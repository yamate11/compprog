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
import Debug.Trace

solve :: Int -> String -> Int -> [Int] -> [Int]
solve n s q ks = map count ks
  where

  sv = VU.fromList s

  count k = sum lst
    where
    (_, lst) = mapAccumL op (0,0,0) [0..n-1]
      where
      op (numD, numM, numDM) i 
        | cur == 'D' = ((numD1 + 1, numM1, numDM1), 0)
        | cur == 'M' = ((numD1, numM1 + 1, numDM1 + numD1), 0)
        | cur == 'C' = ((numD1, numM1, numDM1), numDM1)
        | otherwise  = ((numD1, numM1, numDM1), 0)
        where
          cur = sv VU.! i
          left = sv VU.! (i-k)
          (numD1, numM1, numDM1)
            | i-k < 0 = (numD, numM, numDM)
            | left == 'D' = (numD - 1, numM, numDM - numM)
            | left == 'M' = (numD, numM - 1, numDM)
            | otherwise   = (numD, numM, numDM)

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

