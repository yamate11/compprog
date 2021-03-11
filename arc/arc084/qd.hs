{-# LANGUAGE ViewPatterns, ScopedTypeVariables #-}

import qualified Data.ByteString.Lazy.Char8 as B
-- import qualified Data.Map.Strict as M
import qualified Data.Set as S
import qualified Data.Sequence as Q
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM
import Data.List
import Data.Maybe
import Control.Monad
import Control.Monad.ST
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a
-- traceQ _ a = a

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

num_digits :: Int -> Int -> Int
num_digits k n = ceiling (logBase (fromIntegral k) ((fromIntegral n) + 0.5))

power_int :: Int -> Int -> Int
power_int x y = round ((fromIntegral x) ** (fromIntegral y))

nextPower :: Int -> Int
nextPower n = 10 `power_int` (num_digits 10 n)

sumColumns :: Int -> Int
sumColumns n | n < 10    = n
sumColumns n | otherwise = (n `mod` 10) + sumColumns (n `div` 10)
  
solve :: Int -> Int
solve valK = runST act
  where
    act :: forall s. ST s Int
    act = do
      vDist <- VM.replicate valK valK
      vSw <- VM.replicate valK False
      VM.write vDist 0 0
      VM.write vSw 0 True
      act1 valK (Q.fromList [0]) vDist vSw

    act1 :: forall s. Int -> Q.Seq Int -> VM.MVector s Int -> VM.MVector s Bool
            -> ST s Int
    act1 minDist (Q.viewl -> Q.EmptyL) _ _ = return minDist
    act1 minDist (Q.viewl -> carry Q.:< queue) vDist vSw = do
      VM.write vSw carry False
      dist <- VM.read vDist carry 
      if dist >= minDist - 1
        then act1 minDist queue vDist vSw
        else do
        aqs <- forM [0 .. 9] (procBranch dist)
        let candNmd = dist + (sumColumns carry)
            newMinDist = if candNmd == 0 then minDist
                         else min minDist candNmd
        act1 newMinDist (queue Q.>< Q.fromList (concat aqs)) vDist vSw
          where
            procBranch :: Int -> Int -> ST s [Int]
            procBranch dist k = do
              let x = carry + k * valK
                  newCarry = x `div` 10
                  newDist = dist + (x `mod` 10)
              oldDist <- VM.read vDist newCarry
              if newDist < minDist - 1 && newDist < oldDist
                then do
                  VM.write vDist newCarry newDist
                  sw <- VM.read vSw newCarry
                  let ret = if sw then [] else [newCarry]
                  VM.write vSw newCarry True
                  return ret
                else return []

main :: IO ()
main = do
  conts <- B.getContents
  let [valK] = bsReadInts conts
      x = solve valK
  putStrLn $ show x
  
