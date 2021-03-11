import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List

solve :: [Int] -> Int
solve (valN : as) = head (filter (testBit set) [half..])
  where half = ((sum as) + 1) `div` 2
        set :: Integer
        set = foldl' (\x a -> x .|. (shiftL x a)) (bit 0) as

main :: IO ()
main = putStrLn . show . solve .
         map (fst . fromJust . B.readInt) . B.words =<< B.getContents
