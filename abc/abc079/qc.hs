opcomb :: [[Char]]
opcomb = sub 3
  where
    sub :: Int -> [[Char]]
    sub 0 = [[]]
    sub n = ['+' : x | x <- sub (n - 1)] ++ ['-' : x | x <- sub (n - 1)]

solve :: [Int] -> String
solve ns = fuse ns ops0
  where
    ops0 :: [Char]
    ops0 = head (filter check opcomb)
    n0 : ns0 = ns
    check :: [Char] -> Bool
    check ops = (check1 n0 ns0 ops) == 7
    check1 :: Int -> [Int] -> [Char] -> Int
    check1 acc [] [] = acc
    check1 acc (n : ns) ('+' : ops) = check1 (acc + n) ns ops
    check1 acc (n : ns) ('-' : ops) = check1 (acc - n) ns ops
    fuse :: [Int] -> [Char] -> String
    fuse (n:ns') (op:ops') = (show n) ++ (op : fuse ns' ops')
    fuse [n] [] = show n ++ "=7"

main :: IO ()
main = do
  cont <- getContents
  let [strQ] = words cont
      ns = map (\c -> read [c]) strQ
  putStrLn (solve ns)
