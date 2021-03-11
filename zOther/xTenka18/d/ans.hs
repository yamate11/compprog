{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

solve :: Int -> Maybe (Int, [[Int]])
solve n = do
  k <- getK n
  return $ (k, map (((k-1):) . aSet k) [0..k-1])
  where
    aSet k p = [p0+1 .. p0+p] ++ [toSum (j-1) + p + 1 | j <- [p+1 .. k-1]]
      where p0 = toSum (p-1)

toSum x = x * (x+1) `div` 2  

getK :: Int -> Maybe Int
getK n = let k = ceiling (sqrt (fromIntegral (2*n)))
         in if k*(k-1) == 2*n then Just k
            else if (k+1)*k == 2*n then Just (k+1)
                 else Nothing

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe (Int, [[Int]])
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
  in solve n

outAnswer :: Maybe (Int, [[Int]]) -> IO ()
outAnswer Nothing = putStrLn "No"
outAnswer (Just (n, xs)) = do
  putStrLn "Yes"
  putStrLn (show n)
  putStr (unlines (map (unwords . map show) xs))

main :: IO ()
main = outAnswer . tmain =<< B.getContents

