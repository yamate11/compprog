solve n k 
  | k `mod` 2 == 0 = p*p*p + q*q*q
  | otherwise      = p*p*p
  where
    p = n `div` k
    q = (n + (k `div` 2)) `div` k

main = do
  cont <- getContents
  let [n,k] = map read $ words cont
      a = solve n k
  putStrLn $ show a
  
