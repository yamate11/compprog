solve :: [Int] -> Int
solve [] = 0
solve (n:ns) = let (ded,x) = solve1 ns
               in n - ded + x

solve1 [] = (0,0)
solve1 (n:ns) = let (ded,x) = solve1 ns
                in if (ded == 0 && n == 9) then (0, 9+x)
                   else (1, 9+x)


main :: IO ()
main = do
  cont <- getContents
  let [s] = words cont
  let ns = map (read . (\c -> [c])) s
  putStrLn (show (solve ns))
  
