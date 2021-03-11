suitable = map (* 111) [1 .. 9]

main = do
  cont <- getContents
  let [w] = words cont
      n = read w
      answer = head [k | k <- suitable, n <= k]
  putStrLn (show answer)
  
