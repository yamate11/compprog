import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [Int] -> Int
solve n x as = if k < n then k
               else if sum as == x then n
                    else (n-1)
  where
    os = sort as
    sums = scanl1 (+) os
    k = length $ takeWhile (<= x) sums


bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> Int
tmain cont =
  let n : x : as = bsReadInts cont
  in solve n x as

main = putStrLn . show . tmain =<< B.getContents

inp1 = "\
\3 70\n\
\20 30 10\n\
\"

inp2 = "\
\3 10\n\
\20 30 10\n\
\"

inp3 = "\
\4 1111\n\
\1 10 100 1000\n\
\"

inp4 = "\
\2 10\n\
\20 20\n\
\"


tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4


test1 = tv1 == 2
test2 = tv2 == 1
test3 = tv3 == 4
test4 = tv4 == 0

alltest = test1 && test2 && test3 && test4

