import Data.List

getList :: IO [Int]
getList = do
  s <- getContents
  return $! [read x | x <- lines s]

main :: IO ()
main = do
  xs <- getList
  let a = foldl' (+) 0 xs
  putStrLn $ show a
