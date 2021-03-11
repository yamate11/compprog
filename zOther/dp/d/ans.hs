{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [(Int,Int)] -> Int
solve bN bW wvs = vecFin VU.! bW
  where
  vecFin = foldl' op (VU.replicate (bW+1) 0) wvs
  op vec (w,v) =
    VU.zipWith max vec (VU.replicate w 0 VU.++ VU.map (+ v) vec)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bW]:remLines1 = remLines0
      bN = readBInt bs_bN
      bW = readBInt bs_bW
      wvs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bW wvs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3 8\n3 30\n4 50\n5 60\n"
inp2 = "5 5\n1 1000000000\n1 1000000000\n1 1000000000\n1 1000000000\n1 1000000000\n"
inp3 = "6 15\n6 5\n5 6\n6 4\n6 6\n3 5\n7 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 90
test2 = tv2 == 5000000000
test3 = tv3 == 17
alltest = test1 && test2 && test3
