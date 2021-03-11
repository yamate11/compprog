import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [Int] -> Int
solve n bigX xs = cost n bigX rs d0
  where
    rs = reverse xs
    d0 = if n <= 2 then 1
         else if cost n bigX rs 1 < cost n bigX rs 2 then 1
              else search n bigX rs 1 (n-1)

cost :: Int -> Int -> [Int] -> Int -> Int
cost n bigX rs d = bigX * (n + d)
                   + (sum $ zipWith (*) (5 : [5,7..]) (gsumA d n rs))

-- gsum d rs = gsumA d (length rs) rs

gsumA :: Int -> Int -> [Int] -> [Int]
gsumA d k rs | k <= d = [sum rs]
             | otherwise = (sum rs1) : gsumA d (k-d) rs2
  where (rs1, rs2) = splitAt d rs

search :: Int -> Int -> [Int] -> Int -> Int -> Int
search n bigX rs low high
  | high == low + 1 = high
  | theCost mid < theCost (mid+1) = search n bigX rs low mid
  | otherwise                     = search n bigX rs mid high
  where
    theCost d = cost n bigX rs d
    mid = (low + high) `div` 2

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> Int
tmain cont =
  let n : bigx : xs = bsReadInts cont
  in solve n bigx xs

main = putStrLn . show . tmain =<< B.getContents

inp1 = "\
\2 100\n\
\1 10\n\
\"

inp2 = "\
\5 1\n\
\1 999999997 999999998 999999999 1000000000\n\
\"

inp3 = "\
\10 8851025\n\
\38 87 668 3175 22601 65499 90236 790604 4290609 4894746\n\
\"

inp4 = "\
\16 10\n\
\1 7 12 27 52 75 731 13856 395504 534840 1276551 2356789 9384806 19108104 82684732 535447408\n\
\"

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4

test1 = tv1 == 355
test2 = tv2 == 19999999983
test3 = tv3 == 150710136
test4 = tv4 == 3256017715

alltest = test1 && test2 && test3 && test4
