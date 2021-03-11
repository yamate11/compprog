{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.IntSet as S
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> String
solve bN bK as | S.member bK first = "First"
               | otherwise         = "Second"
  where
  first = foldl pFunc S.empty [0..bK]
  pFunc is x
    | S.member x is = is
    | otherwise =
      S.union is (S.fromDistinctAscList (takeWhile (<= bK) (map (+ x) as)))
  

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bK]:remLines1 = remLines0
      bN = readBInt bs_bN
      bK = readBInt bs_bK
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve bN bK as

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "2 4\n2 3\n"
inp2 = "2 5\n2 3\n"
inp3 = "2 7\n2 3\n"
inp4 = "3 20\n1 2 3\n"
inp5 = "3 21\n1 2 3\n"
inp6 = "1 100000\n1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
tv6 = tmain $ B.pack inp6
test1 = tv1 == "First"
test2 = tv2 == "Second"
test3 = tv3 == "First"
test4 = tv4 == "Second"
test5 = tv5 == "First"
test6 = tv6 == "Second"
alltest = test1 && test2 && test3 && test4 && test5 && test6

