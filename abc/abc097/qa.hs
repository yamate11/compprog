solve :: Int -> Int -> Int -> Int -> String
solve a b c d =
  if (abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d
  then "Yes" else "No"

main :: IO ()
main = do
  line <- getContents
  let [a,b,c,d] = map read (words line)
  putStrLn (solve a b c d)

