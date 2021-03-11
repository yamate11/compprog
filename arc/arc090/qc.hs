
sumN :: [Int] -> [Int] -> Int -> Int
sumN a1s a2s n = s1 + s2
  where
    s1 = sum (take (n + 1) a1s)
    s2 = sum (drop n a2s)

solve :: Int -> [Int] -> [Int] -> Int
solve valN a1s a2s =
  maximum (map (sumN a1s a2s) [0 .. valN-1])

main :: IO ()
main = do
  cont <- getContents
  let valN : as = map read (words cont)
      (a1s, a2s) = splitAt valN as
      answer = solve valN a1s a2s
  putStrLn $ show $ answer
