import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe

solve :: [Int] -> Int
solve ns = sum $ map toBeReduced $ group $ sort ns
  where
    toBeReduced grp = if size >= n then size - n else size
      where size = length grp
            n = head grp

main :: IO ()
main = putStrLn . show . solve .
       map (fst . fromJust . B.readInt) .
       tail . B.words =<< B.getContents
