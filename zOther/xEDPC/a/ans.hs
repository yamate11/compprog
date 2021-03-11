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

solve :: Int -> [Int] -> Int
solve n (h1:h2:hs) = fst $ snd $ foldl' op ((0, h1), (abs (h2-h1), h2)) hs
  where op ((c2, ht2), (c1, ht1)) h =
          ((c1, ht1), (min (c2 + abs (ht2 - h)) (c1 + abs (ht1 - h)), h))
    
readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      hs = map readBInt line2
  in solve n hs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "4\n10 30 40 20\n"
inp2 = "2\n10 10\n"
inp3 = "6\n30 10 60 10 60 50\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 30
test2 = tv2 == 0
test3 = tv3 == 40
alltest = test1 && test2 && test3
