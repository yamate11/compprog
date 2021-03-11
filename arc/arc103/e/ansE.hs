import Data.List
import Data.Char

solve s | sanitary s = toStr (mkTree s)
        | otherwise = "-1\n"

sanitary s =
  head s == '1' && head r == '0'
    && all (\(p,q) -> p == q) (zip s (tail r))
  where r = reverse s

toStr = unlines . map (unwords . map show)

mkTree s = unfoldr f (1, zip [2..] (init s))
  where
    f (_, []) = Nothing
    f (node, (i,e):ps) = Just ([node,i], (if e == '1' then i else node, ps))

main = putStr . solve . takeWhile isAlphaNum =<< getContents
