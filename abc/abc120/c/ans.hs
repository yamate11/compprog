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

solve :: String -> Int
solve s = acc
  where
    (stack, acc) = foldl' op ([], 0) s
    op ([], !acc) c = ([c], acc)
    op (stack@(c1:p), !acc) c2 | c1 == c2 = (c2:stack, acc)
                               | c1 /= c2 = (p, acc+2)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_s]:remLines1 = remLines0
      s = B.unpack bs_s
  in solve s

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "0011\n"
inp2 = "11011010001011\n"
inp3 = "0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 4
test2 = tv2 == 12
test3 = tv3 == 0
alltest = test1 && test2 && test3

