{-# LANGUAGE BangPatterns #-}

import Data.List

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (mPrime + x - y) `mod` mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

mLstMul = foldl1' mMul

solve :: Int -> Int -> Int
solve n 1 = 1
solve n m = mLstMul $ map f (primeFact m)
  where f k = combi (n+k-1) k

sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

primes = takeWhile (< 32000) sieve

primeFact :: Int -> [Int]
primeFact x = pf0 x sieve

pf0 1 _ = []
pf0 x (p:sieves)
  | kk > 0 = kk : pf0 yy sieves
  | p*p > x = [1]
  | otherwise = pf0 x sieves
  where (kk, yy) = pf1 0 p x
        pf1 !acc p x | mm > 0    = acc
                     | otherwise = pf1 (acc+1) p dd
          where (dd,mm) = divMod x p

combi n0 r0 | r0 > (n0 - r0) = combi n0 (n0 - r0)
combi n0 0 = 1
combi n0 r0 = (mLstMul [n0,n0-1..(n0-r0+1)]) `mMul` (mInv (mLstMul [r0,r0-1..1]))

main = do
  cont <- getContents
  let [n,m] = map read $ words cont
      ans = solve n m
  putStrLn $ show $ ans
