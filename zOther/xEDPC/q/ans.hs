{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
-- import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> [Int] -> Int
solve bN hs as = runST $ do
  vec <- VUM.replicate (bN+1) 0
  forM_ (zip hs as) $ \(h,a) -> do
    cur <- bit_intv vec h
    bit_add vec bN h (cur + a)
  bit_intv vec bN

-------------------------------------------------------------------------------

bit_add :: VUM.MVector s Int -> Int -> Int -> Int -> ST s ()
bit_add v n i x = sub i
  where
    sub !j | j > n     = return ()
           | otherwise = do
               VUM.modify v (max x) j
               sub (j + (j .&. (-j)))

bit_intv :: VUM.MVector s Int -> Int -> ST s Int
bit_intv v i = sub 0 i
  where
    sub !acc 0 = return acc
    sub !acc !j = do
      y <- VUM.read v j
      sub (max acc y) (j - (j .&. (-j)))


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      hs = map readBInt line2
      line3:remLines3 = remLines2
      as = map readBInt line3
  in solve bN hs as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n3 1 4 2\n10 20 30 40\n"
inp2 = "1\n1\n10\n"
inp3 = "5\n1 2 3 4 5\n1000000000 1000000000 1000000000 1000000000 1000000000\n"
inp4 = "9\n4 2 5 8 3 6 1 7 9\n6 8 8 4 6 3 5 7 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 60
test2 = tv2 == 10
test3 = tv3 == 5000000000
test4 = tv4 == 31
alltest = test1 && test2 && test3 && test4

