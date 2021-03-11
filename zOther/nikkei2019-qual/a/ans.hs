{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> (Int,Int)
solve n a b = (xmax, xmin)
  where
    xmax = min a b
    xmin = max 0 ((a + b) - n)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int,Int)
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_a,bs_b]:remLines1 = remLines0
      n = readBInt bs_n
      a = readBInt bs_a
      b = readBInt bs_b
  in solve n a b

outAnswer :: (Int,Int) -> IO ()
outAnswer (x,y) = putStrLn (unwords [show x, show y])

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "10 3 5\n"
inp2 = "10 7 5\n"
inp3 = "100 100 100\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == (3, 0)
test2 = tv2 == (5, 2)
test3 = tv3 == (100, 100)
alltest = test1 && test2 && test3

