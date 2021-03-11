{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

data Edge = Init | One | Two

solve :: Int -> String -> String -> Int
solve bN sA sB = calc 1 Init (zip sA sB)
  where
  calc !acc edge [] = acc
  calc !acc edge ((s,t):ps) = calc (mMul acc (coe edge newEdge)) newEdge newPs
    where
      (newEdge, newPs) | s == t    = (One, ps)
                       | otherwise = (Two, tail ps)
      coe Init One = 3
      coe Init Two = 6
      coe One One = 2
      coe One Two = 2
      coe Two One = 1
      coe Two Two = 3

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
      [bs_sA]:remLines2 = remLines1
      sA = B.unpack bs_sA
      [bs_sB]:remLines3 = remLines2
      sB = B.unpack bs_sB
  in solve bN sA sB

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\naab\nccb\n"
inp2 = "1\nZ\nZ\n"
inp3 = "52\nRvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn\nRLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 6
test2 = tv2 == 3
test3 = tv3 == 958681902
alltest = test1 && test2 && test3

