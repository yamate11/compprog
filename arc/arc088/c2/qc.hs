count x y
  | x <= y = 1 + count (2*x) y
  | otherwise = 0

main = do
  cont <- getContents
  let [x,y] = map read $ words cont
      answer = count x y
  putStrLn (show answer)
