{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
{-# LANGUAGE GADTs #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntSet as IS
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Primitive
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int,Int)] -> Int
solve bN bM lras = runST theAction
  where
  vIntv = VU.fromListN bM (map (\(l,r,a) -> (l,r+1,a)) lras)
  intvL = mysortOn' ((\(l,_,_) -> l) . (vIntv VU.!)) [0..bM-1]
  intvR = mysortOn' ((\(_,r,_) -> r) . (vIntv VU.!)) [0..bM-1]
  intvFrL lj = vIntv VU.! (intvL VU.! lj)
  intvFrR rj = vIntv VU.! (intvR VU.! rj)
  
  theAction :: forall s. ST s Int
  theAction = do
    vec <- VUM.replicate (4*(bN+1)) (0,0)
    actSolve vec
    where
    actSolve :: VU.MVector s (Int,Int) -> ST s Int
    actSolve vec = act where
  
      act = mLoop 0 0 1 0 0

{-
      mfAdd :: Int -> 
               SgtFT -> ST s (Int,Int) ->
               VUM.MVector s (Int,Int) -> Int -> Int -> Int -> ST s Int
-}
      {-# INLINE mfAdd #-}
      mfAdd a ft rc vec node l r = sub ft >> sgNodeInfo vec node where
        sub SgtIn = VUM.modify vec (\(vSum,m)->(vSum+a,m)) node
        sub SgtOut = return ()
        sub SgtOther = let f m = VUM.modify vec (\(s,_)->(s,m)) node
                       in uncurry max <$> rc >>= f
--      sAdd :: Int -> Int -> Int -> ST s Int
      {-# INLINE sAdd #-}
      sAdd a = sgtAct (mfAdd a) vec (bN+1) 
          
{-
      mfMax :: SgtFT -> ST s (Int,Int) ->
               VUM.MVector s (Int,Int) -> Int -> Int -> Int -> ST s Int
-}
      {-# INLINE mfMax #-}
      mfMax SgtIn rc vec node l r = sgNodeInfo vec node
      mfMax SgtOut rc vec node l r = return minBound
      mfMax SgtOther rc vec node l r = uncurry max <$> rc

--      sMax :: Int -> Int -> ST s Int
      {-# INLINE sMax #-}
      sMax = sgtAct mfMax vec (bN+1) -- 0 (bN+1)

      sgNodeInfo :: VUM.MVector s (Int,Int) -> Int -> ST s Int
{-
      sgNodeInfo :: (PrimMonad m) =>
                    VUM.MVector (PrimState m) (Int,Int) -> Int -> m Int
-}
      {-# INLINE sgNodeInfo #-}
      sgNodeInfo vec node = do
        (s,m) <- VUM.read vec node
        return $ s + m

--      mLoop :: Int -> Int -> Int -> Int -> Int -> ST s Int
      {-# INLINE mLoop #-}
      mLoop !ans !cur !i !lj !rj 
        | i == bN+1 = return ans
        | otherwise = do
            let (newLj, midCur) = mlLeft (lj, cur)
            (newRj, newCur) <- mlRight (rj, midCur)
            score <- (+ newCur) <$> sMax 0 i
            sAdd (score - newCur) i (i+1)
            mLoop (max ans score) newCur (i+1) newLj newRj
        where
          mlLeft (lj, cur) | lj == bM || l /= i = (lj, cur)
                           | otherwise          = mlLeft (lj+1, cur+a)
            where (l,r,a) = intvFrL lj
          mlRight (rj, cur) | rj == bM || r /= i = return (rj, cur)
                            | otherwise = do
                                sAdd a l r
                                mlRight (rj+1, cur-a)
            where (l,r,a) = intvFrR rj

{-
traceNodes = do
  forM_ [0..bN*4-1] $ \node -> do
    (s,m) <- VUM.read vec node
    traceL "node" (node, (s,m)) (return ())
-}


-- segment tree function type
data SgtFT = SgtIn | SgtOut | SgtOther deriving(Show)

sgtAct :: forall s a b. (VUM.Unbox a) =>
          (SgtFT -> ST s (b,b) ->
             VUM.MVector s a -> Int -> Int -> Int -> ST s b) ->
          VUM.MVector s a ->
          Int ->
          Int ->
          Int ->
          ST s b
{-# INLINE sgtAct #-}
sgtAct mf vec n left right = sub 0 0 n where
  sub :: Int -> Int -> Int -> ST s b
  sub node l r =
    mf (sgtft left right l r) (sgtChildAct sub node l r) vec node l r

{-# INLINE sgtChildAct #-}
sgtChildAct rc' node l r =
  let mid = (l + r) `div` 2
  in (,) <$> rc' (2*node + 1) l mid <*> rc' (2*node + 2) mid r

{-# INLINE sgtChildAct_ #-}
sgtChildAct_ rc' node l r = sgtChildAct rc' node l r >> return ()

{-# INLINE sgtft #-}
sgtft left right l r
  | left <= l && r <= right = SgtIn
  | r <= left || right <= l = SgtOut
  | otherwise               = SgtOther

----------------------------------------------------------------------

mysortOn' :: (Ord a, Ord b, VU.Unbox a, VU.Unbox b, Show a, Show b) =>
            (a -> b) -> [a] -> VU.Vector a
mysortOn' f as = runST $ do
  v <- VU.unsafeThaw $ VU.fromList $ map (\a -> (f a, a)) as
  mymsort v
  (VU.map snd) <$> (VU.unsafeFreeze v)

mymsort :: (PrimMonad m, Ord a, VUM.Unbox a, Show a) =>
           VUM.MVector (PrimState m) a -> m ()
mymsort v = do
  let n = VUM.length v
  sub v 0 (n-1)
  where
  sub v lo hi
    | hi - lo <= 6 = myisort v lo hi
    | otherwise = do
        (pL, pR) <- mypartition v lo hi
--        vv <- VU.freeze v
--        sub v lo ((trace (show (vv, pL, pR)) pL)-1)
        sub v lo (pL-1)
        sub v (pR+1) hi

myisort v lo hi = do
  forM_ [lo+1..hi] $ \i -> do
    x <- VUM.read v i
    j <- sub_start lo i x
    VUM.unsafeMove (VUM.unsafeSlice (j+1) (i-j) v) (VUM.unsafeSlice j (i-j) v)
    VUM.write v j x
  where
    sub_start k i x
      | k == i = return i
      | otherwise = do
          y <- VUM.read v k
          if x < y then return k
                   else sub_start (k+1) i x

mypartition :: (PrimMonad m, Ord a, VUM.Unbox a, Show a) =>
               VUM.MVector (PrimState m) a -> Int -> Int -> m (Int, Int)
mypartition v lo hi = do
  let mid = (lo + hi) `div` 2
  xLo <- VUM.read v lo
  xMid <- VUM.read v mid
  xHi <- VUM.read v hi
  when (xMid < xLo) (VUM.swap v lo mid)
  when (xHi < xLo) (VUM.swap v lo hi)
  when (xMid < xHi) (VUM.swap v mid hi)
  pivot <- VUM.read v hi
--  (i0, j0) <- sub (trace ("pivot = " ++ show pivot) pivot) lo lo hi
  (i0, j0) <- sub pivot lo lo hi
  let w = min (j0-i0) (hi-j0+1)
  forM_ [0..w-1] $ \i -> VUM.swap v (i0+i) (hi-i)
  return (i0, i0+hi-j0+1-1)
  where
    sub pivot i0 j0 k0
      | j0 == k0  = return (i0, j0)
      | otherwise = VUM.read v j0 >>= sub2
      where sub2 x | x > pivot  = sub pivot i0 (j0+1) k0
                   | x == pivot = do
                                  VUM.swap v j0 (k0-1)
                                  sub pivot i0 j0 (k0-1)
                   | otherwise  = do
                                  VUM.swap v i0 j0
                                  sub pivot (i0+1) (j0+1) k0

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      lras = map (\[x1,x2,x3] -> (readBInt x1,readBInt x2,readBInt x3)) remLines1
  in solve bN bM lras

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "5 3\n1 3 10\n2 4 -10\n3 5 10\n"
inp2 = "3 4\n1 3 100\n1 1 -10\n2 2 -20\n3 3 -30\n"
inp3 = "1 1\n1 1 -10\n"
inp4 = "1 5\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n"
inp5 = "6 8\n5 5 3\n1 1 10\n1 6 -8\n3 6 5\n3 4 9\n5 5 -2\n1 3 -6\n4 6 -7\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 20
test2 = tv2 == 90
test3 = tv3 == 0
test4 = tv4 == 5000000000
test5 = tv5 == 10
alltest = test1 && test2 && test3 && test4 && test5

