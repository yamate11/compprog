import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

----------------------------------------------------------------------

solve :: Int -> Int -> [Int] -> Int
solve n k xs = minimum $ zipWith f xs (drop (k-1) xs)
  where
    f p q | q <= 0 = -p
          | p >= 0 = q
          | q <= (-p) = 2 * q + (-p)
          | (-p) <= q = 2 * (-p) + q
    

tmain :: B.ByteString -> Int
tmain cont =
  let n : k : xs = bsReadInts cont
  in solve n k xs

main = putStrLn . show . tmain =<< B.getContents
  


inp1 = "\
\5 3\n\
\-30 -10 10 20 50\n\
\"

inp2 = "\
\3 2\n\
\10 20 30\n\
\"

inp3 = "\
\1 1\n\
\0\n\
\"

inp4 = "\
\8 5\n\
\-9 -7 -4 -3 1 2 3 4\n\
\"

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4

test1 = tv1 == 40
test2 = tv2 == 20
test3 = tv3 == 0
test4 = tv4 == 10
alltest = test1 && test2 && test3 && test4
