main :: IO ()
main = do
  cont <- getContents
  putStr $ "2018" ++ (drop 4 cont)
  
