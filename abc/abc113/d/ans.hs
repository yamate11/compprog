import Data.List

solve :: Int -> Int -> Int -> Int
solve h w k = (acc !! h) !! 0 where

  acc = iterate f iAcc where
    iAcc = map (iteF 1 0 . (== k)) [1..w]
    f acc = foldl1' (zipWith mAdd) (map (change acc) validH)
    
  validH = filter isValid (power !! (w - 1))

isValid q = not $ or $ zipWith (&&) q (tail q)

power = iterate (concatMap (\q -> [False:q, True:q])) [[]]

change [x]       []         = [x]
change (x:xs)    (False:bs) = x  : change xs     bs
change (x:x':xs) (True:bs)  = x' : change (x:xs) bs

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

iteF t e c = if c then t else e

tmain :: String -> Int
tmain cont =
  let [h,w,k] = map read (words cont)
  in solve h w k

main :: IO ()
main = putStrLn . show . tmain =<< getContents

----------------------------------------------------------------------

inp1 = "1 3 2\n"
inp2 = "1 3 1\n"
inp3 = "2 3 3\n"
inp4 = "2 3 1\n"
inp5 = "7 1 1\n"
inp6 = "15 8 5\n"
tv1 = tmain inp1
tv2 = tmain inp2
tv3 = tmain inp3
tv4 = tmain inp4
tv5 = tmain inp5
tv6 = tmain inp6
test1 = tv1 == 1
test2 = tv2 == 2
test3 = tv3 == 1
test4 = tv4 == 5
test5 = tv5 == 1
test6 = tv6 == 437760187
alltest = test1 && test2 && test3 && test4 && test5 && test6
