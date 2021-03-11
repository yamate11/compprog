import Data.List

solve :: Int -> [String] -> String
solve n ws | cond1 ws && cond2 ws = "Yes"
           | otherwise = "No"

cond1 [] = True
cond1 (a:s) = notElem a s && cond1 s

cond2 [_] = True
cond2 (a:b:s) = last a == head b && cond2 (b:s)

main = do
  cont <- getContents
  let n : ws = words cont
  putStrLn $ solve (read n) ws
