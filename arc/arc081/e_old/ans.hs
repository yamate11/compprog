{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Set as S
import Data.Char
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: String -> String
solve s = stage2 "" c0 bs0
  where

  (b0, bs0) = minCoverLS (reverse s)
  c0 = leastNonElem b0

  stage2 acc c []     = reverse (c:acc)
  stage2 acc c (b:bs) = stage2 (c:acc) newC bs
    where newC = leastNonElem (tail (dropWhile (/= c) b))
    
allChars = S.fromDistinctAscList ['a'..'z']

minCoverLS s = sub [] s
  where
    sub acc s = case minCover s of
      (True, t, newS) -> sub (t:acc) newS
      (False, t, _) -> (t, acc)

minCover :: String -> (Bool, String, String)
minCover s = sub "" s allChars
  where
    sub t "" _ = (False, t, "")
    sub t (c:s) cset | S.null newCset = (True, c:t, s)
                     | otherwise      = sub (c:t) s newCset
      where newCset = S.delete c cset

leastNonElem s = S.findMin (foldr S.delete allChars s)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_str]:remLines1 = remLines0
      str = B.unpack bs_str
  in solve str

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "atcoderregularcontest\n"
inp2 = "abcdefghijklmnopqrstuvwxyz\n"
inp3 = "frqnvhydscshfcgdemurlfrutcpzhopfotpifgepnqjxupnskapziurswqazdwnwbgdhyktfyhqqxpoidfhjdakoxraiedxskywuepzfniuyskxiyjpjlxuqnfgmnjcvtlpnclfkpervxmdbvrbrdn\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == "b"
test2 = tv2 == "aa"
test3 = tv3 == "aca"
alltest = test1 && test2 && test3

