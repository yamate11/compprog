-------------------------------------------------------------------------------
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = binsch (try as) n 0

binsch f succ fail | abs (succ - fail) == 1 = succ
                   | f mid                  = binsch f mid fail
                   | otherwise              = binsch f succ mid
  where mid = (succ + fail) `div` 2

step :: Int -> (Int,[(Int,Int)]) -> Int -> Maybe (Int,[(Int,Int)])
step k (s,x) a | a > s     = Just (a,x)
               | k == 1    = Nothing
               | otherwise = (a, ) <$> inc a (cut a x)
  where
    cut a x = dropWhile ((> a) . fst) x
    inc a [] = Just [(a,1)]
    inc a x1@((b,p):x2) | a > b = Just ((a,1) : x1)
                        | p+1 < k = Just ((a,p+1) : x2)
                        | a-1 > 0 = inc (a-1) x2
                        | otherwise = Nothing

try as k = isJust $ try0 as k

try0 as k = foldM (step k) (0, []) as

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

----------------------------------------------------------------------

inp1 = "3\n3 2 1\n"
inp2 = "5\n2 3 2 1 2\n"
inp3 = "5\n2 2 2 2 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 2
test3 = tv3 == 3
alltest = test1 && test2 && test3
