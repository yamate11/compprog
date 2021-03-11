import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> Int -> (Int, Int, Int)
solve valN valY =
  case dropWhile (== Nothing) $ map solveS [0 .. valN] of
    [] -> (-1, -1, -1)
    (Just a) : _ -> a
  where
    solveS :: Int -> Maybe (Int, Int, Int)
    solveS x =
      if 0 <= y && y <= valN && 0 <= z && z <= valN &&
         10000 * x + 5000 * y + 1000 * z == valY
      then Just (x, y, z)
      else Nothing
      where
        rhs = (valY - 10000 * x) - 1000 * (valN - x)
        y = rhs `div` 4000
        z = valN - x - y

main :: IO ()
main = do
  conts <- B.getContents
  let [valN, valY] = bsReadInts conts
      (x, y, z) = solve valN valY
  putStrLn $ show x ++ " " ++ show y ++ " " ++ show z
  
