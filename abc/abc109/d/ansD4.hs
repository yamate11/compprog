import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [[Int]] -> (Int, [[Int]])
solve h w ass = (length coms, coms)
  where
    coms = rowop Nothing (zip [1..] (map (zip [1..]) ass))

rowop :: Maybe Int -> [(Int,[(Int,Int)])] -> [[Int]]
rowop _   []             = []
rowop pos ((y,xas):yxas) = thisRes ++ rowop thisPos yxas
  where
    (thisPos, thisRes)
      = colop Nothing
        $ map (\(x,a) -> if pos == Just x then (x,a+1) else (x,a)) xas

    colop :: Maybe Int -> [(Int,Int)] -> (Maybe Int, [[Int]])
    colop Nothing      []               = (Nothing, [])
    colop start@(Just x) [] | null yxas = (start, [])
                            | otherwise = (start, [[y, x, y+1, x]])
    colop start ((x,a):xas)
      | a `mod` 2 == 0 = colop start xas
      | otherwise = case start of
          Nothing -> colop (Just x) xas
          Just x' -> (pos', coms x' x ++ res')
      where coms x1 x2 = [[y,t,y,t+1] | t <- [x1..x2-1]]
            (pos', res') = colop Nothing xas

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let [h, w] : ass = map bsReadInts (B.lines cont)
      (n, yss) = solve h w ass
  putStr $ unlines $ map (unwords . map show) ([n] : yss)

