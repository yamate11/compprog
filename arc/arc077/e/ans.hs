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
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> Int
solve n m as = runST action
  where
  action = sgtCreate (m+1) (0,0) >>= act

  act sgt = do
    forM_ (zip as (tail as)) $ \(x,y) -> oper x y
    -- sgtTrace sgt
    sgtMin (0,0) 1 (m+1)
    where

    oper x y
      | x + 1 == y || (x,y) == (m,1) =
          sgtAdd' (0,  1)    1     (m+1) 
      | x < y = do
          sgtAdd' (0,  d)    1     (x+2) 
          sgtAdd' (-1, y+1)  (x+2) (y+1) 
          sgtAdd' (0,  d)    (y+1) (m+1) 
      | y < x = do
          sgtAdd' (-1, y+1)   1     (y+1) 
          sgtAdd' (0,  d+m)   (y+1) (x+2) 
          sgtAdd' (-1, y+1+m) (x+2) (m+1) 
      where d = y - x
  
    sgtAdd pq = sgtAct pq sgt mfAdd
    sgtAdd' pq x y | x < y0    = sgtAdd pq x y0
                   | otherwise = return ()
      where y0 = min y (m+1)

    sgtMin pq = sgtAct pq sgt mfMin
  
mfAdd (p,q) SgtIn _ _ sgt node _ _ = sgtModify sgt f node >> return ()
  where f (p0,q0) = (p0+p, q0+q)
mfAdd pq SgtOut _ _ _ _ _ _ = return ()
mfAdd pq SgtOther rcL rcR _ _ _ _ = rcL pq >> rcR pq >> return ()
  
mfMin _ SgtOut _ _ _ _ _ _ = return maxBound
mfMin (p,q) _ rcL rcR sgt node l r = do
  (p', q') <- sgtRead sgt node
  let (p0, q0) = (p + p', q + q')
  if l+1 == r
    then do
    -- traceL "bottom" (l,q0,p0) (return ())
    return (p0 * l + q0)
    else min <$> rcL (p0,q0) <*> rcR (p0,q0)

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
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n m as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4 6\n1 5 1 4\n"
inp2 = "10 10\n10 9 8 7 6 5 4 3 2 1\n"
inp3 = "2 6\n1 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 5
test2 = tv2 == 45
test3 = tv3 == 1
alltest = test1 && test2 && test3

