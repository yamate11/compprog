{-# LANGUAGE BangPatterns #-}

-- This code was written after reading the editorial.

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Debug.Trace
import System.Random
import Control.Monad

solve :: Int -> [Int] -> [Int]
solve n as | n `mod` 2 == 0 = reverse $ sort [sum_even, sum_odd]
           | otherwise = [sum_odd + diff, sum_even - diff]
  where
    sum_all = sum as
    sum_even = f_sum_even as
    sum_odd = sum_all - sum_even
    diff = calc_diff (max 0 (sum_even-sum_odd)) (sum_even + 1) as

f_sum_even as = sub 0 as
  where
    sub !acc []       = acc
    sub !acc [a]      = acc + a
    sub !acc (a:_:as) = sub (acc+a) as

calc_diff dmin dmax as
  | dmax == dmin + 1 = dmin
  | try dmid as = calc_diff dmid dmax as
  | otherwise = calc_diff dmin dmid as
  where
    dmid = (dmax + dmin) `div` 2

try goal [a] = goal <= a
try goal (w0:b0:as@(w1:as'))
  | w0 >= goal && w0 <= b0 = try goal as
  | otherwise              = try goal (w1 + (w0-b0) : as')

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let (n:as) = bsReadInts cont
      ans= solve n as
  putStrLn $ unwords $ map show ans

{-
naive :: Int -> [Int] -> [Int]
naive n as = let (x,y) = naive' 0 as in [x,y]

naive' :: Int -> [Int] -> (Int, Int)
naive' player as = choose player $ map f [0..(length as)-1] 
  where
  opponent = 1 - player
  f i = -- trace ("f i " ++ show (as, i, xxx)) xxx
        xxx
    where (as1, (t: as2)) = splitAt i as
          xxx = myAdd player t $ reccal $ filter (not . null) [reverse as1, as2]
  -- reccal lst | trace ("reccal " ++ show lst) False = undefined
  reccal [] = (0,0)
  reccal [asA] = myAddL opponent asA (0,0)
  reccal [asA, asB] = 
    choose opponent
    $ [myAddP (myAddL opponent asA (0,0)) (naive' (pl asA) asB),
       myAddP (myAddL opponent asB (0,0)) (naive' (pl asB) asA)]
    where pl lst | length lst `mod` 2 == 0 = opponent
                 | otherwise               = player
                  
myAdd 0 t (a,b) = (a+t, b)
myAdd 1 t (a,b) = (a, b+t)

myAddL p as (a,b) 
  | p == 0 = (a + sum_even, b + sum_odd)
  | p == 1 = (a + sum_odd, b + sum_even)
  where sum_even = f_sum_even as
        sum_odd = sum as - sum_even

myAddP (a,b) (c,d) = (a+c, b+d)

choose 0 = maximum
choose 1 = minimum


randTest = do
  gen <- newStdGen
  let n = 11
      lst = take n $ randomRs (1,1000) gen
  when (naive n lst /= solve n lst) (error ("error " ++ show lst))

main = do
  forM_ [0..200] $ \i -> randTest

-}
