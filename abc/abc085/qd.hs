import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> Int -> [[Int]] -> Int
solve valN valH rests =
  case [(i, sum) | (i, sum) <- sc, sum >= valH] of
    (ans, _) : _ -> ans
    [] -> (length effBs) + (((valH - lastsum) + (amax - 1)) `div` amax)
  where
    bs = reverse $ sort $ map (\[a, b] -> b) rests
    as = map (\[a, b] -> a) rests
    amax = maximum (traceQ "as" as)
    effBs = takeWhile (> amax) (traceQ "bs" bs)
    sc = scanl' op (0, 0) effBs
      where op (i, sum) h = (i + 1, sum + h)
    lastsum = snd $ last sc

main :: IO ()
main = do
  conts <- B.getContents
  let fstLine : restLines = B.lines conts
      [valN, valH] = bsReadInts fstLine
      rests = map bsReadInts restLines
      x = solve valN valH rests
  putStrLn $ show x
  
