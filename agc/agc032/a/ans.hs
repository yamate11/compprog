{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> [Int]
solve n bs = case stage [] n vec of
               Nothing -> [-1]
               Just acc -> acc
  where
  vec = VU.fromListN (n+1) (0:bs)
  

  stage acc 0 v = Just acc
  stage acc k v | null ls = Nothing
                | otherwise = stage (k0:acc) (k-1) vNext
    where
    ls = [i | i <- [1..k], v VU.! i == i]
    k0 = maximum ls
    vNext = (VU.slice 0 k0 v) VU.++ (VU.slice (k0+1) (k-k0) v)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      bs = map readBInt line2
  in solve n bs

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr $ unlines $ map show xs

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n1 2 1\n"
inp2 = "2\n2 2\n"
inp3 = "9\n1 1 1 2 2 1 2 3 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

