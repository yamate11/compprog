{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: String -> Int -> Int
solve strK bD | sumDigitsF `mod` bD == 0 = numMultF
              | otherwise                = numMultF `mSub` 1
  where

  (sumDigitsF, numMultF) =
    V.foldl' op (0, 0) (V.zip vecK mVec)
    where
    vecK = V.fromList strK
    lenK = V.length vecK

    -- mVec = trace ("mVec " ++ show mVecA) mVecA
    mVec = V.reverse $ V.iterateN lenK (rot10 bD) (initV bD)

    op (sumDigits, numMult) (c, vec) =
      (sumDigits + d,
       (numMult +
        sum [vec VU.! ((-(sumDigits+i)) `mod` bD) | i <- [0..d-1]]) `mod` mPrime)
      where d = read [c]

initV :: Int -> VU.Vector Int
initV bD = VU.fromListN bD (1 : replicate (bD-1) 0)

shift bD v x = (VU.drop y v) VU.++ (VU.take y v)
    where y = (-x) `mod` bD

rot10 bD v = foldl1 (VU.zipWith mAdd) (map (shift bD v) [0..9])

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime
-- mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime
-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_nK]:remLines1 = remLines0
      [bs_nD]:remLines2 = remLines1
      nD = readBInt bs_nD
  in solve (B.unpack bs_nK) nD

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "30\n4\n"
inp2 = "1000000009\n1\n"
inp3 = "98765432109876543210\n58\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 6
test2 = tv2 == 2
test3 = tv3 == 635270834
alltest = test1 && test2 && test3

