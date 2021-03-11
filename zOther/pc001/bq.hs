import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: [[Int]] -> String
solve [[n], as, bs] =
  if aN >= bN then "Yes" else "No"
  where
    (aN, bN) = foldl' g (0, 0) $ zipWith f as bs
    f a b | a >= b = (0, a - b)
          | a < b && (rem == 0) = (quo, 0)
          | a < b && (rem == 1) = (quo, 1)
      where rem = (b - a) `mod` 2
            quo = (b - a + 1) `div` 2
    g (a1, b1) (a2, b2) = (a1 + a2, b1 + b2)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let answer = solve (map bsReadInts (B.lines conts))
  putStrLn answer
  
