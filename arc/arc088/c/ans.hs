{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

solve :: Int -> Int -> Int
solve x y = length as where
  as = takeWhile (<= y) $ iterate (* 2) x where

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_x,bs_y]:remLines1 = remLines0
      x = readBInt bs_x
      y = readBInt bs_y
  in solve x y

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3 20\n"
inp2 = "25 100\n"
inp3 = "314159265 358979323846264338\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 3
test3 = tv3 == 31
alltest = test1 && test2 && test3
