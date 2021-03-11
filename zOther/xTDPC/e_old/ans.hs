{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import Data.List
import Debug.Trace

solve :: Int -> String -> Int
solve d sn = answer
  where
    rcn = reverse $ map readC sn

    sall:shifts = scanr f 0 rcn
      where f x y = (x + y) `mod` d

    dShift lst k = lstB ++ lstA
      where (lstA, lstB) = splitAt ((-k) `mod` d) lst

    dSum = foldr (zipWith mAdd) $ take d $ repeat 0

    lstBefore p prev = take d $ zipWith (-) (drop p accsum) accsum
      where accsum = scanl' mAdd 0 $ drop ((1-p) `mod` d) $ cycle prev

    cnts = unfoldr f (1 : take (d-1) (repeat 0))
      where f lst = Just (lst, lstBefore 10 lst)

    modified = dSum $ zipWith3 f shifts rcn cnts
      where f s c u = dShift (lstBefore c u) s

    answer = (head modified) - 1 + (if sall == 0 then 1 else 0)

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

readC :: Char -> Int
readC c = read [c]

tmain :: String -> Int
tmain cont = let [sd, sn] = lines cont in solve (read sd) sn

main :: IO ()
main = putStrLn . show . tmain =<< getContents

