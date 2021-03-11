import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

----------------------------------------------------------------------

solve :: Int -> Int -> Int
solve n i = n - i + 1

tmain :: B.ByteString -> Int
tmain cont =
  let [n, i] = bsReadInts cont
  in solve n i

main = putStrLn . show . tmain =<< B.getContents
  


inp1 = "\
\4 2\n\
\"

inp2 = "\
\1 1\n\
\"

inp3 = "\
\15 11\n\
\"

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

test1 = tv1 == 3
test2 = tv2 == 1
test3 = tv3 == 5
alltest = test1 && test2 && test3
