{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = solve0 as

solve0 [] = 0
solve0 as
  | num == length as = mkRoot m0 num
  | otherwise        = max (mkRoot m0 num) (maximum (map solve0 nxt))

  where

  m0 = minimum as
  num = 1 + length [ a | a <- (tail as), a == m0 ]

  nxt = unfoldr f (map (+ (- m0)) as)
    where f [] = Nothing
          f as = Just (bs, ds)
            where (bs, cs) = span (> 0) as
                  ds = dropWhile (== 0) cs

epsilon = 10 ** (-9)
mkRoot q p = floor (1.0 - epsilon + (fromIntegral p ** (1.0 / (fromIntegral q))))


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

