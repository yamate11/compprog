main = do
  cont <- getContents
  case map read (words cont) of
    1 : _ -> putStrLn "Hello World"
    2 : a : b : _ -> putStrLn $ show $ a + b
