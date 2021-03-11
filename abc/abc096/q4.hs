import Data.Bits

big = 55555
bigg = big * 5

sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

primesL :: [Int]
primesL = takeWhile (< bigg) sieve

primesS :: [Int]
primesS = takeWhile (< big) sieve

bPrimesL :: Integer
bPrimesL = foldr (flip setBit) zeroBits $ takeWhile (< bigg) sieve

bPrimesS :: Integer
bPrimesS = bPrimesL .&. ((bit big) - 1)

buildStep :: [Integer] -> Int -> [Integer]
buildStep [one] n = [setBit one n]
buildStep (x:y:zs) n = (shiftL y n .|. x) : buildStep (y:zs) n

step :: [Integer] -> Int -> [Integer]
step a@(top:rest) n
  | shiftL top n .&. bPrimesL == zeroBits = buildStep a n
  | otherwise                             = a

{-
unpack :: Integer -> [Int]
unpack a = sub [] 0 a
  where sub acc n 0 = reverse acc
        sub acc n a
          | testBit a 0 = sub (n:acc) (n+1) (shiftR a 1)
          | otherwise   = sub  acc    (n+1) (shiftR a 1)
-}

unpack :: Integer -> [Int]
unpack a = sub [] 0 a
  where sub acc n 0 = reverse acc
        sub acc n a
          | testBit a n = sub (n:acc) (n+1) (clearBit a n)
          | otherwise   = sub  acc    (n+1) a

solve :: Int -> [Int]
solve n =
  let [_, _, _, seq] : _ =
        dropWhile (\[_, _, _, bot] -> length (unpack bot) < n) $
              scanl step [zeroBits, zeroBits, zeroBits, zeroBits]
                    (reverse primesS)
  in unpack seq
  
main =
  putStrLn $ show $ unpack (setBit zeroBits 10)

