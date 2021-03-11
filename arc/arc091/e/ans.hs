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
trace _ a = a

solve :: Int -> Int -> Int -> Maybe [Int]
solve n a b | a + b - 1 <= n && n <= a * b = Just (solve0 n a b)
            | otherwise = Nothing

solve0 n a 1 = [1..n]
solve0 n 1 b = [n,n-1..1]
solve0 n a b = answer
  where
    (p,q) = divMod (n-b) (a-1)
    nums = [b] ++ replicate q (p+1) ++ replicate (a-1-q) p
    sums = scanl' (+) 0 nums
    tbl = trace ("tbl " ++ show tbl0) tbl0
    tbl0 = zipWith f (map (+ 1) sums) (tail sums)
      where f x y = [y, y-1 .. x]
    answer = concat tbl

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_a,bs_b]:remLines1 = remLines0
      n = readBInt bs_n
      a = readBInt bs_a
      b = readBInt bs_b
  in solve n a b

outAnswer :: Maybe [Int] -> IO ()
outAnswer Nothing = putStrLn "-1"
outAnswer (Just xs) = putStrLn $ unwords $ map show xs

main :: IO ()
main = outAnswer . tmain =<< B.getContents

