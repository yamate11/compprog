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

solve :: Int -> Int
solve n = length [x | x <- list 9, x <= n]

mklist 0 = [""]
mklist n = concat [['3':x, '5':x, '7':x] | x <- mklist (n-1)]

iMklist :: Int -> [Int]
iMklist n = [read x | x <- mklist n, elem '3' x, elem '5' x, elem '7' x]

list n = concat [iMklist k | k <- [1..n]]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
  in solve n

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "575\n"
inp2 = "3600\n"
inp3 = "999999999\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 4
test2 = tv2 == 13
test3 = tv3 == 26484
alltest = test1 && test2 && test3
