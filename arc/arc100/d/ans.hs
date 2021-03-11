import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import Debug.Trace

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve _ as@(a:as') = subproc sum0 as as as' 0 0 a sum0
  where sum0 = sum as

subproc mindiff [_] _ _ _ _ _ _ = mindiff
subproc mindiff (a:as) ps qs s1 s2 s3 s4 =
  subproc newmindiff as ps' qs' s1' s2' s3' s4'
  where
    s2' = s2 + a
    (s1', ps') = newdiv s1 s2' ps
    s4' = s4 - a
    (s3', qs') = newdiv (s3 - a) s4' qs
    a_min = minimum [s1', s2'-s1', s3', s4'-s3']
    a_max = maximum [s1', s2'-s1', s3', s4'-s3']
    newmindiff = min mindiff (a_max - a_min)
  
newdiv sLeft sAll xs = (u, v)
  where
    sums = takeWhile (\s -> 2*s <= sAll - 2*sLeft)
           $ tail $ scanl' (+) 0 xs
    n1 = length sums
    sL | null sums = sLeft
       | otherwise = sLeft + last sums
    x' : xs' = drop n1 xs
    sR = sAll - (sL + x')
    (u, v) = if sL < sR then (sL + x', xs') else (sL, x' : xs')

tmain cont =
  let n : as = bsReadInts cont
  in solve n as

main = putStrLn . show . tmain =<< B.getContents

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3

test1 = tv1 == 2
test2 = tv2 == 36
test3 = tv3 == 999999994
alltest = test1 && test2 && test3

inp1 = "\
\5\n\
\3 2 4 1 2\n\
\"

inp2 = "\
\10\n\
\10 71 84 33 6 47 23 25 52 64\n\
\"

inp3 = "\
\7\n\
\1 2 3 1000000000 4 5 6\n\
\"
