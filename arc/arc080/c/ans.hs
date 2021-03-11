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
import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> String
solve bN as | (n2 == 0 && n1 - 1 <= n4) || n1 <= n4 = "Yes"
            | otherwise = "No"
  where
    as2 = filter (\x -> x `mod` 2 == 0) as
    as4 = filter (\x -> x `mod` 4 == 0) as2
    n4 = length as4
    n2 = length as2 - n4
    -- n1 = traceL "x" (n1X,n2,n4) n1X
    n1 = bN - (n2 + n4)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve bN as

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


-------------------------------------------------------------------------------

inp1 = "3\n1 10 100\n"
inp2 = "4\n1 2 3 4\n"
inp3 = "3\n1 4 1\n"
inp4 = "2\n1 1\n"
inp5 = "6\n2 7 1 8 2 8\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == "Yes"
test2 = tv2 == "No"
test3 = tv3 == "Yes"
test4 = tv4 == "No"
test5 = tv5 == "Yes"
alltest = test1 && test2 && test3 && test4 && test5

