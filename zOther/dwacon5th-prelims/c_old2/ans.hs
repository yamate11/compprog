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

solve :: Int -> String -> Int -> [Int] -> [Int]
solve n s q ks = count
  where

  sv = VU.fromList s

  appD = mkCntVec n 'D' sv
  appC = mkCntVec n 'C' sv
  posM = [i | i <- [0..n-1], sv VU.! i == 'M']

  count = foldr1 (zipWith (+)) lst
    where
    (_, lst) = mapAccumL op (replicate q 0) (zip ((-1):posM) posM)
    op thisCnt (jm1,jm2) = (newCnt, newCnt)
      where
      newCnt = zipWith3 (\c i d -> c + (i - d)) thisCnt inc dec
      inc = map g ks
        where g k = sum $ map f [i | i <- [jm1+1..jm2-1], sv VU.! i == 'D']
                where f i | i+k <= jm2 = 0
                          | otherwise = (appC VU.! (min (i+k-1) (n-1)))
                                        - (appC VU.! jm2)
      dec = map g ks
        where g k = sum $ map f [i | i <- [jm1+1..jm2-1], sv VU.! i == 'C']
                where f i | jm1 < 0      = 0
                          | jm1 <= i-k+1 = 0
                          | i-k < 0      =  appD VU.! jm1
                          | otherwise    = (appD VU.! jm1) - (appD VU.! (i-k))
      
mkCntVec n c0 sv = VU.unfoldrN n f (0,0)
  where f (cnt, i) | sv VU.! i == c0 = Just (cnt+1, (cnt+1, i+1))
                   | otherwise       = Just (cnt, (cnt, i+1))

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      [bs_s]:remLines2 = remLines1
      s = B.unpack bs_s
      [bs_q]:remLines3 = remLines2
      q = readBInt bs_q
      line4:remLines4 = remLines3
      ks = map readBInt line4
  in solve n s q ks

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr $ unlines $ map show xs

main :: IO ()
main = outAnswer . tmain =<< B.getContents


----------------------------------------------------------------------

inp1 = "18\nDWANGOMEDIACLUSTER\n1\n18\n"
inp2 = "18\nDDDDDDMMMMMCCCCCCC\n1\n18\n"
inp3 = "54\nDIALUPWIDEAREANETWORKGAMINGOPERATIONCORPORATIONLIMITED\n3\n20 30 40\n"
inp4 = "30\nDMCDMCDMCDMCDMCDMCDMCDMCDMCDMC\n4\n5 10 15 20\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == [1]
test2 = tv2 == [210]
test3 = tv3 == [0,1,2]
test4 = tv4 == [10,52,110,140]
alltest = test1 && test2 && test3 && test4

