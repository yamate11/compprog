{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int
solve n | n <= 9 = 0
        | otherwise = ((fm 4) * ((fm 4) - 1) `div` 2) * ((fm 2) - 2)
                      + (fm 14) * ((fm 4) - 1)
                      + (fm 24) * ((fm 2) - 1)
                      + (fm 74)
  where
    
  pvec = VU.toList $ VU.create $ do
    v <- VUM.replicate 101 0
    forM_ [2..n] $ \k -> do
      forM_ (prfac k) $ \(p,r) -> VUM.modify v (+ r) p
    return v

  fm :: Int -> Int
  fm k = length (filter (>= k) pvec)

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

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
  in solve n

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "9\n"
inp2 = "10\n"
inp3 = "100\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 0
test2 = tv2 == 1
test3 = tv3 == 543
alltest = test1 && test2 && test3
