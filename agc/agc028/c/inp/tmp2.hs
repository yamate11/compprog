{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> [String] -> [(Int,String,Int)] -> [[Int]] -> Int
solve m n as bs cs ds = error ""

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_m,bs_n]:remLines1 = remLines0
      m = readBInt bs_m
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
      (lines3, remLines3) = splitAt (n) remLines2
      bs = map (\[x] -> B.unpack x) lines3
      (lines4, remLines4) = splitAt (n-1) remLines3
      cs = map (\[x1,x2,x3] -> (readBInt x1,B.unpack x2,readBInt x3)) lines4
      ds = map (map readBInt) remLines4
  in solve m n as bs cs ds

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

