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

solve :: Int -> [Int] -> [Int] -> Int
solve bN as bs | sumA < sumB = -1
               | otherwise = (length needs) + theLen
  where
    sumA = sum as
    sumB = sum bs
    supply = zipWith f as bs
      where f a b | a > b = Just (a-b)
                  | otherwise = Nothing
    srtSupply = sortOn (* (-1)) (catMaybes supply)
    acc = scanl' (+) 0 srtSupply
    needs = catMaybes $ zipWith g as bs
      where g a b | b > a = Just (b-a)
                  | otherwise = Nothing
    sumNeeds = sum needs
    -- theLen = trace ("xx " ++ show (sumA, sumB, srtSupply, acc, needs, theLenA)) theLenA
    theLen = length $ takeWhile (< sumNeeds) acc
    

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      as = map readBInt line2
      line3:remLines3 = remLines2
      bs = map readBInt line3
  in solve bN as bs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n2 3 5\n3 4 1\n"
inp2 = "3\n2 3 3\n2 2 1\n"
inp3 = "3\n17 7 1\n25 6 14\n"
inp4 = "12\n757232153 372327760 440075441 195848680 354974235 458054863 463477172 740174259 615762794 632963102 529866931 64991604\n74164189 98239366 465611891 362739947 147060907 118867039 63189252 78303147 501410831 110823640 122948912 572905212\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 3
test2 = tv2 == 0
test3 = tv3 == -1
test4 = tv4 == 5
alltest = test1 && test2 && test3 && test4
