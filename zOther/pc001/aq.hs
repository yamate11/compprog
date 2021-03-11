main = do
  cont <- getContents
  let [x,y] = map read (words cont)
      answer = if x `mod` y == 0 then -1 else x
  putStrLn (show answer)

