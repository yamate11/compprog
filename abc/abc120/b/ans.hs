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

solve :: Int -> Int -> Int -> Int
solve a b k = lst !! (k-1)
  where
    g = gcd a b
    lst = [x | x <- [g,g-1..1], g `mod` x == 0]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_a,bs_b,bs_k]:remLines1 = remLines0
      a = readBInt bs_a
      b = readBInt bs_b
      k = readBInt bs_k
  in solve a b k

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "8 12 2\n"
inp2 = "100 50 4\n"
inp3 = "1 1 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 5
test3 = tv3 == 1
alltest = test1 && test2 && test3

