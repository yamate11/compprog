import Data.List

main = do
  cont <- getContents
  let [bigN,bigT] : cts = map (map read . words) $ lines cont
      red = [(c,t) | [c,t] <- cts, t <= bigT]
      (c0, t0) = foldr f (0, bigT+1) red
  if t0 <= t then putStrLn (show c0) else putStrLn "TLE"
  where
    f :: [Int] -> [Int] -> [Int]
    f [c, t] [c1, t1] | c < c1 = [c, t]
                      | otherwise = [c1, t1]
