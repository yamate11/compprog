body :: [Int] -> [[Int]]
body = 

out :: [[Int]] -> IO ()
out results = do
  (putStrLn . show . length) results
  (putStr . unlines . map (unwords . map show)) results

main :: IO ()
main = do
  con <- getContents
  let [line1, line2] = lines con
  (out . body . map read . words) line2
