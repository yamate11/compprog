{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntMap.Strict as IM
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int)] -> [Int]
solve bN bM lstAB = map (\x -> (combi2 bN) - x) conn
  where
  conn = map (\(_,_,x) -> x) tr
  tr = tail $ reverse $ scanl' op (IM.empty, initCC, 0) (reverse lstAB)
  initCC = IM.fromDistinctAscList [(i,1) | i <- [1..bN]]
  op (!uf, !cc, !count) (a,b)
      -- | traceL "op" (show (a,b)) False = undefined
      | a' == b'  = (uf2, cc, count)
      | otherwise = (newUF, newCC, newCount)
    where
    (uf1, a') = getTop a uf
    (uf2, b') = getTop b uf1
    {-
    getTop x ufX | traceL "getTop" (show (x, ufX)) False = undefined
    getTop x ufX = traceL "getTopFin" (show aaa) aaa
      where aaa = getTopZ x ufX
    -}
    getTop x ufX = case IM.lookup x ufX of
      Nothing -> (ufX, x)
      Just y -> let (ufZ, z) = getTop y ufX
                in (IM.adjust (const z) x ufZ, z)
    -- newUF = traceL "newUF" (show (b', a', uf2, newUFZ)) newUFZ
    newUF = IM.insert b' a' uf2
    nA = cc IM.! a'
    nB = cc IM.! b'
    nSum = nA + nB
    newCount = count + (combi2 nSum) - (combi2 nA) - (combi2 nB)
    newCC = IM.adjust (const nSum) a' cc
    

combi2 n = (n * (n-1)) `div` 2

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bM lstAB

outAnswer :: [Int] -> IO ()
outAnswer ns = putStr (unlines (map show ns))

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

-------------------------------------------------------------------------------

inp1 = "4 5\n1 2\n3 4\n1 3\n2 3\n1 4\n"
inp2 = "6 5\n2 3\n1 2\n5 6\n3 4\n4 5\n"
inp3 = "2 1\n1 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == [0,0,4,5,6]
test2 = tv2 == [8,9,12,14,15]
test3 = tv3 == [1]
alltest = test1 && test2 && test3

