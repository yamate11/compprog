import Data.List

solve :: Int -> String -> String
solve _ s = foldr1 f $ map solveB (mkBlocks s)
  where
    f s1 s2 | cmpless s1 s2 = s2
            | otherwise     = s1 ++ s2

cmpless (x : s) (y : t) | x == y = cmpless s t
                        | otherwise = x < y
cmpless _ _ = False                        

mkBlocks = unfoldr f
  where 
    f "" = Nothing
    f s@(c:_) = let cnts = (takeWhile (> 0) (tail (scanl' g 0 s))) ++ [0]
                    (s1, s2) = splitAt (length cnts) s
                in Just $ ((s1, cnts), s2)
      where g n c' | c' == c   = n + 1
                   | otherwise = n - 1

solveB (s@('a':_), _) = take (2*count) $ cycle "ab"
  where
    count = sub 0 0 0 s

    sub ia ib cnt [] = cnt
    sub ia ib cnt ('a':s) = sub2 ia (ia+1) ib cnt s
    sub ia ib cnt ('b':s) = sub ia (ib+1) cnt s

    sub2 ga ia ib cnt ('a':s) = sub2 ga (ia+1) ib cnt s
    sub2 ga ia ib cnt ('b':s) | ga == ib = sub ia (ib+1) (cnt+1) s
                              | otherwise = sub2 ga ia (ib+1) cnt s

solveB (s@('b':_), cnts) =
  maximum [take cmax (repeat 'b') ++ drop i s
          | (i, cnt) <- zip [1..] cnts, cnt == cmax]
  where
    cmax = maximum cnts

main = do
  cont <- getContents
  let [sn, s] = words cont
  putStrLn $ solve (read sn) s



test1 = solve 3 "aababb" == "abab"
test2 = solve 3 "bbabaa" == "bbabaa"
test3 = solve 6 "bbbaabbabaaa" == "bbbabaaa"
test4 = solve 9 "abbbaababaababbaba" == "bbaababababa"
test5 = solve 2 "abab" == "abab"

alltest = test1 && test2 && test3 && test4 && test5

naive :: Int -> String -> String
naive n s = maximum [appchfn chfn spos | chfn <- power n]
  where
    spos = mkpos 0 0 s

    mkpos na nb [] = []
    mkpos na nb ('a':s) = ('a', na) : mkpos (na+1) nb s
    mkpos na nb ('b':s) = ('b', nb) : mkpos na (nb+1) s

    pwr = power n

    power 0 = [[]]
    power n = concat [[False:x, True:x] | x <- power (n-1)]

    appchfn chfn [] = ""
    appchfn chfn ((c,n) : sp) | chfn !! n = c : appchfn chfn sp
                              | otherwise =     appchfn chfn sp

enum :: Int -> [String]
enum n = sub (take n (repeat 'a')) (take n (repeat 'b'))
  where
    sub "" s = [s]
    sub s "" = [s]
    sub (c1:s1) (c2:s2) = [c1:s | s <- sub s1 (c2:s2)] ++
                          [c2:s | s <- sub (c1:s1) s2]

check :: Int -> [String]
check n = [s | s <- enum n, naive n s /= solve n s ]



