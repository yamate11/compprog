solve :: Int -> Int -> Int -> Int -> [Int] -> [Int] -> String
solve n m x y xs ys =
  let xmax = maximum (x : xs)
      ymin = minimum (y : ys)
  in if xmax < ymin then "No War" else "War"

main = do
  cont <- getContents
  let [line1, line2, line3] = lines cont
      [n,m,x,y] = map read $ words line1
      xs = map read $ words line2
      ys = map read $ words line3
      ans = solve n m x y xs ys
  putStrLn $ ans
