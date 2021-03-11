import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a
-- traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

-- connPart lfs start size == sublist of a1 ++ a2 ++ ... ++ an
-- from start with size size
-- for each ai, (li, fi) is given in lfs, where li is the size of
-- ai and fi start size  gives the sublist of ai from start with sie size.
-- Note that connPart [(length as, \x y -> drop x (take y as)) | as in ass] start size == drop start (take size (concat ass))
connPart :: [(Int, Int -> Int -> [a])] -> Int -> Int -> [a]
connPart lfs start size =
  let cumList = dropWhile (\(cum, (sz, _)) -> cum + sz <= start)
                   $ zip (scanl (+) 0 (map fst lfs)) lfs 
  in case cumList of
  []                      -> []
  (cs1, (s1, f1)) : clfs2 -> res1 ++ res2
    where
      off1 = start - cs1
      sz1 = min (s1 - off1) size
      res1 = f1 off1 sz1
      lfs2 = map snd clfs2
      clfs3 = takeWhile ((> 0) . fst)
                $ zip (scanl (-) (size - sz1) (map fst lfs2)) lfs2
      res2 = concatMap (\(remS, (sz, f)) -> f 0 (min sz remS)) clfs3

lFloor len i = len * (i `div` len)
-- lCeil  len i = lFloor len (i + len - 1)

test0 :: Int -> Int -> (Int, Int -> Int -> [Int])
test0 a b = (b, test1 a)

test1 :: Int -> Int -> Int -> [Int]
test1 a x y = [(a + x) .. (a + x + y - 1)]

solve :: Int -> [[Int]] -> [String]
solve _ = map eSolve 

ecase c1 c2 valC valD =
  take (valD - valC + 1) $ cycle [d1, d2]
  where (d1,d2) = if valC `mod` 2 == 1 then (c1,c2) else (c2,c1)

chars :: Char -> Int -> String
chars c len = if len > 0 then take len (repeat c) else ""

eSolve :: [Int] -> String
eSolve [valA,valB,valC,valD] 
  | valA == valB || valA == valB + 1 = ecase 'A' 'B' valC valD
  |                 valB == valA + 1 = ecase 'B' 'A' valC valD
  | otherwise = connPart partsDef (valC - 1) (valD - valC + 1)
  where
    bLen = (long + ((short + 1) - 1)) `div` (short + 1)
      where long = max valA valB
            short = min valA valB
    pre  = (bLen * valA - valB) `div` ((bLen - 1) * (bLen + 1))
    post = (bLen * valB - valA) `div` ((bLen - 1) * (bLen + 1))
    midA = valA - (bLen * pre + post)
    midB = valB - (pre + bLen * post)
    partsDef :: [(Int, Int -> Int -> String)]
    partsDef = [((bLen + 1) * pre, extBoth bLen 1),
                (midA + midB, extBoth midA midB),
                ((bLen + 1) * post, extBoth 1 bLen)]

extBoth :: Int -> Int -> Int -> Int -> String
extBoth len1 len2 start size
  | len == 0 = ""
  | otherwise = concatMap getItvl [bStart, (bStart + len) .. bEndN]
  where
    len = len1 + len2
    endN = start + size
    bStart = lFloor len start
    bEndN =  lFloor len (endN - 1)
    getItvl :: Int -> String
    getItvl x = chars 'A' ((min len1 en) - st) ++
                chars 'B' (en - (max len1 st))
      where
        st = if x < start      then start - x else 0
        en = if endN < x + len then endN  - x else len




main :: IO ()
main = do
  conts <- B.getContents
  let [valQ] : qs = map bsReadInts (B.lines conts)
      answer = solve valQ qs
  putStr $ unlines $ answer
