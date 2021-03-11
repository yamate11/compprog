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
trace _ = id

solve :: Int -> [Int] -> Int
solve bN as = cntL + cntS
  where
  top0 : sorted = sortOn (* (-1)) as
  -- sorted = traceL "sorted" sortedX sortedX
  ((cntM,topM), lstPos) = mapAccumL f (0,top0) (zip [1..] sorted)
    where
    f (cnt,top) (k,a) | top < 2*bN = ((cnt,top), top - ht)
                      | otherwise = (newAcc, pos)
      where
        ht = a + cnt
        (lp, pos) = divMod (top - ht) (bN + 1)
        newAcc = (cnt + lp*k, top + lp*((k-1) - bN))
  (cntL, topL) | topM < 2*bN = (cntM, topM)
               | otherwise = (cntM + (topM - 2*bN)*bN, 2*bN)
  cntS = solveSimp bN (map (topL -) (0:lstPos))

solveSimp :: Int -> [Int] -> Int
-- solveSimp bN as | traceL "solveSimp" as False = undefined
solveSimp bN as = sub 0 (VU.fromListN bN as)
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

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa




-------------------------------------------------------------------------------

inp1 = "4\n3 3 3 3\n"
inp2 = "3\n1 0 3\n"
inp3 = "2\n2 2\n"
inp4 = "7\n27 0 0 0 0 0 0\n"
inp5 = "10\n1000 193 256 777 0 1 1192 1234567891011 48 425\n"
inp6 = "3\n0 0 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
tv6 = tmain $ B.pack inp6
test1 = tv1 == 0
test2 = tv2 == 1
test3 = tv3 == 2
test4 = tv4 == 3
test5 = tv5 == 1234567894848
test6 = tv6 == 1
alltest = test1 && test2 && test3 && test4 && test5 && test6

