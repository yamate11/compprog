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
trace _ = id

solve :: Int -> [Int] -> Int
solve n as = answer
  where
  posLst :: [Int]
  posLst = trace ("posLst " ++ show posLst0) posLst0
  posLst0 = costLst as
  negLst :: [Int]
  negLst = trace ("negLst " ++ show negLst0) negLst0
  negLst0 = reverse $ costLst $ reverse as
  answer = minimum $ zipWith3 f posLst negLst [0,1..]
    where f p n w = 2 * (p + n) + w

costLst :: [Int] -> [Int]
costLst xs = scanr (+) 0 $ snd $ mapAccumR f initAcc $
                zip xs (tail xs ++ [big])
  where
    initAcc :: [(Int, Int)]
    initAcc = [(0, big)]
    f :: [(Int,Int)] -> (Int,Int) -> ([(Int,Int)], Int)
    f steps@((len, gap):rem) (x, xNext)
      | 4 * x <= xNext = ((1, costF xNext x):steps, 0)
      | x <= xNext = ((len+1, gap):rem, 0)
      | otherwise = g (costC x xNext) 0 1 steps
      where
        g :: Int -> Int -> Int -> [(Int,Int)] -> ([(Int,Int)], Int)
        g !h !cost !len ((tLen,gap):rem)
          | h <= gap = ((newLen, gap-h):rem, newCost)
          | otherwise = g (h-gap) newCost newLen rem
          where newCost = cost + h*tLen
                newLen = len + tLen

big = 10 ^ 10

epsilon = 2 ** (-64)

log4 :: Int -> Double
log4 x = logBase 4 (fromIntegral x)

costC x y = ceiling (log4 x - log4 y - epsilon)
costF x y = floor (log4 x - log4 y + epsilon)

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

inp1 = "4\n3 1 4 1\n"
inp2 = "5\n1 2 3 4 5\n"
inp3 = "8\n657312726 129662684 181537270 324043958 468214806 916875077 825989291 319670097\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 0
test3 = tv3 == 7
alltest = test1 && test2 && test3
