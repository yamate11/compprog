{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Monad.ST
import Data.List

func1 :: Int -> [Int] -> IO Int
func1 acc [] = return acc
func1 !acc (a:as) = func1 (acc + op1 a) as

func2 :: Int -> [Int] -> Int
func2 acc [] = acc
func2 acc (a:as) = func2 (acc + op1 a) as

func3 :: [Int] -> Int
-- func3 as = sum (map op1 as)
func3 as = foldl' (+) 0 (map op1 as)

func4 :: [Int] -> IO Int
-- func4 as = sum <$> mapM op2 as
-- func4 as = (foldl' (+) 0) <$> mapM op2 as
func4 as = foldM f 0 as
  where f acc a = (+ acc) <$> (op2 a)

op1 :: Int -> Int
op1 a = a * a

op2 :: Int -> IO Int
op2 a = return (a*a)

main = do
  cont <- getContents
  let [sn] = words cont
      n = read sn
--  x <- func1 0 [1..n]
--      x = func2 0 [1..n]
--      x = func3 [1..n]
  x <- func4 [1..n]
  putStrLn $ show x
  
