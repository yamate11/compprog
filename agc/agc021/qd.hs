import qualified Data.Vector as V

solve :: String -> Int -> Int
solve valS valK = dp 0 lenS valK
  where
    lenS = length valS
    vecS = V.fromList valS

    dp :: Int -> Int -> Int -> Int
    dp st 0 n = 0
    dp st 1 n = 1
    dp st len n
      | vecS V.! st == vecS V.! (st+len-1) =
                    max shorter (2 + ds V.! (idx (st+1, len-2, n  )))
      | n > 0     = max shorter (2 + ds V.! (idx (st+1, len-2, n-1)))
      | otherwise =     shorter
      where shorter = max (ds V.! (idx (st, len-1, n)))
                          (ds V.! (idx (st+1, len-1, n)))

    ds = V.fromList 
           [dp st len n | st <- [0..lenS-1],
                          len <- [0..lenS],
                          n <- [0..valK]]

    idx (st, len, n) = (st * (lenS+1) + len) * (valK + 1) + n

main :: IO ()
main = do
  cont <- getContents
  let [valS, kk] = words cont
      valK = read kk
      answer = solve valS valK
  putStrLn (show answer)
