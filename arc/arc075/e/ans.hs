{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
{-# LANGUAGE MultiWayIf #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> Int
solve bN bK as = runST action
  where
  vA = VU.fromListN bN (map (+ (-bK)) as)
  vASum = VU.postscanl' (+) 0 vA
  (vOrd, vRev) = vecSortIdx vASum

  action = sgtCreate bN (0,0,0) >>= act
  act sgt = do
    sInit
    fst <$> foldM op (0, 0) [0..bN-1]
    where
    op (!acc, border) i = do
      -- sgtTrace sgt
      cnt <- sAsk border
      sReset (vRev VU.! i)
      return (acc + cnt, border + (vA VU.! i))
  
    sInit = sgtAct () sgt mfInit 0 bN
    sAsk q = sgtAct q sgt mfAsk 0 bN
    sReset j = sgtAct () sgt mfReset j (j+1)
  
  mfInit _ _ rcL rcR sgt node l r
    | l+1 == r = do
        let x = vASum VU.! (vOrd VU.! l)
            trip = (x,x,1::Int)
        sgtWrite sgt node trip
        return trip
    | otherwise = do
        (xL,yL,cL) <- rcL ()
        (xR,yR,cR) <- rcR ()
        let trip = (xL, yR, cL+cR)
        sgtWrite sgt node trip
        return trip

  mfAsk q _ rcL rcR sgt node _ _ = do
    (x,y,c) <- sgtRead sgt node
    if | q <= x    -> return c
       | y < q     -> return 0
       | otherwise -> (+) <$> rcL q <*> rcR q

  mymodify sgt node c = sgtModify sgt (modify33 c) node >> return c

  mfReset _ SgtIn _ _ sgt node _ _ = mymodify sgt node 0
  mfReset _ SgtOut _ _ sgt node _ _ = read33 <$> sgtRead sgt node
  mfReset _ SgtOther rcL rcR sgt node _ _ = 
    (+) <$> rcL () <*> rcR () >>= mymodify sgt node

read33 = \(_,_,c) -> c
modify33 c = \(a,b,_) -> (a,b,c)

{-
  (idx, ridx) = vecSortIdx vx
  sorted = VU.fromList [vx VU.! (idx VU.! i) | i <- [0..n-1] ] -- sorted vector
  vu VU.! i == sorted VU.! (ridx VU.! i)
-}
sortIdx xs = bodySortIdx (zip xs [0..])
vecSortIdx vx = let n = VU.length vx 
                in bodySortIdx [(vx VU.! i, i) | i <- [0..n-1]]

bodySortIdx xis = runST $ do
  let idx = VU.fromList $ map snd $ mysort xis
      n = VU.length idx
  vec <- VUM.new n
  mapM_ (\i -> VUM.write vec (idx VU.! i) i) [0..n-1]
  revIdx <- VU.unsafeFreeze vec
  return (idx, revIdx)

-------------------------------------------------------------------------------

mysort :: (Ord a, VU.Unbox a, Show a) => [a] -> [a]
mysort as = VU.toList $ runST $ do
  v <- VU.unsafeThaw (VU.fromList as)
  mymsort v
  VU.unsafeFreeze v

mysortOn :: (Ord a, Ord b, VU.Unbox a, VU.Unbox b,
             Show a, Show b) =>
            (a -> b) -> [a] -> [a]
mysortOn f as = VU.toList $ runST $ do
  v <- VU.unsafeThaw $ VU.fromList $ map (\a -> (f a, a)) as
  mymsort v
  (VU.map snd) <$> (VU.unsafeFreeze v)

mymsort :: (PrimMonad m, Ord a, VUM.Unbox a, Show a) =>
           VUM.MVector (PrimState m) a -> m ()
mymsort v = sortBody (pmgenNext pmSeed) v 0 ((VUM.length v) - 1) 
  where

  sortBody g v lo hi | hi - lo <= 6 = isort v lo hi
                     | otherwise    = do
                         let (x, newG) = pmRandom (lo,hi) g
                         pivot <- VUM.read v x
                         (pL, pR) <- partition v lo hi x pivot
                         sortBody newG v lo (pL-1)
                         sortBody newG v (pR+1) hi

  isort v lo hi = do
    forM_ [lo+1..hi] $ \i -> do
      x <- VUM.read v i
      j <- position lo i x
      VUM.move (VUM.slice (j+1) (i-j) v) (VUM.slice j (i-j) v)
      VUM.write v j x
    where
      position k i x
        | k == i = return i
        | otherwise = do
            y <- VUM.read v k
            if x < y then return k
                     else position (k+1) i x

  -- Compares and moves elems of v against pivot in range [lo,hi]
  -- Precondition: v[x] == pivot
  -- Returns (pL, pR): for pL <= j <= pR, v[j] == pivot
  partition v lo hi x pivot = do
    VUM.swap v lo x
    (loW, hiW) <- partBody (lo+1) hi lo hi
    mapM_ (\i -> VUM.write v i pivot) [loW .. hiW]
    return (loW, hiW)
    where

    partBody loR hiR loW hiW
      | hiR < loR  = return (loW, hiW)
      | loR == loW = sub loR (loR+1) hiR
      | otherwise  = sub hiR loR (hiR-1)
      where
      sub rd newLoR newHiR = do
        t <- VUM.read v rd
        (newLoW, newHiW) <- aWrite loW hiW t
        partBody newLoR newHiR newLoW newHiW

    aWrite loW hiW t
      | t < pivot = VUM.write v loW t >> return (loW+1, hiW)
      | t > pivot = VUM.write v hiW t >> return (loW,   hiW-1)
      | otherwise =                      return (loW,   hiW)

-- As a random number generator, the following is used.
pmSeed :: Int
pmSeed = 429496729 -- can be any number

pmcoA = 48271 :: Int
pmcoM = (2^31 - 1) :: Int

pmgenNext :: Int -> Int
pmgenNext x = (pmcoA * x) `mod` pmcoM

pmRandom :: (Int,Int) -> Int -> (Int,Int)
pmRandom (lo, hi) g = (lo + ((g * (hi+1 - lo)) `div` pmcoM), pmgenNext g)



-------------------------------------------------------------------------------

data SegTree s a = SegTree {
  sgtVec :: VUM.MVector s a,
  sgtSize :: Int
}
data SgtFT = SgtIn | SgtOut | SgtOther deriving(Show)
type SgtMF   s a b c =
  c ->             -- parameter
  SgtFT ->         -- type (In/Out/Other)
  (c -> ST s b) -> -- left recursive function
  (c -> ST s b) -> -- right recursive function
  SegTree s a ->   -- segment tree
  Int ->           -- node
  Int ->           -- left bound for the node (incl)
  Int ->           -- right bound for the node (excl)
  ST s b

sgtRead :: (VUM.Unbox a) => SegTree s a -> Int -> ST s a
{-# INLINE sgtRead #-}
sgtRead sgt node = VUM.read (sgtVec sgt) node

sgtWrite :: (VUM.Unbox a) => SegTree s a -> Int -> a -> ST s ()
{-# INLINE sgtWrite #-}
sgtWrite sgt node a = VUM.write (sgtVec sgt) node a

sgtModify :: (VUM.Unbox a) => SegTree s a -> (a -> a) -> Int -> ST s ()
{-# INLINE sgtModify #-}
sgtModify sgt f node = VUM.modify (sgtVec sgt) f node

sgtCreate :: (VUM.Unbox a) => Int -> a -> ST s (SegTree s a)
{-# INLINE sgtCreate #-}
sgtCreate n a = do
  vec <- VUM.replicate (4*n) a
  return $ SegTree { sgtVec = vec, sgtSize = n }

sgtAct :: (VUM.Unbox a) =>
          c ->             -- parameter
          SegTree s a ->   -- segment tree
          SgtMF s a b c -> -- action body
          Int ->           -- left
          Int ->           -- right
          ST s b
{-# INLINE sgtAct #-}
sgtAct c0 sgt mf left right = sub c0 0 0 (sgtSize sgt)
  where
  sub c node l r = mf c ft rcL rcR sgt node l r
    where
      ft | left <= l && r <= right = SgtIn
         | r <= left || right <= l = SgtOut
         | otherwise               = SgtOther
      mid = (l+r) `div` 2
      rcL c' = sub c' (2*node + 1) l mid
      rcR c' = sub c' (2*node + 2) mid r

sgtTrace :: (VUM.Unbox a, Show a) => SegTree s a -> ST s ()
sgtTrace sgt = 
  let size = sgtSize sgt
      sub vec node l r = do
        VUM.modify vec (\(_,_,_,a) -> (True,l,r,a)) node
        unless (l+1 == r) $ do
          let mid = (l + r) `div` 2
          sub vec (2*node+1) l mid
          sub vec (2*node+2) mid r
  in do
    vec <- VUM.new (4*size)
    forM_ [0..4*size-1] $ \node -> do
      a <- sgtRead sgt node
      VUM.write vec node (False,0,0,a)
    sub vec 0 0 size
    forM_ [0..4*size-1] $ \node -> do
      (eff,l,r,a) <- VUM.read vec node
      when eff $ 
        trace ("  " ++ show node ++ " [" ++ show l ++ ", " ++ show r ++ ")  "
               ++ show a) (return ())

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


-------------------------------------------------------------------------------

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bK]:remLines1 = remLines0
      bN = readBInt bs_bN
      bK = readBInt bs_bK
      as = map (\[x] -> readBInt x) remLines1
  in solve bN bK as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3 6\n7\n5\n7\n"
inp2 = "1 2\n1\n"
inp3 = "7 26\n10\n20\n30\n40\n30\n20\n10\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 5
test2 = tv2 == 0
test3 = tv3 == 13
alltest = test1 && test2 && test3

