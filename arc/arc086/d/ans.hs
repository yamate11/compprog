{-# LANGUAGE TupleSections #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> [(Int,Int)]
solve n as = stage1 ++ stage2 where
  asWidx = zip [1..] as
  amax = maximum as
  amaxarg = theIndex amax
  amin = minimum as
  aminarg = theIndex amin
  theIndex x = fst $ head $ filter ((== x) . snd) asWidx
  stage1
    | amax >= -amin = map ((amaxarg,) . fst) $ filter ((< 0) . snd) asWidx
    | otherwise     = map ((aminarg,) . fst) $ filter ((> 0) . snd) asWidx
  stage2
    | amax >= -amin = zipWith (,) [1..n-1] [2..n]
    | otherwise     = zipWith (,) [n,n-1..2] [n-1,n-2..1]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [(Int,Int)]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

conv :: [(Int, Int)] -> String
conv xys 
  = unlines $ show (length xys) : map (\(x,y) -> show x ++ " " ++ show y) xys

main :: IO ()
main = putStr . conv . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n-2 5 -1\n"
inp2 = "2\n-1 -3\n"
inp3 = "5\n0 0 0 0 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
