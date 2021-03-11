import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

solve :: Int -> [[Int]] -> (Int, [Int], [String])
solve n xys
  | check rem rest = solve0 rem n xys
  | otherwise = (-1, [], [])
  where
    [x0,y0] : rest = xys
    rem = (x0 + y0) `mod` 2

check :: Int -> [[Int]] -> Bool  
check rem xys = all (\[x,y] -> (x+y) `mod` 2 == rem) xys

solve0 rem n xys = (m, ds, ws)
  where
    m | rem == 0 = 40
      | rem == 1 = 39

    ds = take m $ repeat 1

    ws = map f xys
      where
        f [x,y]
          | -10 <= x && x <= 10 && -10 <= y && y <= 10 = g x y
          | otherwise = ""

        g x y = horiz ++ vert ++ rest
          where
          horiz | x > 0 = take x $ repeat 'R'
                | x < 0 = take (-x) $ repeat 'L'
                | x == 0 = ""

          vert | y > 0 = take y $ repeat 'U'
               | y < 0 = take (-y) $ repeat 'D'
               | y == 0 = ""

          rest = take (m - ((abs x) + (abs y))) $ cycle "RL"

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let [n] : xys = map bsReadInts (B.lines conts)
      (m, ds, ws) = solve n xys
  if m < 0 then putStrLn "-1"
    else do
    putStrLn $ show m
    putStrLn $ unwords $ map show ds
    putStr $ unlines ws  
