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

solve :: Int -> [(Int,Int)] -> Int
solve bN abs | null aMore = 0
             | otherwise = s - b0
  where
    aMore = [(a,b) | (a,b) <- abs, a > b]
    (_, b0) = minimumBy f aMore
    f (_,b) (_,b') | b < b' = LT
                   | b == b' = EQ
                   | b > b' = GT
    s = sum (map fst abs)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      abs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN abs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "2\n1 2\n3 2\n"
inp2 = "3\n8 3\n0 1\n4 8\n"
inp3 = "1\n1 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 9
test3 = tv3 == 0
alltest = test1 && test2 && test3
