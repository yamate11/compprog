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
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> Int
solve bN bK as = lastVec VU.! bK
  where
  lastVec = foldl princF initVec as
  initVec = VU.cons 1 (VU.replicate bK 0)
  princF prev a = VU.postscanl' secondF 0 (VU.fromListN (bK+1) [0..bK])
    where secondF acc k 
            | k-(a+1) < 0   = x
            | otherwise     = x `mSub` (prev VU.! (k-(a+1)))
            where x = acc `mAdd` (prev VU.! k)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bK]:remLines1 = remLines0
      bN = readBInt bs_bN
      bK = readBInt bs_bK
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve bN bK as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

prime :: Int
prime = 10 ^ 9 + 7

mAdd x y | s < prime = s
         | otherwise = s - prime
  where s = x + y

mSub x y = mAdd (prime + x) (-y)

-------------------------------------------------------------------------------

inp1 = "3 4\n1 2 3\n"
inp2 = "1 10\n9\n"
inp3 = "2 0\n0 0\n"
inp4 = "4 100000\n100000 100000 100000 100000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 5
test2 = tv2 == 0
test3 = tv3 == 1
test4 = tv4 == 665683269
alltest = test1 && test2 && test3 && test4

