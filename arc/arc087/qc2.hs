import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe
import qualified Data.Map.Strict as M

solve :: [Int] -> Int
solve ns =
  M.foldlWithKey' f 0 (foldr (M.alter af) M.empty ns)
  where
    f sum n size = sum + if size >= n then size - n else size
    af Nothing = Just 1
    af (Just x) = Just (x + 1)
  
main :: IO ()
main = putStrLn . show . solve .
       map (fst . fromJust . B.readInt) .
       tail . B.words =<< B.getContents
