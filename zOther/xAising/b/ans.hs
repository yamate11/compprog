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

solve :: Int -> Int -> Int -> [Int] -> Int
solve n a b ps = minimum [s1, s2, s3]
  where
    s1 = length [ p | p <- ps, p <= a ]
    s2 = length [ p | p <- ps, a+1 <= p, p <= b ]
    s3 = length [ p | p <- ps, b+1 <= p ]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      [bs_a,bs_b]:remLines2 = remLines1
      a = readBInt bs_a
      b = readBInt bs_b
      line3:remLines3 = remLines2
      ps = map readBInt line3
  in solve n a b ps

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "7\n5 15\n1 10 16 2 7 20 12\n"
inp2 = "8\n3 8\n5 5 5 10 10 10 15 20\n"
inp3 = "3\n5 6\n5 6 10\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 0
test3 = tv3 == 1
alltest = test1 && test2 && test3
