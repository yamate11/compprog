import Data.Maybe
import Data.List

solve :: Int -> Int -> String -> String -> Int
solve n m s t = ans
  where
    g = gcd n m
    lcm = n * m `div` g
    s' = perc (n `div` g) s
    t' = perc (m `div` g) t
    ans | s' == t' = lcm
        | otherwise = -1

perc k "" = ""
perc k (c:str) = c : perc k (drop (k-1) str)


tmain :: String -> Int
tmain cont =
  let [sn, sm, s, t]  = words cont
      n = read sn
      m = read sm
  in solve n m s t

main = putStrLn . show . tmain =<< getContents

----------------------------------------------------------------------

inp1 = "\
\3 2\n\
\acp\n\
\ae\n\
\"

inp2 = "\
\6 3\n\
\abcdef\n\
\abc\n\
\"

inp3 = "\
\15 9\n\
\dnsusrayukuaiia\n\
\dujrunuma\n\
\"

{-
inp4 = "\
\2 10\n\
\20 20\n\
\"
-}

tv1 = tmain $ inp1
tv2 = tmain $ inp2
tv3 = tmain $ inp3
-- tv4 = tmain $ B.pack inp4


test1 = tv1 == 6
test2 = tv2 == -1
test3 = tv3 == 45
-- test4 = tv4 ==

alltest = test1 && test2 && test3 -- && test4

