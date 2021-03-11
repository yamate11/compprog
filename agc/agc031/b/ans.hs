{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

mPrime = 10^9 + 7

lim = 2 * 10^5

solve :: Int -> [Int] -> Int
solve n cs = runST $ do
    vec <- VUM.replicate (lim+1) 0
    sub vec 1 (uniq cs)

    where
    sub vec xCur [] = return xCur
    sub vec xCur (c:cs) = do
      x <- VUM.read vec c
      let newX = x `mAdd` xCur
      VUM.write vec c newX
      sub vec newX cs


  
uniq [] = []
uniq [x] = [x]
uniq (y:x:xs) | y == x    = uniq (x:xs)
              | otherwise = y : (uniq (x:xs))

-- mAdd x y = (x + y) `mod` mPrime
mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      cs = map (\[x] -> readBInt x) remLines1
  in solve n cs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "5\n1\n2\n1\n2\n2\n"
inp2 = "6\n4\n2\n5\n4\n2\n4\n"
inp3 = "7\n1\n3\n1\n2\n3\n3\n2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 5
test3 = tv3 == 5
alltest = test1 && test2 && test3

