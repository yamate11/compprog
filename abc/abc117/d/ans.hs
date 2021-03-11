{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Data.Bits
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

col = 40

solve :: Int -> Int -> [Int] -> Int
solve bN bK as = snd calc
  where
  vecX = foldl (\v a -> VU.zipWith (+) v (vecExp a)) (VU.replicate col 0) as
  calc = VU.ifoldl f (0,0) vecX
    where
    f (dec, und) i numOne
      | testBit bK i = (dec', max (2^i * numZero + und) (2^i * numOne + dec))
      | otherwise    = (dec', 2^i * numOne + und)
      where numZero = bN - numOne
            dec' = 2^i * (max numZero numOne) + dec

vecExp x = VU.generate col (\i -> if testBit x i then 1 else 0)

-------------------------------------------------------------------------------

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

inp1 = "3 7\n1 6 3\n"
inp2 = "4 9\n7 4 0 3\n"
inp3 = "1 0\n1000000000000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 14
test2 = tv2 == 46
test3 = tv3 == 1000000000000
alltest = test1 && test2 && test3

