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
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [(Int,Int,Int)] -> Int
solve bN wsvs = VU.maximum theVec
  where

  wLim = bN * 10^4
  sorted = sortOn (\(w,s,_) -> w+s) wsvs

  theVec = VU.create $ do
    vec <- VUM.replicate (wLim+1) 0
    forM_ sorted $ \(w0,s0,v0) -> do
      let st = min s0 (wLim - w0)
      forM_ [st, st-1 .. 0] $ \w -> do
        v1 <- VUM.read vec w
        v2 <- VUM.read vec (w+w0)
        when (v0 + v1 > v2) $ VUM.write vec (w+w0) (v0+v1)
    return vec

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      wsvs = map (\[x1,x2,x3] -> (readBInt x1,readBInt x2,readBInt x3)) remLines1
  in solve bN wsvs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n2 2 20\n2 1 30\n3 1 40\n"
inp2 = "4\n1 2 10\n3 1 10\n2 4 10\n1 6 10\n"
inp3 = "5\n1 10000 1000000000\n1 10000 1000000000\n1 10000 1000000000\n1 10000 1000000000\n1 10000 1000000000\n"
inp4 = "8\n9 5 7\n6 2 7\n5 7 3\n7 8 8\n1 9 6\n3 3 3\n4 1 7\n4 5 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 50
test2 = tv2 == 40
test3 = tv3 == 5000000000
test4 = tv4 == 22
alltest = test1 && test2 && test3 && test4

