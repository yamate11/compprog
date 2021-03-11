{-# LANGUAGE BangPatterns #-}
import System.Environment

mPrime :: Int
mPrime = 10 ^ 9 + 7

act :: Int -> IO Int
act n = do
  let sub !acc !i | i > n = return acc
                  | otherwise = sub ((acc * i) `mod` mPrime) (i+1)
  sub 1 1

main = do
  [arg1] <- getArgs
  x <- act $ read arg1
  putStrLn $ show $ x
  
sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

