{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int)] -> String
solve n m lstAB | V.length oddV > 0 = "No"
                | V.length six > 0 = "Yes"
                | V.length four >= 3 = "Yes"
                | V.length four <= 1 = "No"
                | null chk = "No"
                | otherwise = "Yes"
  where
  nbr = V.create $ do
    vec <- VM.replicate (n+1) []
    forM_ lstAB $ \(a,b) -> do
      VM.modify vec (a :) b
      VM.modify vec (b :) a
    return vec

  deg = V.map length nbr
  oddV = V.filter odd deg
  six = V.filter (== 6) deg
  four = V.filter (== 4) deg
  [p1, p2] = V.toList four
  qs = nbr V.! p1
  rs = map (follow p1) qs
  chk = filter (== p1) rs

  follow p r | r == p1 = p1
             | r == p2 = p2
             | otherwise = follow r s
    where [s] = filter (/= p) (nbr V.! r)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n m lstAB

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "7 9\n1 2\n1 3\n2 3\n1 4\n1 5\n4 5\n1 6\n1 7\n6 7\n"
inp2 = "3 3\n1 2\n2 3\n3 1\n"
inp3 = "18 27\n17 7\n12 15\n18 17\n13 18\n13 6\n5 7\n7 1\n14 5\n15 11\n7 6\n1 9\n5 4\n18 16\n4 6\n7 2\n7 11\n6 3\n12 14\n5 2\n10 5\n7 8\n10 15\n3 15\n9 8\n7 15\n5 16\n18 15\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == "Yes"
test2 = tv2 == "No"
test3 = tv3 == "Yes"
alltest = test1 && test2 && test3

