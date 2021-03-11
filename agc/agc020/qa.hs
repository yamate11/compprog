solve :: Int -> Int -> Int -> String
solve _ a b = if (a - b) `mod` 2 == 0 then "Alice" else "Borys"


main :: IO ()
main = do
  conts <- getContents
  let [valN, valA, valB] = map read (words conts)
      answer = solve valN valA valB
  putStrLn answer
