{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

type Mms = (Int, Int, Int, Int)
--          min, max, shift, direction

bound :: Int -> Int -> Int -> Int
bound lower upper = min upper . max lower

diffP :: Int -> Int -> Int -> Int -> (Int, Int)
diffP dead avail shift time = (newD, newS)
  where newD = bound dead avail (time - shift)
        newS = max (-avail) (shift - time)

mmsUpd :: Int -> Int -> Mms -> Mms
mmsUpd valX r (deadL, deadH, shift, -1) = (nD, deadH, nS, 1)
  where (nD, nS) = diffP deadL (valX - deadL - deadH) shift r
mmsUpd valX r (deadL, deadH, shift,  1) = (deadL, nD, -nS, -1)
  where (nD, nS) = diffP deadH (valX - deadL - deadH) (-shift) r

duf :: forall a b. (Ord a) => (b -> a) -> [a] -> [b] -> [b]
duf f as bs = map (fst . head) $ tail $ scanl op bts0 as
  where 
    bts0 :: [(b, [b])]
    bts0 = zip bs (tails bs)
    op :: [(b, [b])] -> a -> [(b, [b])]
    op [bt] _ = [bt]
    op bts a = dropWhile ((>= a) . f . head . snd) bts

solve :: Int -> Int -> [Int] -> Int -> [[Int]] -> [Int]
solve valX valK rs valQ tas = vals

  where
    states = scanl op (0, (0, 0, 0, -1)) rs
      where op (t, mms) r = (r, mmsUpd valX (r - t) mms)

    valueA :: Int -> Mms -> Int -> Int
    valueA t (deadL, deadH, shift, dir)
      = bound 0 valX . (+ t*dir) . (+ shift) . bound (0 + deadL) (valX - deadH)

    vals = zipWith f tas $ duf fst ts states
      where ts = map (\[t,_] -> t) tas
            f [t,a] (r,mms) = valueA (t - r) mms a

main :: IO ()
main = do
  conts <- B.getContents
  let [valX] : [valK] : rs : [valQ] : tas = map bsReadInts (B.lines conts)
      answer = solve valX valK rs valQ tas
  putStr $ unlines $ map show answer
