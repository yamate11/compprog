import Data.Vector as V

fib :: Int -> Int
fib max = go max
  where go 0 = 0
        go 1 = 1
        go n = fibs V.! (n - 1) + fibs V.! (n - 2)
        fibs = V.fromList [go x | x <- [0..max]]
        
main =
  putStrLn (show (fib 8))
  
