import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [[Int]] -> (Int, [[Int]])
solve h w ass = (length coms, coms)
  where
    coms = reverse $ rowop Nothing 1 [] ass

rowop _ _ res [] = res
rowop pos y res (as:ass)
  = rowop thisPos (y+1) (thisRes ++ vert pos ++ res) ass
  where
    (thisPos, thisRes) = colop Nothing 1 [] as 

    vert Nothing = []
    vert (Just x) = [[y-1, x, y, x]]

    colop start x res [] = (start, res)
    colop start x res (a:as)
      | a' `mod` 2 == 0 = colop start (x+1) res as
      | otherwise = case start of
          Nothing -> colop (Just x) (x+1) res as
          Just x' -> colop Nothing (x+1) (coms x' x ++ res) as
      where a' | pos == Just x = a + 1
               | otherwise     = a
            coms x1 x2 = [[y,t,y,t+1] | t <- [x2-1,x2-2..x1]]

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let [h, w] : ass = map bsReadInts (B.lines cont)
      (n, yss) = solve h w ass
  B.putStr $ B.unlines $ map (B.unwords . map (B.pack . show)) ([n] : yss)
