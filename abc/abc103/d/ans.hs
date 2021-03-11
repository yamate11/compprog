{-
This code was written after reading the editorial.
-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [[Int]] -> Int
solve n m abs = count $ trim $ map head
                   $ groupBy (\[a1,_] [a2,_] -> a1 == a2) $ sort abs

trim :: [[Int]] -> [[Int]]
trim [] = []
trim [x] = [x]
trim ([a1,b1] : sabs)
  | b1 >= b2 = sabs'
  | otherwise = [a1,b1] : sabs'
  where sabs'@([_,b2] : _) = trim sabs

count :: [[Int]] -> Int
count = sum . unfoldr f
  where
    f [] = Nothing
    f ([a,b] : sabs) = Just (1, remove b sabs)
      where remove b [] = []
            remove b all@([a1,b1] : sabs) | b <= a1 = all
                                          | otherwise = remove b sabs

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let [n, m] : abs = map bsReadInts (B.lines conts)
      answer = solve n m abs
  putStrLn (show answer)
