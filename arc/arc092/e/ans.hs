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

naive0 [x] = x
naive0 xs = maximum [sub k xs | k <- [0..length xs - 1]]
  where
    sub k xs | k == 0 = naive0 (tail xs)
             | k == (length xs) - 1 = naive0 (init xs)
             | otherwise = naive0 ((init ys) ++ ((last ys) + z) : zs)
               where (ys, (_:z:zs)) = splitAt k xs

solve :: Int -> [Int] -> (Int, [Int])
solve n as | as_max <= 0 = noPlus n as_max as
           | otherwise   = somePlus n as
  where as_max = maximum as

noPlus n as_max as = (as_max, replicate k 1 ++ [n-k,n-k-1..2])
  where k = length $ takeWhile (< as_max) as

somePlus n as = (bVal, opList)
  where
    eLen = (n+1) `div` 2
    oLen = n `div` 2
    (es, os) = f $ partition fst $ zip (cycle [True,False]) as
      where f (x,y) = (map snd x, map snd y)
    (eVal, eMax) = myScan es
    (oVal, oMax) = myScan os
    initCut | odd n && eVal > oVal = []
            | odd n                = [n, 1]
            |          eVal > oVal = [n]
            | otherwise            = [1]
    (seq, bVal, bMax) = if eVal > oVal then (es, eVal, eMax)
                                       else (os, oVal, oMax)
    (part1, part2a) = span (<= 0) seq
    (part3r, part2r) = span (<= 0) $ reverse part2a
    part2 = reverse part2r
    opList = initCut ++ replicate (2 * k1) 1 ++ zs ++ [2*k3+1,2*k3..2]
      where
        k1 = length part1
        k3 = length part3r
        zs = map (\x -> if x <= 0 then 3 else 2) (tail part2)

myScan as = (sum (map (max 0) as), maximum as)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int, [Int])
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: (Int, [Int]) -> IO ()
outAnswer (bVal, opList) = do
  putStrLn $ show $ bVal
  putStrLn $ show $ length $ opList
  putStr $ unlines $ map show opList

main :: IO ()
main = outAnswer . tmain =<< B.getContents

