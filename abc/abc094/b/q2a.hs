main = do
  _ : m : x : as <- return . map read . words =<< getContents
  let left = length (filter (< x) as)
  putStrLn (show (min left (m - left)))
