{-# LANGUAGE MultiWayIf #-}

import Data.List
import Data.Bits
import Debug.Trace

-- traceQ label a
--   Traces the value of a with label.
traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a
-- traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

bigP = 1000000000 + 7
addMod x y = (x + y) `mod` bigP
subtMod x y = (bigP + x - y) `mod` bigP
multMod x y = (x * y) `mod` bigP
prodMod xs = foldl' multMod 1 xs

-- powerTT i == 10^(2^i)   (mod bigP)
powerTT :: [Int]
powerTT = iterate (\x -> x `multMod` x) 10

-- power10 k == 10^k    (mod bigP)
power10 :: Int -> Int
power10 x = prodMod $ zipWith (\b z -> if b then z else 1) bitList powerTT
  where
    bitList = map (flip testBit 0)
                  (takeWhile (> 0) (iterate (flip shiftR 1) x))

solve :: Int -> Int
solve valS = error ""

type StSt = (Int, Int)  -- stage-step pair

-- stage-step pair, forward m step
ststFwd :: StSt -> Int -> StSt
ststFwd (stage, step) shift =
  if step + shift < n
  then (stage, step + shift)
  else ststFwd (stage + 1, 0) (shift - (n - step))
  where n = numStepsInStage stage

ststDiff :: StSt -> StSt -> Int
ststDiff (stage1, step1) (stage2, step2) = step2 + vm - step1
  where vm = sum $ map numStepsInStage [stage1 .. stage2 - 1]

numStepsInStage :: Int -> Int
numStepsInStage stage = (power10 stage) `subtMod` (power10 (stage - 1))

upStage :: StSt -> Int -> (StSt, Int)
upStage stst@(stage, step) over =
  if step + m <= n
  then (ststFwd stst m, m * stage - over)
  else upStage (stage+1, 0) (over - stage * (n - step))
  where
    m = (over + (stage - 1)) `div` stage
    n = numStepsInStage stage

phase1 :: Int -> (Int, Int)
phase1 valS = (num, ststDiff ststL ststH)
  where
    filt (_, ((stageL, _), (stageH, _))) = stageL + 2 <= stageH
    (num, (ststL, ststH)) : _ =
      dropWhile filt $ zip [0..] $ iterate nextPair (firstPair valS)

firstPair :: Int -> (StSt, StSt)
firstPair valS = chase (1,0) (1,0) valS

nextPair :: (StSt, StSt) -> (StSt, StSt)
nextPair (ststL, ststH@(stageH, _)) =
  chase ststL (ststFwd ststH 1) (-stageH)

chase :: StSt -> StSt -> Int -> (StSt, StSt)
chase ststL ststH shift
  | shift == 0 = (ststL, ststH)
  | shift > 0  = chase ststL newH (-newShiftH)
  | shift < 0  = chase newL ststH newShiftL
  where
    (newH, newShiftH) = upStage ststH shift
    (newL, newShiftL) = upStage ststL (-shift)

main :: IO ()
main = do
  cont <- getContents
  let valS = read cont
--      ans = solve valS
      ans = phase1 valS
  putStrLn $ show $ ans
  
--------

sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand
