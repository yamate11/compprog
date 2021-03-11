{-# LANGUAGE BangPatterns #-}

import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Mutable as VM
import Control.Monad.ST
import Data.Foldable
import Data.List
import Data.Maybe
import qualified Data.ByteString.Lazy.Char8 as B
-- import Debug.Trace

kFix :: Int
kFix = 1000000007

binFix :: (Int -> Int -> Int) -> Int -> Int -> Int
binFix op !a !b = (a `op` b) `rem` kFix

addFix = binFix (+)
subtFix !a !b = (a - b + kFix) `rem` kFix
mulFix = binFix (*)

sumFix :: [Int] -> Int
sumFix = foldl' addFix 0 

nMax :: Int
nMax = 200000

vPow :: VU.Vector Int
vPow = VU.iterateN (nMax + 1) f 1
  where f x = (x * 2) `rem` kFix

type IVal = (Int, Int)
-- (x, m) :: Ival
--    means that the number of node is m, and out of 2^m cases
--    there is a stone in x' cases where x' \equiv x mod kFix

goUp :: [IVal] -> IVal
goUp ivs = (x, m) where (_, x, m) = goUpSub ivs

goUpSub :: [IVal] -> (Int, Int, Int)
--                   (numCases0, numCases1, m)
goUpSub = foldl' guBin (1, 0, 0)
  where
    guBin :: (Int, Int, Int) -> IVal -> (Int, Int, Int)
    guBin arg1@((!x0, !x1, !m)) arg2@(!x', !m') = 
      -- The two p values should be equal
      let newM = m + m'
          xNeg = vPow VU.! m' `subtFix` x'
          newX0 = x0 `mulFix` xNeg
          newX1 = (x0 `mulFix` x') `addFix` (x1 `mulFix` xNeg)
      in (newX0, newX1, newM)

body :: Int -> [Int] -> Int
body numNodes parent = 
  let f :: IVal -> Int
      f (x, p) = x `mulFix` (vPow VU.! (numNodes - p))
  in foldl' addFix 0 $ map f $ accumulate 0
  where

    accumulate :: Int -> [IVal]
    accumulate i = (1, 1) : rest
      where
        rest = case children V.! i of
          []   -> []
          [j]  -> accumulate j
          cs@_ -> map goUp $ transpose $ map accumulate cs

    children :: V.Vector [Int]
    children = V.create $ do
      v <- VM.replicate numNodes []
      for_ (zip [1..] parent) $ \(i, p) -> VM.modify v (i :) p
      return v

main :: IO ()
main = do
  cont <- B.getContents
  let [[n], ps] =
        map (map (fst . fromJust . B.readInt) . B.words) (B.lines cont)
  putStrLn $ show $ body (n + 1) ps

