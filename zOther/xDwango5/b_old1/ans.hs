{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Data.Bits
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> Int
solve n k as = value 0 seq 
  where

    size = n * (n+1) `div` 2
    acc = VU.fromList $ scanl' (+) 0 as
    subsum = [(acc VU.! i) - (acc VU.! j) | j <- [0..n], i <- [j+1..n]]

    seq = unfoldr f (subsum, 47)
      where
        f (_, -1) = Nothing
        f (lst, p) | length ok >= k = Just (1, (ok, p-1))
                   | otherwise      = Just (0, (lst, p-1))
          where
            ok = filter (\x -> testBit x p) lst
      
    value acc [] = acc
    value acc (b:bs) = value (2*acc + b) bs

int2bits :: Int -> [Int]
int2bits x = take 48 $ unfoldr f x
  where
    f y = Just (q, p)
      where (p,q) = divMod y 2


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_k]:remLines1 = remLines0
      n = readBInt bs_n
      k = readBInt bs_k
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n k as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

tv1 = solve 4 2 [2,5,2,5]
test1 = tv1 == 12
tv2 = solve 8 4 [9,1,8,2,7,5,6,4]
test2 = tv2 == 32
alltest = test1 && test2
