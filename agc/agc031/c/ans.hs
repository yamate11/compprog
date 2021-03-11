{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> Maybe [Int]
solve n a b | even (popCount (xor a b)) = Nothing
            | otherwise = Just (subsolve n n (2^n - 1) a b)

subsolve :: Int -> Int -> Int -> Int -> Int -> [Int]
subsolve n 1 mask a b = [a, b]
subsolve n k mask a b = part1 ++ part2
  where
  t = (xor a b) .&. mask
  lsb = t .&. (-t)
  newMask = xor mask lsb
  inNewMask = newMask .&. (-newMask)
  c = xor a inNewMask
  part1 = subsolve n (k-1) newMask a c
  part2 = subsolve n (k-1) newMask (xor c lsb) b
  
readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_a,bs_b]:remLines1 = remLines0
      n = readBInt bs_n
      a = readBInt bs_a
      b = readBInt bs_b
  in solve n a b

outAnswer :: Maybe [Int] -> IO ()
outAnswer Nothing = putStrLn "NO"
outAnswer (Just xs) = do
  putStrLn "YES"
  putStrLn (unwords (map show xs))

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "2 1 3\n"
inp2 = "3 2 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2

