solve k = (k `div` 2) * ((k+1) `div` 2)

main = do
  cont <- getContents
  let [k] = words cont
      a = solve (read k)
  putStrLn $ show $ a
