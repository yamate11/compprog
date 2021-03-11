import Data.Bits
import Debug.Trace

move :: Int -> (Int, Integer) -> (Int, Integer)
move amount (offset, places) =
  (offset - amount, places .|. (shiftL places (2 * amount)))

toNums :: String -> [Int]
toNums s = let (fs, rem) = span (== 'F') s
               n = length fs
           in case rem of
                []       -> [n]
                t : rem' -> n : toNums rem'

eoDiv :: [a] -> ([a], [a])
eoDiv = foldr (\a (xs, ys) -> (a : ys, xs)) ([], [])

toPlaces :: Int -> [Int] -> (Int, Integer)
toPlaces p0 = foldr move (p0, 1)

solve :: String -> Int -> Int -> String
solve commands x0 y0 =
  let fstX : numsYX = toNums commands
      (numsY, numsX) = eoDiv numsYX
      (xOffset, xPlaces) = toPlaces fstX numsX
      (yOffset, yPlaces) = toPlaces 0 numsY
  in if testBit xPlaces (x0 - xOffset) && testBit yPlaces (y0 - yOffset)
     then "Yes" else "No"

main :: IO ()
main = do
  cont <- getContents
  let [com, sx0, sy0] = words cont
  putStrLn $ solve com (read sx0) (read sy0)

