import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

count1 :: Int -> Int
count1 i | i `mod` 2 == 0 = 1 + count1 (i `div` 2)
         | otherwise      = 0

solve :: Int -> [Int] -> Int
solve n as =
  sum $ map count1 as

main :: IO ()
main = do
  conts <- B.getContents
  let n : as = bsReadInts conts
      answer = solve n as
  putStrLn (show answer)
