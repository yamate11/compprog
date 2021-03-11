solve a b =
  if (a <= 8) && (b <= 8) then "Yay!" else ":("

main = do
  conts <- getContents
  let [a,b] = map read $ words conts
      answer = solve a b
  putStrLn answer
