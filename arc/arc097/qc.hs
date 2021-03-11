import Data.List

theListU :: String -> Int -> [String]
theListU s k = [take i (drop n s) | n <- [0 .. len-1],
                 i <- [1 .. min k (len - n)]]
  where len = length s

solve :: String -> Int -> String
solve s k = theList !! (k-1)
  where 
    theList = nub $ sort (theListU s k)

main :: IO ()
main = do
  lines <- getContents
  let [s,str_k] = words lines
      k = read str_k
  putStrLn $ solve s k
