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
import Debug.Trace

solve :: Int -> [(Int,Int,Int)] -> Int
solve bigN abcs = maximum [xa, xb, xc]
  where
    (xa, xb, xc) = foldl' op (0,0,0) abcs
      where
      op (pa, pb, pc) (a, b, c) = (a + max pb pc, b + max pc pa, c + max pa pb)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigN]:remLines1 = remLines0
      bigN = readBInt bs_bigN
      abcs = map (\[x1,x2,x3] -> (readBInt x1,readBInt x2,readBInt x3)) remLines1
  in solve bigN abcs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n10 40 70\n20 50 80\n30 60 90\n"
inp2 = "1\n100 10 1\n"
inp3 = "7\n6 7 8\n8 8 3\n2 5 2\n7 8 6\n4 6 8\n2 3 4\n7 5 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 210
test2 = tv2 == 100
test3 = tv3 == 46
alltest = test1 && test2 && test3
