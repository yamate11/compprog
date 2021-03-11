import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad


solve n = error ""
  where


primes = take 1024 sieve 

mPrimes = alter lst1 (reverse lst2)
  where (lst1, lst2) = splitAt 512 primes

alter lst1 lst2 = concat $ zipWith (\a b -> [a,b]) lst1 lst2

(mP1, mP2) = splitAt 512 mPrimes
vecP1 = VU.fromList mP1
vecP2 = VU.fromList mP2

enc (y,x) = y*512 + x

mkTable = VU.create $ do
  vec1 <- VU.unsafeThaw vecP1
  vec2 <- VU.unsafeThaw vecP2
  table <- VUM.new (512*512)
  forM_ [0..511] $ \y ->
    let o | y `mod` 2 == 0 = 0
          | otherwise        1
    forM_ [o .. o+2*511] $ \x ->
      
    

  forM_ [0..511] $ \x ->
    forM_ [0,2..1023] $ 


  return table


sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand
    


main = do
  cont <- getContents
  let n = read cont
  putStr (solve n)
