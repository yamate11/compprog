import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [[Int]] -> (Int, [[Int]])
solve h w ass = (length coms, coms)
  where
    coms = reverse $ snd $ rowop $ zip [1..h] $ map (zip [1..w]) ass
    
rowop :: [(Int, [(Int, Int)])] -> (Maybe Int, [[Int]])
rowop [] = (Nothing, [])
rowop ((y,ps):pss) = (newPos, addCom ++ newCommands ++ commands)
  where
    (pos, commands) = rowop pss
    (newPos, newCommands) = colop y pos ps
    addCom = case newPos of
      Nothing -> []
      Just x -> if y == 1 then [] else [[y, x, y-1, x]]

colop :: Int -> Maybe Int -> [(Int, Int)] -> (Maybe Int, [[Int]])
colop _ _ [] = (Nothing, [])
colop y pos ((x,a):ps)
  | isOdd = case endP of
      Nothing -> (Just x, commands)
      Just x' -> (Nothing, newCommands x x' ++ commands)
  | otherwise = (endP, commands)
  where
    (endP, commands) = colop y pos ps
    isOdd | Just x == pos = a `mod` 2 == 0
          | otherwise     = a `mod` 2 == 1
    newCommands x1 x2 = [[y, x-1, y, x] | x <- [x2,x2-1..x1+1]]

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let [h, w] : ass = map bsReadInts (B.lines cont)
      (n, yss) = solve h w ass
  B.putStr $ B.unlines $ map (B.unwords . map (B.pack . show)) ([n] : yss)
