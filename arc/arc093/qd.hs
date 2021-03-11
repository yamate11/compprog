main = do
  cont <- getContents
  let [a, b] = map read $ words cont
      (h, w, answer) = solve a b
  putStrLn $ (show h) ++ " " ++ (show w)
  putStrLn $ unlines answer

halfNC = 50

solve :: Int -> Int -> (Int, Int, [String])
solve a b =
  let (ca, ra) = divMod (a-1) halfNC
      (cb, rb) = divMod (b-1) halfNC
  in (2*(1+ca+1+cb), 2*halfNC,
      sub ca ra '.' '#' ++ reverse (sub cb rb '#' '.'))

sub :: Int -> Int -> Char -> Char -> [String]
sub comp rem thisC thatC =
  remRows rem thisC thatC ++ compRows comp thisC thatC

remRows :: Int -> Char -> Char -> [String]
remRows rem thisC thatC =
  [ take (2 * rem) (cycle [thisC, thatC])
    ++ take (2 * (halfNC - rem)) (cycle [thatC, thatC])
  , take (2 * halfNC) $ repeat thatC
  ]

compRows :: Int -> Char -> Char -> [String]
compRows comp thisC thatC =
  take (2 * comp) $ cycle (f thisC thatC)
  where
    f thisC thatC = [ take (2 * halfNC) $ cycle [thisC, thatC]
                    , take (2 * halfNC) $ repeat thatC
                    ]
