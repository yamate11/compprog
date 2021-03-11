{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

lim :: Int
lim = 10 ^ 10

solve :: Int -> Int -> [Int] -> Int
solve bigN bigK hs = sub 1 (VU.cons 0 (VU.replicate (bigK-1) lim))
  where 
    vH = VU.fromListN (bigN+1) (0:hs)
    sub i vX
      | i == bigN = VU.head vX
      | otherwise =
          sub (i+1) (VU.zipWith (f (vH VU.! i) (VU.head vX))
                     (VU.drop (i+1) vH) (VU.snoc (VU.tail vX) lim))
      where f h0 x0 h x = min x (x0 + abs (h - h0))

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n, bs_k]:remLines1 = remLines0
      n = readBInt bs_n
      k = readBInt bs_k
      line2:remLines2 = remLines1
      hs = map readBInt line2
  in solve n k hs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "5 3\n10 30 40 50 20\n"
inp2 = "3 1\n10 20 10\n"
inp3 = "2 100\n10 10\n"
inp4 = "10 4\n40 10 20 70 80 10 20 70 80 60\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 30
test2 = tv2 == 20
test3 = tv3 == 0
test4 = tv4 == 40
alltest = test1 && test2 && test3 && test4
