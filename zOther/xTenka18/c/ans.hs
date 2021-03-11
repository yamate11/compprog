{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = 
  let (k, rem) = divMod n 2
      (e1, e2) = findMiddle rem (drop (k-1) (sort as))
      s = sum [abs (a - e1) | a <- as]
  in 2 * s - abs (e2-e1)

findMiddle 0 (x:y:_) = (x, y)
findMiddle 1 (x:y:z:_) | y - x < z - y = (y, x)
                       | otherwise     = (y, z)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      as = map (\[x] -> readBInt x) remLines1
  in solve n as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents



inp1 = "5\n6\n8\n1\n2\n3\n"
inp2 = "6\n3\n1\n4\n1\n5\n9\n"
inp3 = "3\n5\n5\n1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 21
test2 = tv2 == 25
test3 = tv3 == 8
alltest = test1 && test2 && test3
