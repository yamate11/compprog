{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> [Int] -> [Int]
solve bN bQ as qs = map solveOne qs where

  vA = VU.reverse $ VU.fromListN bN as
  vASum = VU.postscanl' (+) 0 vA
  vAEven = VU.postscanl' (+) 0 (VU.ifilter (\i _ -> even i) vA)

  lX = (bN-1) `div` 2
  vX = VU.fromListN lX
         [((vA VU.! (i+1)) + (vA VU.! (2*(i+1)))) `div` 2 | i <- [0 .. lX-1]]

  solveOne q = ans where

    i0 = binsch (bsJ q) (-1) lX
    bsJ q i = vX VU.! i < q
    ans = vASum VU.! i0 + vAEven VU.! (VU.length vAEven - 1) - vAEven VU.! i0
  
binsch f lo hi | hi == lo + 1 = hi
               | f mid        = binsch f lo mid
               | otherwise    = binsch f mid hi
  where mid = (lo + hi) `div` 2

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_q]:remLines1 = remLines0
      n = readBInt bs_n
      q = readBInt bs_q
      line2:remLines2 = remLines1
      as = map readBInt line2
      qs = map (\[x] -> readBInt x) remLines2
  in solve n q as qs

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr (unlines (map show xs))

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "5 5\n3 5 7 11 13\n1\n4\n9\n10\n13\n"
inp2 = "4 3\n10 20 30 40\n2\n34\n34\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
