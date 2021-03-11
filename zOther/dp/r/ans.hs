{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [[Int]] -> Int
solve bN bK ass = VU.foldl' mAdd 0 theMat
  where
  matE = VU.fromListN (bN*bN) (concat ass)
  mmm = matMul mAdd mMul bN bN bN
  power = iterate (\x -> mmm x x) matE
  seq = [testBit bK i | i <- [0..63]]
  theMat = foldl' mmm (matI bN) [p | (s, p) <- zip seq power, s]

-------------------------------------------------------------------------------

matI n =
  VU.fromListN (n*n)
  [if i == j then 1 else 0 | i <- [0..n-1], j <- [0..n-1]]

matMul opA opM n m p mat1 mat2 =
  VU.fromListN (n*p)
  [foldl' opA 0 [(mat1 VU.! (i*m+k)) `opM` (mat2 VU.! (k*p+j))
                | k <- [0..m-1]]
  | i <- [0..n-1], j <- [0..p-1]]

-------------------------------------------------------------------------------

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime
-- mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime
-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_k]:remLines1 = remLines0
      n = readBInt bs_n
      k = readBInt bs_k
      ass = map (map readBInt) remLines1
  in solve n k ass

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4 2\n0 1 0 0\n0 0 1 1\n0 0 0 1\n1 0 0 0\n"
inp2 = "3 3\n0 1 0\n1 0 1\n0 0 0\n"
inp3 = "6 2\n0 0 0 0 0 0\n0 0 1 0 0 0\n0 0 0 0 0 0\n0 0 0 0 1 0\n0 0 0 0 0 1\n0 0 0 0 0 0\n"
inp4 = "1 1\n0\n"
inp5 = "10 1000000000000000000\n0 0 1 1 0 0 0 1 1 0\n0 0 0 0 0 1 1 1 0 0\n0 1 0 0 0 1 0 1 0 1\n1 1 1 0 1 1 0 1 1 0\n0 1 1 1 0 1 0 1 1 1\n0 0 0 1 0 0 1 0 1 0\n0 0 0 1 1 0 0 1 0 1\n1 0 0 0 1 0 1 0 0 0\n0 0 0 0 0 1 0 0 0 0\n1 0 1 1 1 0 1 1 1 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 6
test2 = tv2 == 3
test3 = tv3 == 1
test4 = tv4 == 0
test5 = tv5 == 957538352
alltest = test1 && test2 && test3 && test4 && test5

