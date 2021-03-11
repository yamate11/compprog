main = do
  cont <- getContents
  let [s] = words cont
      t = map f s
  putStrLn t
    where f '1' = '9'
          f '9' = '1'
