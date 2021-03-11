import Data.List

solve a b c =
  let [x,y,z] = sort [a,b,c]
  in 10*z+y+x

main = do
  cont <- getContents
  let [a,b,c] = map read $ words cont
      n = solve a b c
  putStrLn $ show n
