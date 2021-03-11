import qualified Data.IntMap as IM

solve :: Int -> [[Int]] -> (Int,Int,Int)
solve n xyhs =
  case [(x,y,h) | [x,y,h] <- xyhs, h > 0] of
    pos : _ -> solve1 pos xyhs
    [] -> solve2 xyhs

solve1 :: (Int,Int,Int) -> [[Int]] -> (Int,Int,Int)
solve1 (x0,y0,h0) xyhs = head $ foldr f initCands xyhs
  where
    initCands = [(cx, cy, h0 + (abs (x0 - cx)) + (abs (y0 - cy)))
                   | cx <- [0..100], cy <- [0..100]]
    f :: [Int] -> [(Int,Int,Int)] -> [(Int,Int,Int)]
    f [x,y,h] = filter ff
      where ff (cx, cy, ch) = height cx cy ch x y == h

solve2 :: [[Int]] -> (Int,Int,Int)
solve2 xyhs = head $ [(x,y,1) | x <- [0..100], y <- [0..100],
                                IM.notMember (enc (x,y)) mp]
  where mp = foldr f IM.empty xyhs
          where f [x,y,_] imap = IM.insertWith (+) (enc (x,y)) 1 imap

enc (x,y) = 101*x + y
       
height cx cy ch x y = max (ch - (abs (x - cx)) - (abs (y - cy))) 0


main = do
  cont <- getContents
  let [n] : xyhs = map (map read . words) (lines cont)
      (cx, cy, ch) = solve n xyhs
  putStrLn (show cx ++ " " ++ show cy ++ " " ++ show ch)
