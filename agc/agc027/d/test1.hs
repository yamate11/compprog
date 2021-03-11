import Data.List

check xs = check1 xs && check2 yss && check3 yss
  where yss = unfoldr f xs
          where f [] = Nothing
                f xs' = Just (splitAt 500 xs')

check1 xs = all f xs
  where f x = if x < 10^15 then True else error ("1 " ++ (show x))

checkA s yss = all f yss
  where f ys = and (zipWith g' ys (tail ys))
        g y1 y2 | y1 > y2 = y1 `mod` y2 == 1
                | y1 == y2 = False
                | otherwise = y2 `mod` y1 == 1
        g' y1 y2 | g y1 y2 = True
                 | otherwise = error (s ++ " " ++ show (y1, y2))

check2 yss = checkA "2" yss
check3 yss = checkA "3" (transpose yss)

main = do
  cont <- getContents
  let xs = words cont
      b = check (map read xs)
  if b then putStrLn "ok" else putStrLn "ng"
  
