{-# LANGUAGE BangPatterns #-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [[Int]] -> (Int, B.ByteString)
solve h w ass = rowop Nothing 1 0 B.empty ass

rowop :: Maybe Int -> Int -> Int -> B.ByteString -> [[Int]]
      -> (Int, B.ByteString)
rowop _ _ !cnt !res [] = (cnt, res)
rowop pos y !cnt !res (as:ass)
  = rowop thisPos (y+1) newCnt newRes ass

  where
    (thisPos, thisCnt, thisRes) = colop Nothing 1 0 B.empty as 

    newRes = B.append (B.append res (vert pos)) thisRes

    vert :: Maybe Int -> B.ByteString
    vert Nothing = scmd []
    vert (Just x) = scmd [[y-1, x, y, x]]

    newCnt = cnt + thisCnt + if isJust pos then 1 else 0

    colop :: Maybe Int -> Int -> Int -> B.ByteString -> [Int]
          -> (Maybe Int, Int, B.ByteString)
    colop start x !cnt !res [] = (start, cnt, res)
    colop start x !cnt !res (a:as)
      | a' `mod` 2 == 0 = colop start (x+1) cnt res as
      | otherwise = case start of
          Nothing -> colop (Just x) (x+1) cnt res as
          Just x' -> colop Nothing (x+1) (cnt+x-x') (newRes x' x) as
      where a' | pos == Just x = a + 1
               | otherwise     = a
            newRes x1 x2 = B.append res (scmd [[y,t,y,t+1] | t <- [x1..x2-1]])

scmd :: [[Int]] -> B.ByteString
scmd = B.unlines . map (B.unwords . map (B.pack . show))

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let [h, w] : ass = map bsReadInts (B.lines cont)
      (n, bs) = solve h w ass
  putStrLn (show n)
  B.putStr bs
