{-
  This code was written after reading the editorial.
-}

import qualified Data.Vector.Unboxed as VU
import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

----------------------------------------------------------------------

solve :: Int -> [Int] -> Int
solve n as = binsearch n (VU.fromList (sort as)) as 0 n

binsearch n vec_a as p q
-- p: success, q: failure
  | p + 1 == q            = vec_a VU.! p
  | try (vec_a VU.! m) as = binsearch n vec_a as m q
  | otherwise             = binsearch n vec_a as p m
  where m = (p + q) `div` 2

try x as = cntIncPairs 
           $ scanl' (+) 0
           $ map (\a -> if x <= a then 1 else (-1)) as

cntIncPairs ys = let k = length ys
                     (cnt, _) = cip k ys
                 in ((k*(k-1) `div` 2) + 1) `div` 2 <= cnt

cip 1 ys = (0, ys)
cip 2 [y1, y2] | y1 <= y2  = (1, [y1, y2])
               | otherwise = (0, [y2, y1])
cip k ys = 
  let mz = k `div` 2
      mw = k - mz
      (zs, ws) = splitAt mz ys
      (znum, zssrt) = cip mz zs
      (wnum, wssrt) = cip mw ws
      (cnt, merged) = merge mz mw zssrt wssrt
  in (cnt + znum + wnum, merged)

merge 0 _ [] ws = (0, ws)
merge _ 0 zs [] = (0, zs)
merge mz mw ozs@(z:zs) ows@(w:ws)
  | z <= w    = (mw + z_cnt, z : z_merged)
  | otherwise = (     w_cnt, w : w_merged)
  where (z_cnt, z_merged) = merge (mz-1) mw zs ows
        (w_cnt, w_merged) = merge mz (mw-1) ozs ws

tmain :: B.ByteString -> Int
tmain cont =
  let n : as = bsReadInts cont
  in solve n as

main = putStrLn . show . tmain =<< B.getContents
  
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5

test1 = tv1 == 30
test2 = tv2 == 10
test3 = tv3 == 8
test4 = tv4 == 3
test5 = tv5 == 3
alltest = test1 && test2 && test3 && test4 && test5

inp1 = "\
\3\n\
\10 30 20\n\
\"

inp2 = "\
\1\n\
\10\n\
\"

inp3 = "\
\10\n\
\5 9 5 9 8 9 3 5 4 3\n\
\"

inp4 = "\
\4\n\
\1 2 3 4\n\
\"

inp5 = "\
\4\n\
\1 4 2 3\n\
\"

