{-# LANGUAGE ViewPatterns #-}
import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Data.Bits
import qualified Data.Map.Strict as M
import Data.Char
import Debug.Trace
import Data.Maybe

traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

lsbAdd :: Int -> Int
lsbAdd k = k + (k .&. (-k))

lsbOff :: Int -> Int
lsbOff k = k .&. complement (k .&. (-k))

bitSum :: VM.MVector s Int -> Int -> ST s Int
bitSum vec n = 
  foldM g 0 $ takeWhile (> 0) $ iterate lsbOff n
  where g sum i = (+ sum) <$> (VM.read vec (i - 1))

bitUpd :: Int -> VM.MVector s Int -> Int -> Int -> ST s ()
bitUpd nMax vec n diff = forM_ indices act
  where indices = takeWhile (<= nMax) (iterate lsbAdd (n + 1))
        act k = VM.modify vec (+ diff) (k - 1)

xchgCount :: [Int] -> Int
xchgCount ns =
  let nMax = bit $ ceiling $ logBase 2 $ fromIntegral $ length ns
      f vec acc n = do
        count <- bitSum vec n
        bitUpd nMax vec n 1
        return (acc + count)
  in runST $ do
    vec <- VM.replicate nMax 0
    foldM (f vec) 0 (reverse ns)


type MyMap = M.Map Char Int
type Ann = (Char, Int)

solve :: [Char] -> Int
solve s = either (const (-1)) id (actSolve s)
      
actSolve :: [Char] -> Either () Int
actSolve s = do
  let (anns, cMap) = annot s
  cOdd <- checkOdd cMap
  let (xchg1, pre, post) = divThree cOdd cMap anns
      xchg2 = xchgCount (mkOrder cMap (traceQ "pre" pre) (traceQ "post" post))
  return (xchg1 + xchg2)

annot :: [Char] -> ([Ann], MyMap)
annot s = annot1 s M.empty

annot1 :: [Char] -> MyMap -> ([Ann], MyMap)
annot1 [] cMap = ([], cMap)
annot1 (c:cs) cMap =
  let (i, cMap') = annLookup c cMap
      (result, cMap'') = annot1 cs cMap'
  in ((c, i) : result, cMap'')

annLookup :: Char -> MyMap -> (Int, MyMap)
annLookup c cMap = case M.lookup c cMap of
  Nothing -> (0, M.insert c 1 cMap)
  Just n  -> (n, M.adjust (+ 1) c cMap)

checkOdd :: MyMap -> Either () (Maybe Char)
checkOdd cMap = foldM op Nothing (M.keys cMap)
  where
    op :: Maybe Char -> Char -> Either () (Maybe Char)
    op mc1      (isEven -> True) = Right mc1
    op Nothing  c2               = Right (Just c2)
    op (Just _) _                = Left ()

    isEven :: Char -> Bool
    isEven c = (cMap M.! c) `mod` 2 == 0

divThree :: (Maybe Char) -> MyMap -> [Ann] -> (Int, [Ann], [Ann])
divThree cOdd cMap ann = (numXchg, pre, post)
  where
    (numXchg, _, _, pre, post) = sub cOdd cMap ann

    sub :: (Maybe Char) -> MyMap -> [Ann] -> (Int, Int, Int, [Ann], [Ann])
    sub cOdd cMap anns = foldr op (0, 0, 0, [], []) anns
      where
        op ann (numXchg, numPre, numMid, pre, post)
          | isPre ann = (numXchg, numPre + 1, numMid, ann : pre, post)
          | isMid ann = (numXchg + numPre, numPre, 1, pre, post)
          | otherwise = (numXchg + numPre + numMid, numPre, numMid, pre,
                         ann : post)

        isPre :: Ann -> Bool
        isPre (c, p) = p < midd c

        isMid :: Ann -> Bool
        isMid (c, p) = Just c == cOdd && p == midd c

        midd :: Char -> Int
        midd c = (cMap M.! c) `div` 2

mkOrder :: MyMap -> [Ann] -> [Ann] -> [Int]
mkOrder cMap pre post = map (mMap M.!) post
  where
    n = length pre
    mMap = genRevMap (zip [n-1, n-2 .. 0] (map annMirror pre))
    annMirror (c, p) = (c, (cMap M.! c) - 1 - p)
    genRevMap pairs = foldr op M.empty pairs
    op (i, ann) uMap = M.insert ann i uMap

main :: IO ()
main = do
  cont <- getContents
  putStrLn $ show $ solve (takeWhile isLower cont)
