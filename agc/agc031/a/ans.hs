{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> String -> Int
solve n s = (VU.foldl' mMul 1 cnts) `mSub` 1
  where
  cnts = VU.create $ do
    vec <- VUM.replicate 26 1
    forM_ s $ \c -> do
      let i = ord c - ord 'a'
      VUM.modify vec (+ 1) i
    return vec

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y
mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime



readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      [bs_s]:remLines2 = remLines1
      s = B.unpack bs_s
  in solve n s

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\nabcd\n"
inp2 = "3\nbaa\n"
inp3 = "5\nabcab\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 15
test2 = tv2 == 5
test3 = tv3 == 17
alltest = test1 && test2 && test3

