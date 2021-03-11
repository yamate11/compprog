{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List hiding(partition)
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.ST
import Debug.Trace

solve :: Int -> [Int] -> [Int] -> Int
solve n as bs = toDec $ map calcBit [0..28] where

  calcBit :: Int -> Int
  calcBit k = answer where

    bigT = shift 1 k
    mask = 2 * bigT - 1
    asM = map (mask .&.) as
    bsM = map (mask .&.) bs

    answer = (sum (map calcBitA asM)) `mod` 2

    bsft = VU.fromList $ mysort $ bsM
  
    calcBitA a = ((idxT0 - idxS0) + (n - idxS1)) `mod` 2
      where
      idxS0 = getIdx (bigT     - a)
      idxT0 = getIdx ((2*bigT) - a)
      idxS1 = getIdx ((3*bigT) - a)
      
      getIdx :: Int -> Int
      getIdx x | bsft VU.! (n-1) < x = n
               | x <= bsft VU.! 0    = 0
               | otherwise           = binsch 0 (n-1)
        where
          binsch lo hi | hi == lo + 1       = hi
                       | x <= bsft VU.! mid = binsch lo mid
                       | otherwise          = binsch mid hi
            where mid = (hi + lo) `div` 2

toDec :: [Int] -> Int
toDec [] = 0
toDec (b:bs) = b + 2 * toDec bs

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
      line3:remLines3 = remLines2
      bs = map readBInt line3
  in solve n as bs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

mysort :: (Ord a, VU.Unbox a, Show a) => [a] -> [a]
mysort as = VU.toList $ runST $ do
  v <- VU.unsafeThaw (VU.fromList as)
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

----------------------------------------------------------------------


inp1 = "2\n1 2\n3 4\n"
inp2 = "6\n4 6 0 0 3 3\n0 5 6 5 0 3\n"
inp3 = "5\n1 2 3 4 5\n1 2 3 4 5\n"
inp4 = "1\n0\n0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 2
test2 = tv2 == 8
test3 = tv3 == 2
test4 = tv4 == 0
alltest = test1 && test2 && test3 && test4
