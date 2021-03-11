import Data.Char

solve :: [Char] -> Int
solve s = error ""
  where
    n = length s
    anns = zip [0..] s
    isEven = n `mod` 2 == 0

    f p' c' ((p,c):anns)
      | i < mid && c == c' = f p' c anns
      | i < mid && c /= c' = f p  c anns
      | i > mid && c == c' = f p' c anns
      | i > mid && c /= c' =
        (min (mid - p') (p - mid)) + mid
        (min (mid - p') (p - (mid + 1)) + mid + 1


main :: IO ()
main = do
  cont <- getContents
  putStrLn $ show $ solve (takeWhile isDigit cont)
