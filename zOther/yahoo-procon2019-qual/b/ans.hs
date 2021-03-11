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

solve :: [(Int,Int)] -> String
solve [(a,b),(c,d),(e,z)] = if (f 1) + (f 2) + (f 3) + (f 4) == 2 then "YES" else "NO"
  where
    flat :: [Int]
    flat = [a,b,c,d,e,z]
    f :: Int -> Int
    f i = if length [x | x <- flat, x == i] == 1 then 1 else 0


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines0
  in solve lstAB

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4 2\n1 3\n2 3\n"
inp2 = "3 2\n2 4\n1 2\n"
inp3 = "2 1\n3 2\n4 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == "YES"
test2 = tv2 == "NO"
test3 = tv3 == "YES"
alltest = test1 && test2 && test3

