import Data.List

main :: IO ()
main = do
  line1 : c_board <- return . lines =<< getContents
  let [h, w] = map read (words line1)
      board = map (map (== '#')) c_board
      blankRow = take w (repeat False)
      brdU = blankRow : init board
      brdD = tail board ++ [blankRow]
      brdR = map (\x -> False : init x) board
      brdL = map (\x -> tail x ++ [False]) board
      jdg = all f $ transpose (map concat [board, brdU, brdD, brdR, brdL])
  putStrLn (if jdg then "Yes" else "No")

  where f (x : bs) = not x || any id bs
