-------------------------------------------------------------------------------
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace

solve :: Int -> Int -> [Int] -> Int
solve n a xs = sum [reduce V.! i VU.! (i*a) | i <- [1..n]]
  where

  reduce = foldl update initTbl xs

  initTbl = V.fromListN (n+1) (v1 : repeat v2)
    where v1 = VU.fromListN (a*n + 1) (1 : repeat 0)
          v2 = VU.replicate (a*n + 1) 0

  update :: V.Vector (VU.Vector Int) -> Int -> V.Vector (VU.Vector Int)
  update tbl x = V.fromListN (n+1) [upd i | i <- [0..n]]
    where
      upd :: Int -> VU.Vector Int
      upd 0 = tbl V.! 0
      upd i = upd0 (tbl V.! (i-1)) (tbl V.! i)
              -- VU.fromListN (a*n+1) [vval v1 (j-x) + vval v2 j | j <- [0..a*n]]
      upd0 :: VU.Vector Int -> VU.Vector Int -> VU.Vector Int
      upd0 v1 v2 = 
                   VU.slice 0 x v2 VU.++ VU.fromListN (a*n+1-x) (
                   [v1 VU.! (j-x) + v2 VU.! j | j <- [x..a*n]])
{-
      upd0 v1 v2 = VU.fromListN (a*n+1) [yyy j + v2 VU.! j | j <- [0..a*n]]
        where yyy j | j - x >= 0 = v1 VU.! (j-x)
                    | otherwise  = 0
-}

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_a]:remLines1 = remLines0
      n = readBInt bs_n
      a = readBInt bs_a
      line2:remLines2 = remLines1
      xs = map readBInt line2
  in solve n a xs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "4 8\n7 9 8 9\n"
inp2 = "3 8\n6 6 9\n"
inp3 = "8 5\n3 6 2 8 7 6 5 9\n"
inp4 = "33 3\n3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 5
test2 = tv2 == 0
test3 = tv3 == 19
test4 = tv4 == 8589934591
alltest = test1 && test2 && test3 && test4
