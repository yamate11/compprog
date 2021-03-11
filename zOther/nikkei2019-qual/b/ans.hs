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

solve :: Int -> String -> String -> String -> Int
solve n a b c = sum (zipWith3 f a b c)
  where
    f x y z | x == y && y == z = 0
            | x == y || y == z || x == z = 1
            | otherwise = 2

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      [bs_a]:remLines2 = remLines1
      a = B.unpack bs_a
      [bs_b]:remLines3 = remLines2
      b = B.unpack bs_b
      [bs_c]:remLines4 = remLines3
      c = B.unpack bs_c
  in solve n a b c

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\nwest\neast\nwait\n"
inp2 = "9\ndifferent\ndifferent\ndifferent\n"
inp3 = "7\nzenkoku\ntouitsu\nprogram\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 0
test3 = tv3 == 13
alltest = test1 && test2 && test3

