solve :: Int -> Int -> Int -> Int -> Int -> Int
solve q h s d n = f n
  where
    f :: Int -> Int
    f 0 = 0
    f 1 = best1
    f n = (n `div` 2) * best2 + (n `mod` 2) * best1
    best1 :: Int
    best1 = minimum [q * 4, h * 2, s]
    best2 :: Int
    best2 = min (best1 * 2) d
  

main :: IO ()
main = do
  cont <- getContents
  let [q, h, s, d, n] = map read (words cont)
      answer = solve q h s d n
  putStrLn $ show answer

