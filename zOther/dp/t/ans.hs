{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> String -> Int
solve bN s = VU.foldl' mAdd 0 vecF
  where
  vecF = foldl' op (VU.fromListN 1 [1]) s
  op vec '<' = VU.scanl' mAdd 0 vec
  op vec '>' = VU.scanr' mAdd 0 vec

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
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      [bs_s]:remLines2 = remLines1
      s = B.unpack bs_s
  in solve bN s

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n<><\n"
inp2 = "5\n<<<<\n"
inp3 = "20\n>>>><>>><>><>>><<>>\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 5
test2 = tv2 == 1
test3 = tv3 == 217136290
alltest = test1 && test2 && test3

