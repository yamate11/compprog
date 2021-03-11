solve :: Int -> Int
solve n = minimum $ map f [0,9..n]
  where f x = base_exp 6 (n-x) + base_exp 9 x

base_exp k 0 = 0
base_exp k n = n `mod` k + base_exp k (n `div` k)

main = putStrLn . show . solve . read =<< getContents
  
