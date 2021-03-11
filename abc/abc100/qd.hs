import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> Int -> [Int] -> [Int] -> [Int] -> Int
solve n m xs ys zs =
  maximum [f a b c | a <- [1,-1], b <- [1,-1], c <- [1,-1]]
  where
    f :: Int -> Int -> Int -> Int
    f a b c  =
      sum $ take m $ reverse $ sort $ zipWith3 h (g a xs) (g b ys) (g c zs)
    g a xs = map (* a) xs
    h p q r = p + q + r

main :: IO ()
main = do
  conts <- B.getContents
  let [n, m] : xyzs = map bsReadInts (B.lines conts)
      [xs, ys, zs] = transpose xyzs
      answer = solve n m xs ys zs
  putStrLn (show answer)
