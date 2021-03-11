{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> Int
solve k a b
  | k == 1     = 2
  | b <= a + 2 = k + 1
--  | a == 1     = b + (b-a) * q + r
  | a + 1 > k  = k + 1
  | otherwise = b + (b-a) * q + r
  where (q,r) = divMod (k - (a+1)) 2

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_k,bs_a,bs_b]:remLines1 = remLines0
      k = readBInt bs_k
      a = readBInt bs_a
      b = readBInt bs_b
  in solve k a b

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4 2 6\n"
inp2 = "7 3 4\n"
inp3 = "314159265 35897932 384626433\n"
inp4 = "2 1 10\n"
inp5 = "4 1 10\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 7
test2 = tv2 == 8
test3 = tv3 == 48518828981938099
test4 = tv4 == 10
test5 = tv5 == 19
alltest = test1 && test2 && test3 && test4 && test5

