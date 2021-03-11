solve 0 100 = 101
solve 0 a = a
solve 1 100 = 10100
solve 1 a = a * 100
solve 2 100 = 1010000
solve 2 a = a * 10000


main = do
  conts <- getContents
  let [a,b] = map read $ words conts
      answer = solve a b
  putStrLn $ show answer
