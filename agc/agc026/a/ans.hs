{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = sum (map (`div` 2) nums)
  where
  nums = unfoldr f as
    where f [] = Nothing
          f (x:xs) = Just (1 + length ss, ds)
            where (ss, ds) = span (== x) xs

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "5\n1 1 2 2 2\n"
inp2 = "3\n1 2 1\n"
inp3 = "5\n1 1 1 1 1\n"
inp4 = "14\n1 2 2 3 3 3 4 4 4 4 1 2 3 4\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 2
test2 = tv2 == 0
test3 = tv3 == 2
test4 = tv4 == 4
alltest = test1 && test2 && test3 && test4
