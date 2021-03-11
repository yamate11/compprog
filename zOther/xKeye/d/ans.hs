{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> [Int] -> Int
solve bN bM as bs = princ (1, bN*bM, aRem0, bRem0, 0, 0, 0)
  where
  aRem0 = sortOn (* (-1)) as
  bRem0 = sortOn (* (-1)) bs

  princ (acc, x, aRem, bRem, aOcc, bOcc, emp)
    | x == 0 = acc
    | isHead x aRem && isHead x bRem =
      princ (acc, x-1, tail aRem, tail bRem, aOcc+1, bOcc+1, emp+aOcc+bOcc)
    | x == bN*bM = 0
    | isHead x aRem = 
      princ (acc `mMul` bOcc, x-1, tail aRem, bRem,
             aOcc+1, bOcc, emp+bOcc-1)
    | isHead x bRem = 
      princ (acc `mMul` aOcc, x-1, aRem, tail bRem,
             aOcc, bOcc+1, emp+aOcc-1)
    | emp == 0 = 0
    | otherwise = princ (acc `mMul` emp, x-1, aRem, bRem, aOcc, bOcc, emp-1)

isHead x [] = False
isHead x (y:_) = x == y

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      line2:remLines2 = remLines1
      as = map readBInt line2
      line3:remLines3 = remLines2
      bs = map readBInt line3
  in solve bN bM as bs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

inp1 = "2 2\n4 3\n3 4\n"
inp2 = "3 3\n5 9 7\n3 6 9\n"
inp3 = "2 2\n4 4\n4 4\n"
inp4 = "14 13\n158 167 181 147 178 151 179 182 176 169 180 129 175 168\n181 150 178 179 167 180 176 169 182 177 175 159 173\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 2
test2 = tv2 == 0
test3 = tv3 == 0
test4 = tv4 == 343772227
alltest = test1 && test2 && test3 && test4
