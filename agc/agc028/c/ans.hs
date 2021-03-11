{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntSet as IS

solve :: Int -> [Int] -> Int
solve n xs = minimum [sumA, sumB, sumM]
  where
    ys = addlab 0 xs
    (as, bs) = partition ((== 'a') . getT) ys
    sumA = sum $ map getX as
    sumB = sum $ map getX bs
    (smalls, bigs) = splitAt n $ sort $ ys
    isDup = n > (IS.size $ IS.fromList $ map getI smalls)
    sumSmalls = sum $ map getX smalls
    (xP1,iP1,_):(xP2,_,_):_ = bigs
    (xQ1,iQ1,_):(xQ2,_,_):_ = reverse smalls
    sumM = sumSmalls + diff
    diff | isDup      = 0
         | iP1 /= iQ1 = xP1 - xQ1
         | otherwise  = min (xP2 - xQ1) (xP1 - xQ2)

addlab _ [] = []
addlab !i (x1:x2:xs) = (x1,i,'a'):(x2,i,'b'):(addlab (i+1) xs)

getX (x,_,_) = x
getI (_,i,_) = i
getT (_,_,t) = t

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> Int
tmain cont =
  let n : xs = bsReadInts cont
  in solve n xs

main = putStrLn . show . tmain =<< B.getContents

inp1 = "\
\3\n\
\1 5\n\
\4 2\n\
\6 3\n\
\"

inp2 = "\
\4\n\
\1 5\n\
\2 6\n\
\3 7\n\
\4 8\n\
\"

inp3 = "\
\6\n\
\19 92\n\
\64 64\n\
\78 48\n\
\57 33\n\
\73 6\n\
\95 73\n\
\"

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

test1 = tv1 == 7
test2 = tv2 == 10
test3 = tv3 == 227

alltest = test1 && test2 && test3

