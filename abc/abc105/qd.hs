import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM
import Data.List

bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve n m as = sum $ map g $ IM.toList im
  where
    g (_,c) = (c*(c-1)) `div` 2
    accs = scanl' op 0 as
      where op a1 a2 = (a1 + a2) `mod` m
    im = foldr (IM.alter f) IM.empty accs
      where f Nothing = Just 1
            f (Just a) = Just (a+1)

tmain cont =
  let n : m : as = bsReadInts cont
  in solve n m as

main = putStrLn . show . tmain =<< B.getContents

test1 = tv1 == 3
test2 = tv2 == 6
test3 = tv3 == 25
alltest = test1 && test2 && test3

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

inp1 = "\
\3 2\n\
\4 1 5\n\
\"

inp2 = "\
\13 17\n\
\29 7 5 7 9 51 7 13 8 55 42 9 81\n\
\"

inp3 = "\
\10 400000000\n\
\1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000\n\
\"
