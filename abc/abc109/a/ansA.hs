solve a b | a*b `mod` 2 == 0 = "No"
          | otherwise = "Yes"

main = do
  cont <- getContents
  let [a,b] = map read $ words cont
  putStrLn $ solve a b
