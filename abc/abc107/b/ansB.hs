import Data.List
import Data.Maybe

----------------------------------------------------------------------

solve :: Int -> Int -> [[Char]] -> String
solve h w ass = unlines $ transpose $ compress $ transpose $ compress ass

compress :: [[Char]] -> [[Char]]
compress ass = catMaybes $ map f ass
  where f as | and [ a == '.' | a <- as] = Nothing
             | otherwise = Just as

tmain :: String -> String
tmain cont =
  let sh : sw : ass = words cont
      h = read sh
      w = read sw
  in solve h w ass

main = putStr . tmain =<< getContents
  

