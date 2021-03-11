{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ = id

solve :: Int -> Int -> Int -> Int -> Int -> Int -> (Int,Int)
solve a b c d e f = (y, z)
  where
  (x, y, z) = maximum [ fromWater (100 * a * na + 100 * b * nb)
                      | nb <- [0 .. f `div` (100 * b)],
                        na <- [0 .. (f - (100*b*nb)) `div` (100*a)]]

  fromWater :: Int -> (Double, Int, Int)
  fromWater 0 = (0.0, 0, 0)
  fromWater water | trace ("fromWater " ++ show water) False = undefined
  fromWater water = maximum [ fromD nd | nd <- [0 .. sugarLim `div` d] ]
    where
    sugarLim = min ((water `div` 100) * e) (f - water)
    fromD :: Int -> (Double, Int, Int)
    fromD nd = ((fromIntegral (100 * sugar)) / (fromIntegral (water + sugar)), 
                water + sugar, sugar)
      where
      nc = (sugarLim - d * nd) `div` c
      sugar = c * nc + d * nd

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int,Int)
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_a,bs_b,bs_c,bs_d,bs_e,bs_f]:remLines1 = remLines0
      a = readBInt bs_a
      b = readBInt bs_b
      c = readBInt bs_c
      d = readBInt bs_d
      e = readBInt bs_e
      f = readBInt bs_f
  in solve a b c d e f

outAnswer :: (Int,Int) -> IO ()
outAnswer (x,y) = putStrLn (show x ++ " " ++ show y)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "1 2 10 20 15 200\n"
inp2 = "1 2 1 2 100 1000\n"
inp3 = "17 19 22 26 55 2802\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == (110, 10)
test2 = tv2 == (200, 100)
test3 = tv3 == (2634, 934)
alltest = test1 && test2 && test3
