import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [Int] -> Int
solve n start xs = foldl1' gcd $ map op xs
  where op x = abs(x - start)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  cont <- B.getContents
  let n : start : xs = bsReadInts cont
  putStrLn $ show $ solve n start xs
