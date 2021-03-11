import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe


bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> [Int] -> [Int]
solve valK as =
  case foldr op (Just (2, 2)) as of
    Just (x, y) -> [x, y]
    Nothing     -> [-1]
  where
    op _ Nothing = Nothing
    op a (Just (minX, maxX)) | a1 <= a2 = Just (a1, a2 + a - 1)
                             | otherwise = Nothing
      where a1 = a * ((minX + a - 1) `div` a)
            a2 = a * (maxX `div` a)
      

main :: IO ()
main = do
  conts <- B.getContents
  let valK : as = bsReadInts conts
      answer = solve valK as
  putStrLn $ unwords $ map show answer
