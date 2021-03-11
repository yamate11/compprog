{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Double] -> Double
solve n ps = pw
  where
    res = foldl' op (VU.fromList [1]) ps
    op vec p = VU.zipWith (+)
               (VU.snoc (VU.map (* p) vec) 0)
               (VU.cons 0 (VU.map (* (1-p)) vec))
    pw = VU.sum (VU.take ((n+1) `div` 2) res)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Double
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      ps = map (read . B.unpack) line2
  in solve n ps

outAnswer :: Double -> IO ()
outAnswer x = putStrLn (show x)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3\n0.30 0.60 0.80\n"
inp2 = "1\n0.50\n"
inp3 = "5\n0.42 0.01 0.42 0.99 0.42\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 0.612
test2 = tv2 == 0.5
test3 = tv3 == 0.3821815872
alltest = test1 && test2 && test3
