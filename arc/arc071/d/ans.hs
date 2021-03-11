{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> [Int] -> Int
solve n m xs ys = weightX `mMul` weightY
  where
    diff ps = zipWith mSub (tail ps) ps
    dxs = diff xs
    dys = diff ys
    weightX = foldl' mAdd 0 $ zipWith mMul dxs [hight n k | k <- [0..n-2]]
    weightY = foldl' mAdd 0 $ zipWith mMul dys [hight m k | k <- [0..m-2]]

hight n k = mMul (n - 1 - k) (k + 1)

----------------------------------------------------------------------

mPrime = 10^9 + 7

-- mAdd x y = (x + y) `mod` mPrime
mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y
mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

----------------------------------------------------------------------

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      line2:remLines2 = remLines1
      xs = map readBInt line2
      line3:remLines3 = remLines2
      ys = map readBInt line3
  in solve n m xs ys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3 3\n1 3 4\n1 3 6\n"
inp2 = "6 5\n-790013317 -192321079 95834122 418379342 586260100 802780784\n-253230108 193944314 363756450 712662868 735867677\n"
inp3 = "4 4\n0 1 2 3\n0 1 2 3\n"
inp4 = "4 3\n0 1 2 3\n0 1 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 60
test2 = tv2 == 835067060
test3 = tv3 == 100
test4 = tv4 == 40
alltest = test1 && test2 && test3 && test4

