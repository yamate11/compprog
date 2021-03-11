{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace

solve :: Int -> Int -> Int
solve n mPrime = powpowTwo n mPrime - lessTwo n mPrime

powpowTwo :: Int -> Int -> Int
powpowTwo n mPrime = answer where
  (r, m0) = divModPow2 (mPrime - 1)
  b | n < r = (2^n) `mod` (mPrime - 1)
    | otherwise = (2^r) * (mPow m0 2 (n-r))
  answer = mPow mPrime 2 b

divModPow2 x = sub 0 x where
  sub !p !m | r == 0 = sub (p+1) q
            | otherwise = (p, m)
    where (q, r) = divMod m 2

lessTwo :: Int -> Int -> Int
lessTwo n mPrime = mMul mPrime 2 (mSum mPrime perNum) where
  perNum = trace ("perNum " ++ show (n, perNumXX)) perNumXX
  perNumXX = head $ drop n $ iterate g [1] where
    g lst = 1 : (zipWith3 f [1..] lst (tail lst)) ++ [1] where
      f i x y = mAdd mPrime x (mMul mPrime i y)
  
mSum :: Int -> [Int] -> Int
mSum m = foldl' (mAdd m) 0

mAdd :: Int -> Int -> Int -> Int
mAdd m x y = (x + y) `mod` m

mSub :: Int -> Int -> Int -> Int
mSub m x y = (x - y) `mod` m    -- ok even if x < y

mMul :: Int -> Int -> Int -> Int
mMul m x y = (x * y) `mod` m

mPow :: Int -> Int -> Int -> Int
mPow m x y = foldl' (mMul m) 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul m t t) x

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
  in solve n m

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "2 1000000007\n"
inp2 = "3 1000000009\n"
inp3 = "50 111111113\n"
inp4 = "3000 123456791\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 2
test2 = tv2 == 118
test3 = tv3 == 1456748
test4 = tv4 == 16369789
alltest = test1 && test2 && test3 && test4
