{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Data.Bifunctor
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> [Int]
solve n as | even n    = reverse os ++ es
           | otherwise = reverse es ++ os
  where
    (es, os) = part as

part (a:b:xs) = (a:es1, b:os1)
  where (es1, os1) = part xs
part es2 = (es2, [])

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: [Int] -> IO ()
outAnswer ns = putStrLn $ unwords $ map show ns

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n1 2 3 4\n"
inp2 = "3\n1 2 3\n"
inp3 = "1\n1000000000\n"
inp4 = "6\n0 6 7 6 7 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == [4, 2, 1, 3]
test2 = tv2 == [3, 1, 2]
test3 = tv3 == [1000000000]
test4 = tv4 == [0, 6, 6, 0, 7, 7]
alltest = test1 && test2 && test3 && test4

