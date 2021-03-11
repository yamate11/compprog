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

solve :: Int -> Int -> String
solve n k = if n >= 2*k-1 then "YES" else "NO"

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_k]:remLines1 = remLines0
      n = readBInt bs_n
      k = readBInt bs_k
  in solve n k

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3 2\n"
inp2 = "5 5\n"
inp3 = "31 10\n"
inp4 = "10 90\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == "YES"
test2 = tv2 == "NO"
test3 = tv3 == "YES"
test4 = tv4 == "NO"
alltest = test1 && test2 && test3 && test4

