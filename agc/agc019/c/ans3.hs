{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
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

solve :: Int -> Int -> Int -> Int -> Int -> [(Int,Int)] -> Double
solve xA yA xB yB bN lstXY =
  (fromIntegral ((xL+yL)*100)) + diffLen
  where
  cvtFX x | xA < xB = x - xA
          | otherwise = xA - x
  cvtFY y | yA < yB = y - yA
          | otherwise = yA - y
  cvtF (x,y) = (cvtFX x, cvtFY y)
  (xL, yL) = cvtF (xB, yB)
  vXY = VU.fromList $ mysort $ filter eff $ map cvtF lstXY
    where eff (x,y) = 0 <= x && x <= xL && 0 <= y && y <= yL
  pt i = vXY VU.! i
  bM = VU.length vXY
  isXUR (x,y) (x',y') = x+1 == x' && y < y'
  isYUR (x,y) (x',y') = x < x' && y+1 == y'
  allUR prop = and [ prop (pt (i-1)) (pt i) | i <- [1..bM-1] ]
  isSpecCase1 = snd (pt 0) == 0 && snd (pt (bM-1)) == yL && allUR isYUR
  isSpecCase2 = fst (pt 0) == 0 && fst (pt (bM-1)) == xL && allUR isXUR
  diffLen
    | bM == 0 = 0
    | isSpecCase1 || isSpecCase2
      = (5*pi-20) * (fromIntegral (bM-1)) + (10*pi-20)
    | otherwise = (5*pi-20) * (fromIntegral dpHt)

  dpHt = runST $ VUM.new (bM+1) >>= dpSub
  dpSub vec = act1 0 0 where
    act1 !ht !j | j == bM = return ht
    act1 !ht !j = do
      let (_,y) = pt j
      (idx, newHt) <- sch ht y
      VUM.write vec idx y
      act1 newHt (j+1)

    sch ht y = do
      let prop j = (y <) <$> VUM.read vec j
      midx <- lower_boundM prop 1 ht
      case midx of
        Nothing -> return (ht+1, ht+1)
        Just idx -> return (idx, ht)

-------------------------------------------------------------------------------

-- Finds the least i such that (lo <= i <= hi && prop i) holds
-- Precondition: prop j && j <= k ==> prop k
lower_bound :: (Int -> Bool) -> Int -> Int -> Maybe Int
lower_bound prop lo hi
  | hi < lo || not (prop hi) = Nothing
  | prop lo = Just lo
  | otherwise = sub lo hi
  where sub lo hi | lo + 1 == hi = Just hi
                  | prop mid     = sub lo mid
                  | otherwise    = sub mid hi
          where mid = (lo + hi) `div` 2

-- Finds the greatest i such that (lo <= i <= hi && prop i) holds
-- Precondition: prop j && j >= k ==> prop k
upper_bound :: (Int -> Bool) -> Int -> Int -> Maybe Int
upper_bound prop lo hi
  | hi < lo || not (prop lo) = Nothing
  | prop hi = Just hi
  | otherwise = sub lo hi
  where sub lo hi | lo + 1 == hi = Just lo
                  | prop mid     = sub mid hi
                  | otherwise    = sub lo mid
          where mid = (lo + hi) `div` 2

lower_boundM :: Monad m => (Int -> m Bool) -> Int -> Int -> m (Maybe Int)
lower_boundM prop lo hi | hi < lo = return Nothing
lower_boundM prop lo hi = do
  b <- prop hi
  if not b then return Nothing else do
    b2 <- prop lo
    if b2 then return (Just lo) else sub lo hi
  where
  sub lo hi | lo + 1 == hi = return $ Just hi
            | otherwise = do
                let mid = (lo + hi) `div` 2
                b3 <- prop mid
                if b3 then sub lo mid else sub mid hi

upper_boundM :: Monad m => (Int -> m Bool) -> Int -> Int -> m (Maybe Int)
upper_boundM prop lo hi | hi < lo = return Nothing
upper_boundM prop lo hi = do
  b <- prop lo
  if not b then return Nothing else do
    b2 <- prop hi
    if b2 then return (Just hi) else sub lo hi
  where
  sub lo hi | lo + 1 == hi = return $ Just lo
            | otherwise = do
                let mid = (lo + hi) `div` 2
                b3 <- prop mid
                if b3 then sub mid hi else sub lo mid

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Double
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_xA,bs_yA,bs_xB,bs_yB]:remLines1 = remLines0
      xA = readBInt bs_xA
      yA = readBInt bs_yA
      xB = readBInt bs_xB
      yB = readBInt bs_yB
      [bs_bN]:remLines2 = remLines1
      bN = readBInt bs_bN
      lstXY = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve xA yA xB yB bN lstXY

outAnswer :: Double -> IO ()
outAnswer x = putStrLn $ show x

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

mysort :: (Ord a, VU.Unbox a, Show a) => [a] -> [a]
mysort as = VU.toList $ runST $ do
  v <- VU.unsafeThaw (VU.fromList as)
  mymsort v
  VU.unsafeFreeze v

myVSort :: (Ord a, VU.Unbox a, Show a) => VU.Vector a -> VU.Vector a
myVSort va = runST $ do
  v <- VU.unsafeThaw va
  mymsort v
  VU.unsafeFreeze v

mysortOn :: (Ord a, Ord b, VU.Unbox a, VU.Unbox b, Show a, Show b) =>
            (a -> b) -> [a] -> [a]
mysortOn f as = VU.toList $ runST $ do
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



-------------------------------------------------------------------------------

inp1 = "1 1 6 5\n3\n3 2\n5 3\n2 4\n"
inp2 = "3 5 6 4\n3\n3 2\n5 3\n2 4\n"
inp3 = "4 2 2 2\n3\n3 2\n5 3\n2 4\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 891.415926535897938
test2 = tv2 == 400.000000000000000
test3 = tv3 == 211.415926535897938
alltest = test1 && test2 && test3

