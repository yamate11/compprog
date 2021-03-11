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

c = 50

solve :: Int -> (Int, [Int])
solve bK = (c, replicate t (b+c+1) ++ replicate (c-t) b)
  where
  (s,t) = divMod bK c
  b     = c - 1 + s - t

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int, [Int])
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bK]:remLines1 = remLines0
      bK = readBInt bs_bK
  in solve bK

outAnswer :: (Int, [Int]) -> IO ()
outAnswer (n,as) = do
  putStrLn $ show $ n
  putStrLn $ unwords $ map show $ as

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "0\n"
inp2 = "1\n"
inp3 = "2\n"
inp4 = "3\n"
inp5 = "1234567894848\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5

