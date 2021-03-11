import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM

solve :: [Int] -> Int
solve (n:as) =
  foldr (\x a -> a + x*(x-1) `div` 2) 0 $
        foldr (IM.alter upd) IM.empty $
              scanl (+) 0 as
  where
    upd Nothing  = Just 1
    upd (Just c) = Just (c+1)

main = putStrLn . show . solve . map (fst . fromJust . B.readInt) . B.words
         =<< B.getContents
