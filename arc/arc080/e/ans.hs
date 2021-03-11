{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.STRef
-- import Debug.Trace
trace _ = id

solve :: Int -> [Int] -> [Int]
solve bN ps = VU.toList $ VU.create $ do
  stEven <- sgtCreate bN2 maxBound
  stOdd  <- sgtCreate bN2 maxBound
  pque <- pqueInit bN (\(v,_,_,_) (v',_,_,_) -> v < v')
  results <- VUM.new bN
  action stEven stOdd pque results
  where
  vP = VU.fromListN bN ps
  vEven = VU.ifilter (\i _ -> even i) vP
  vOdd  = VU.ifilter (\i _ -> odd  i) vP
  bN2 = bN `div` 2

--  mfPut :: Int -> SgtFT -> ST s ((Int,Int),(Int,Int)) -> SegTree s (Int,Int) -> Int -> Int -> Int -> ST s (Int,Int)
  mfPut x ft rc sgt node l r =
    let wt y = do
          -- traceL "wt" (node,y) (return ())
          sgtWrite sgt node y
          return y
    in case ft of
      SgtIn    -> wt (x,l)
      SgtOut   -> sgtRead sgt node
      SgtOther -> ((uncurry min) <$> rc) >>= wt

  mfMin SgtIn rc sgt node l r = sgtRead sgt node
  mfMin SgtOut rc sgt node l r = return (maxBound,maxBound)
  mfMin SgtOther rc sgt node l r = (uncurry min) <$> rc

  sPut sgt i x = sgtAct sgt (mfPut x) i (i+1) >> return ()
--   sMin :: SegTree s (Int,Int) -> Int -> Int -> ST s (Int,Int)
  sMin sgt l r = sgtAct sgt mfMin l r

  action stEven stOdd pque results = act
    where

    act = do
      forM_ [0..bN2-1] $ \i -> do
        -- traceL "evenPut" (i,vEven VU.! i) (return ())
        sPut stEven i (vEven VU.! i)
        -- traceL "oddPut " (i,vOdd VU.! i) (return ())
        sPut stOdd  i (vOdd  VU.! i)
      (tmin,ma) <- sMin stEven 0 bN2
      -- traceL "tmin" tmin (return ())
      pquePut pque (tmin,2*ma,0,bN)
      forM_ [0..bN2-1] $ \k -> do
        (v, i1, i0, i3) <- pqueGet pque
        (w, i2) <- myMin (i1+1) i3
        toPQue i0 i1
        toPQue (i1+1) i2
        toPQue (i2+1) i3
        -- traceL "results" (k,v,w) (return ())
        VUM.write results (2*k) v
        VUM.write results (2*k+1) w
      return results    

    -- myMin :: Int -> Int -> ST s (Int, Int)
    myMin i j = do
      let (st, off) = if even i then (stEven, 0) else (stOdd, 1)
      (w, p) <- sMin st (i `div` 2) ((j+1) `div` 2)
      return (w, 2*p + off)

    -- toPQue :: Int -> Int -> ST s ()
    toPQue i j | i == j = return ()
    toPQue i j = do
      let l = i `div` 2
          r = j `div` 2
          (st, off) = if even i then (stEven, 0) else (stOdd, 1)
      (v, p) <- sMin st l r
      pquePut pque (v, 2*p + off, i, j)

-------------------------------------------------------------------------------

actionWithValue :: ST s a -> (a -> ST s b) -> ST s a
{-# INLINE actionWithValue #-}
actionWithValue act1 act2 = do
  a <- act1
  act2 a
  return a

modSTRef :: STRef s a -> (a -> a) -> ST s a
{-# INLINE modSTRef #-}
modSTRef ref f = actionWithValue (readSTRef ref) (writeSTRef ref . f)

data PQueue s a = PQueue {
  pqueHigher :: a -> a -> Bool,
  pqueVec :: VUM.MVector s a,
  pqueSize :: Int,
  pqueBot :: STRef s Int
}

pqueInit :: (VUM.Unbox a) => Int -> (a -> a -> Bool) -> ST s (PQueue s a)
{-# INLINE pqueInit #-}
pqueInit n higher = do
  vec <- VUM.new n
  b <- newSTRef 0
  return $ PQueue { pqueHigher = higher, pqueVec = vec,
                    pqueSize = n, pqueBot = b }

pquePut :: (VUM.Unbox a, Show a) => PQueue s a -> a -> ST s ()
{-# INLINE pquePut #-}
pquePut q a = do
  -- traceL "pquePut" a (return ())
  n <- modSTRef (pqueBot q) (+ 1)
  m <- goUp n a
  VUM.write (pqueVec q) m a
  where goUp 0 _ = return 0
        goUp n a = do
          let n' = (n - 1) `div` 2
          a' <- VUM.read (pqueVec q) n'
          if not (pqueHigher q a a') then return n else do
            VUM.write (pqueVec q) n a'
            goUp n' a

pqueGet :: (VUM.Unbox a, Show a) => PQueue s a -> ST s a
{-# INLINE pqueGet #-}
pqueGet q = do
  retval <- VUM.read (pqueVec q) 0
  -- traceL "pqueGet" retval (return ())
  n <- modSTRef (pqueBot q) (+ (-1))
  a <- VUM.read (pqueVec q) (n-1)
  goDown n 0 a retval
    where
    goDown n k a retval = do
      (v, go) <- sub k a (2*k+1) (2*k+2)
      VUM.write (pqueVec q) k v
      case go of
        Nothing -> return retval
        Just (k', a') -> goDown n k' a' retval
      where
        sub k a i j | i >= n - 1 = return (a, Nothing)
        sub k a i j = do
          ai <- VUM.read (pqueVec q) i
          sub2 k a i ai j
        sub2 k a i ai j | j >= n - 1 = sub3 k a i ai
        sub2 k a i ai j = do
          aj <- VUM.read (pqueVec q) j
          if pqueHigher q ai aj then sub3 k a i ai else sub3 k a j aj
        sub3 k a x ax | pqueHigher q a ax = return (a, Nothing)
                      | otherwise         = return (ax, Just (x, a))

-------------------------------------------------------------------------------

data SegTree s a = SegTree {
  sgtVec :: VUM.MVector s a,
  sgtSize :: Int
}
data SgtFT = SgtIn | SgtOut | SgtOther deriving(Show)
type SgtMF   s a b =
  SgtFT ->         -- type (In/Out/Other)
  ST s (b,b) ->    -- results of (left,right)
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
          SegTree s a ->   -- segment tree
          SgtMF s a b ->   -- action body
          Int ->           -- left
          Int ->           -- right
          ST s b
{-# INLINE sgtAct #-}
sgtAct sgt mf left right = sub 0 0 (sgtSize sgt) where
  sub node l r =
    mf (sgtft left right l r) (sgtChildAct sub node l r) sgt node l r

  sgtChildAct sub' node l r =
    let mid = (l + r) `div` 2
    in (,) <$> sub' (2*node + 1) l mid <*> sub' (2*node + 2) mid r

  sgtft left right l r
    | left <= l && r <= right = SgtIn
    | r <= left || right <= l = SgtOut
    | otherwise               = SgtOther


-------------------------------------------------------------------------------

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      ps = map readBInt line2
  in solve bN ps

outAnswer :: [Int] -> IO ()
outAnswer xs = do
  putStrLn (unwords (map show xs))

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n3 2 4 1\n"
inp2 = "2\n1 2\n"
inp3 = "8\n4 6 3 2 8 5 7 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == [3, 1, 2, 4]
test2 = tv2 == [1, 2]
test3 = tv3 == [3, 1, 2, 7, 4, 6, 8, 5]
alltest = test1 && test2 && test3

