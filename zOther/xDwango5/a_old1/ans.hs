{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = j
  where
    s = sum as
    (_, j) = minimum $ zip (map f as) [0..]
      where
        f a = abs (a * n - s)
        

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

tv1 = solve 3 [1,2,3]
test1 = tv1 == 1
tv2 = solve 4 [2,5,2,5]
test2 = tv2 == 0
alltest = test1 && test2
