{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> Int
solve bN as = sub 0 (VU.fromListN bN as)
  where
  sub !cnt vA
    | aMax < bN = cnt
    | otherwise = sub (cnt+1) (VU.imap f vA)
    where iMax = VU.maxIndex vA
          aMax = vA VU.! iMax
          f i a | i == iMax = a - bN
                | otherwise = a + 1

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve bN as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n3 3 3 3\n"
inp2 = "3\n1 0 3\n"
inp3 = "2\n2 2\n"
inp4 = "7\n27 0 0 0 0 0 0\n"
inp5 = "10\n1000 193 256 777 0 1 1192 1234567891011 48 425\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 0
test2 = tv2 == 1
test3 = tv3 == 2
test4 = tv4 == 3
test5 = tv5 == 1234567894848
alltest = test1 && test2 && test3 && test4 && test5

