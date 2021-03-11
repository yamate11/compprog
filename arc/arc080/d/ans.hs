{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> [Int] -> [[Int]]
solve bH bW bN as = answer
  where
    xs = concat $ map (\(i,a) -> replicate a i) $ zip [1..bN] as
    answer = unfoldr f (True, xs)
      where f (_, []) = Nothing
            f (b, xs) | b == True  = Just (xs1, (False, xs2))
                      | b == False = Just (reverse xs1, (True, xs2))
              where (xs1, xs2) = splitAt bW xs

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [[Int]]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bH,bs_bW]:remLines1 = remLines0
      bH = readBInt bs_bH
      bW = readBInt bs_bW
      [bs_bN]:remLines2 = remLines1
      bN = readBInt bs_bN
      line3:remLines3 = remLines2
      as = map readBInt line3
  in solve bH bW bN as

outAnswer :: [[Int]] -> IO ()
outAnswer css = putStr $ unlines $ map (unwords . map show) css

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "2 2\n3\n2 1 1\n"
inp2 = "3 5\n5\n1 2 3 4 5\n"
inp3 = "1 1\n1\n1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

