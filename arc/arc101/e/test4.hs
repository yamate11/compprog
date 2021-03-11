import System.Environment
import Data.List

mPrime = 10^9 + 7
mSafe = 2^31

foo :: Int -> Int
foo n = (foldl' (+) 0 (zipWith (*) [0..n] [0..n])) `mod` mPrime
bar :: Int -> Int
bar n = foldl' f 0 (zipWith g [0..n] [0..n])
  where f x y = (x + y) `mod` mPrime
        g x y = (x * y) `mod` mPrime
baz :: Int -> Int
baz n = (foldl' f 0 (zipWith g [0..n] [0..n])) `mod` mPrime
  where f x y = x' + y'
          where x' = if x < mSafe then x else x `mod` mPrime
                y' = if y < mSafe then y else y `mod` mPrime
        g x y = x' * y'
          where x' = if x < mSafe then x else x `mod` mPrime
                y' = if y < mSafe then y else y `mod` mPrime

  
main = do
  [t, sn] <- getArgs
  let n = read sn
      x | t == "0" = foo n
        | t == "1" = bar n
        | t == "2" = baz n
  putStrLn $ show $ x
  
