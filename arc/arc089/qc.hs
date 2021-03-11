import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List


bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> [[Int]] -> String
solve _ txys = if res then "Yes" else "No"
  where
    res = foldl' (&&) True $ zipWith f ([0, 0, 0] : txys) txys
      where
        f [n1, x1, y1] [n2, x2, y2] = judge
          where
            elapsed = n2 - n1
            dist = abs (x2 - x1) + abs (y2 - y1)
            judge = dist <= elapsed && (elapsed - dist) `mod` 2 == 0

main :: IO ()
main = do
  conts <- B.getContents
  let ([n] : txys) = map bsReadInts (B.lines conts)
      answer = solve n txys
  putStrLn answer
