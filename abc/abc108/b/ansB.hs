solve [x1,y1,x2,y2] = [x3,y3,x4,y4]
  where
    [vx,vy] = [x2-x1, y2-y1]
    [x3,y3] = zipWith (+) [x2,y2] [-vy,vx]
    [x4,y4] = zipWith (+) [x3,y3] [-vx,-vy]

main = do
  cont <- getContents
  let xy = map read $ words cont
      a = solve xy
  putStrLn $ unwords $ map show a
