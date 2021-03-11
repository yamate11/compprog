{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

solve :: String -> Int
solve s | n `mod` 2 == 0 = (n `div` 2) + k
        | otherwise     = (n `div` 2) + 1 + k

  where

  n = length s

  (sa, sb) = splitAt (n `div` 2) s

  (pred0, seq1, seq2) 
    | n `mod` 2 == 0 = (const True, reverse sa, sb)
    | otherwise = ((== (head sb)), reverse sa, (tail sb))

  k = length $ takeWhile id $ zipWith f seq1 seq2 where
    f x y = pred0 x && x == y

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

inp1 = "010\n"
inp2 = "100000000\n"
inp3 = "00001111\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 8
test3 = tv3 == 4
alltest = test1 && test2 && test3
