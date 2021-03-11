-------------------------------------------------------------------------------
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> Int
solve n x as = minimum (take n costRot)
  where
  costRot = unfoldr f (0, as)
    where f (k,ps) = Just (sum qs + k*x, (k+1, qs))
            where qs = zipWith min (ys++xs) ps
                  (xs, ys) = splitAt k as

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_x]:remLines1 = remLines0
      n = readBInt bs_n
      x = readBInt bs_x
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n x as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "2 10\n1 100\n"
inp2 = "3 10\n100 1 100\n"
inp3 = "4 10\n1 2 3 4\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 12
test2 = tv2 == 23
test3 = tv3 == 10
alltest = test1 && test2 && test3
