
lim1 :: Int -> Int -> Int
lim1 _ 1 = 1
lim1 x b 
  | b*b > x   = 1
  | otherwise = last $ takeWhile (< x) $ iterate (* b) (b*b)

solve :: Int -> Int
solve x = maximum [lim1 x b | b <- [1..x]]

main :: IO ()
main = do
  line <- getContents
  let [x] = map read (words line)
  putStrLn (show (solve x))
