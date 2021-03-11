{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [[Int]] -> Int
solve n ass = case sum of
                Just x -> x
                Nothing -> -1
  where
  vec = VU.fromListN (n*n) (concat ass)
  enc i j = i * n + j
  dist i j = vec VU.! (enc i j)
  road (i,j) = and <$> mapM f [0..n-1] >>= ite231 (Just d) (Just 0)
    where
      d = dist i j
      f k | k == i || k == j = Just True
          | d < tri = Just True
          | d == tri = Just False
          | otherwise = Nothing
        where tri = dist i k + dist k j
  indices = [(i,j) | i <- [0..n-1], j <- [i+1..n-1]]
  sum = foldl' (+) 0 <$> mapM road indices


ite231 t e c = if c then t else e

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      ass = map (map readBInt) remLines1
  in solve n ass

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n0 1 3\n1 0 2\n3 2 0\n"
inp2 = "3\n0 1 3\n1 0 1\n3 1 0\n"
inp3 = "5\n0 21 18 11 28\n21 0 13 10 26\n18 13 0 23 13\n11 10 23 0 17\n28 26 13 17 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == -1
test3 = tv3 == 82
alltest = test1 && test2 && test3
