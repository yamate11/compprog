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

solve :: String -> String -> Int -> [(Int,Int,Int,Int)] -> [String]
solve bS bT q abcds = map ansF abcds
  where
  readStr s = VU.fromList $ scanl' (+) 0 $ map isANum s
  vS = readStr bS
  vT = readStr bT
  ansF (a,b,c,d) | equiv (fnAB a b vS) (fnAB c d vT) = "YES"
                 | otherwise = "NO"
  fnAB p q vec = (nA, nB)
    where nA = vec VU.! q - vec VU.! (p-1)
          nB = (q-p+1) - nA
  equiv (a1,b1) (a2,b2) = ((a1 + 2*b1) - (a2 + 2*b2)) `mod` 3 == 0

isANum 'A' = 1
isANum _   = 0


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [String]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bS]:remLines1 = remLines0
      bS = B.unpack bs_bS
      [bs_bT]:remLines2 = remLines1
      bT = B.unpack bs_bT
      [bs_q]:remLines3 = remLines2
      q = readBInt bs_q
      abcds = map (\[x1,x2,x3,x4] -> (readBInt x1,readBInt x2,readBInt x3,readBInt x4)) remLines3
  in solve bS bT q abcds

outAnswer :: [String] -> IO ()
outAnswer ss = putStr $ unlines ss

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "BBBAAAABA\nBBBBA\n4\n7 9 2 5\n7 9 1 4\n1 7 2 5\n1 7 2 4\n"
inp2 = "AAAAABBBBAAABBBBAAAA\nBBBBAAABBBBBBAAAAABB\n10\n2 15 2 13\n2 13 6 16\n1 13 2 20\n4 20 3 20\n1 18 9 19\n2 14 1 11\n3 20 3 15\n6 16 1 17\n4 18 8 20\n7 20 3 14\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == ["YES", "NO", "YES", "NO"]
test2 = tv2 == ["YES","YES","YES","YES","YES","YES","NO","NO","NO","NO"]
alltest = test1 && test2

