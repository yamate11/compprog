solve :: Int -> (Int, Int, [[Int]])
solve 1 = (1, 0, [])
solve l
  | l `mod` 2 == 0 =
    let (n, m, uvws) = solve (l `div` 2)
    in (n+1, m+2, [1,2,0] : [1,2,1] : map (\[u,v,w] -> [u+1,v+1,2*w]) uvws)
  | otherwise =
    let (n,m,uvws) = solve (l - 1)
    in (n, m+1, [1,n,l-1] : uvws)

main = do
  cont <- getContents
  let (n, m, uvws) = solve $ read cont
  putStr $ unlines $ map (unwords . map show) $ [n, m] : uvws
