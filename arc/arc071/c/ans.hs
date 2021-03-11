{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [String] -> String
solve n ss =
  concat $
  zipWith replicate (foldr1 (zipWith min) (map countEach ss)) alphabet

alphabet = ['a'..'z']

countEach s0 = snd $ mapAccumL op (sort s0) alphabet where
  op s c = (newS, length cs) where
    (cs, newS) = span (== c) s

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      ss = map (\[x] -> B.unpack x) remLines1
  in solve n ss

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\ncbaa\ndaacc\nacacac\n"
inp2 = "3\na\naa\nb\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == "aac"
test2 = tv2 == ""
alltest = test1 && test2

