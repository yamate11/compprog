solve :: Int -> Int -> Int
solve n k = answer
  where


tmain cont = let [n, k] = map read (words cont) in solve n k

main = putStrLn . show . tmain =<< getContents
  
