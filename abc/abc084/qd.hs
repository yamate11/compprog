{-# LANGUAGE RankNTypes #-}
import Control.Monad
import Control.Monad.ST
import Data.Bits
import Data.Maybe
import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM

pMax = 100000

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

data BIT s a = BIT Int (VM.MVector s a)

bitLsbAdd :: Int -> Int
bitLsbAdd k = k + (k .&. (-k))

bitLsbOff :: Int -> Int
bitLsbOff k = k .&. complement (k .&. (-k))

bitEmpty :: (Num a, VM.Unbox a) => Int -> ST s (BIT s a)
bitEmpty size = VM.replicate size 0 >>= return . BIT size

bitFromPairsWithSize :: (Num a, VM.Unbox a) =>
                        Int -> [(Int, a)] -> ST s (BIT s a)
bitFromPairsWithSize size ps = do
  bit <- bitEmpty size
  forM_ ps $ \(n, x) -> bitUpd bit n x
  return bit

bitFromListWithSize :: (Num a, VM.Unbox a) => Int -> [Int] -> ST s (BIT s a)
bitFromListWithSize size ns = bitFromPairsWithSize size [(n, 1) | n <- ns]

bitFix :: (VM.Unbox a) => (forall s. ST s (BIT s a)) -> V.Vector a
bitFix act = V.create $ do
  BIT _ vec <- act
  return vec

bitFixSum :: (Num a, VM.Unbox a) => V.Vector a -> Int -> a
bitFixSum vec n =
  sum $ map ((vec V.!) . (+ (-1))) $ takeWhile (> 0) $ iterate bitLsbOff n

bitUpd :: (Num a, VM.Unbox a) => BIT s a -> Int -> a -> ST s ()
bitUpd (BIT size vec) n diff = forM_ indices act
  where indices = takeWhile (<= size) (iterate bitLsbAdd (n + 1))
        act k = VM.modify vec (+ diff) (k - 1)

intersectOL :: (Ord a) => [a] -> [a] -> [a]
intersectOL [] _ = []
intersectOL _ [] = []
intersectOL (a:as) (b:bs) | a == b = a : intersectOL as bs
                          | a <  b = intersectOL as (b:bs)
                          | a >  b = intersectOL (a:as) bs

solve :: Int -> [[Int]] -> [Int]
solve valQ lrs = [query l r | [l, r] <- lrs]
  where
    like2017 = intersectOL sieve [2 * p - 1 | p <- sieve]
    vbit = bitFix (bitFromListWithSize pMax (takeWhile (< pMax) like2017))
    query :: Int -> Int -> Int
    query l r = bitFixSum vbit (r + 1) - bitFixSum vbit l

main :: IO ()
main = do
  conts <- B.getContents
  let [valQ] : lrs = map bsReadInts (B.lines conts)
      answer = solve valQ lrs
  putStr (unlines (map show answer))
