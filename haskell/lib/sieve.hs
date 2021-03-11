import Data.List

-- Sieve of Eratosthenes

-- only needed in the main function of this file
import System.Environment

-- sieve : the infinite list of prime numbers
sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

-- prfac : prime factorization

prfac :: Int -> [(Int,Int)]
prfac n = filter ((>= 1) . snd) $ unfoldr f (sieve, n)
  where
    f (_, 1) = Nothing
    f (p:ps, k) | p*p > k   = Just ((k, 1), ([], 1))
                | otherwise = Just ((p, pow), (ps, div k p_pow))
      where (pow, p_pow) = divmany k p
    divmany k p = sub 0 1 k
      where sub pow p_pow x | m == 0    = sub (pow+1) (p_pow*p) d
                            | otherwise = (pow, p_pow)
              where (d,m) = divMod x p

-- divisors : list of divosors (not sorted)

divisors :: Int -> [Int]
divisors n = sub (prfac n)
  where sub []            = [1]
        sub ((p,r) : prs) = [x*y | x <- [p^k | k <- [0..r]], y <- sub prs]


-- Command Line Usage: sieve lim
--   Prints the list of prime numbers less than lim.

-- Performance (HPE-580, SSD)
--   10,000 -> 0.05s, 100,000 -> 0.09s, 300,000 -> 0.15s
--   1,000,000 -> 0.50s, 10,000,000 -> 11.4s

main :: IO ()
main = do
  [lim] <- getArgs
  putStrLn $ show $ takeWhile (< (read lim)) sieve

