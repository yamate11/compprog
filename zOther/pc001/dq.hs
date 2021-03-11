{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.Vector as VB
import qualified Data.Vector.Mutable as VBM
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Control.Monad
import Control.Monad.ST
import Debug.Trace

-- traceQ label a
--   Traces the value of a with label.
traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a
-- traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

big = (1000000000 :: Int) + 1

solve :: [[Int]] -> String
solve ([valN, valM] : as : xys) =
  case sum2 of
    Nothing -> "Impossible"
    Just t -> show $ sum1 + t
  where
    nbr = fNbr valN xys
    pInfo = fPInfo valN nbr as
--      pInfo[id] == (connectedComponentID, aValue)
--    vcc = connComps valN (traceQ "nbr" nbr)
    numCcs = traceQ "numCcs" (fNumCcs (traceQ "vcc" vcc))
--    sorted = sortTotal as
--    rank = mkRank valN (traceQ "sorted" sorted)
--    licc = leastInCC valN numCcs (traceQ "rank" rank) vcc
    (least, rest) = fLeastRest numCcs pInfo
    sum1 = mkSum1 (traceQ "licc" licc)
    sum2 = mkSum2 numCcs licc sorted vcc

fNbr :: Int -> [[Int]] -> VB.Vector [Int]
fNbr valN xys = VB.create $ do
  vec <- VBM.replicate valN [] 
  forM_ xys $ \[x,y] -> do
    VBM.modify vec (y:) x
    VBM.modify vec (x:) y
  return vec

{-
connComps :: Int -> VB.Vector [Int] -> V.Vector Int
connComps valN nbr = V.create (actCC valN nbr)
-}

fPInfo :: Int -> VB.Vector [Int] -> [Int] -> V.Vector (Int, Int)
-- pInfo[id] == (connectedComponentID, aValue)
fPInfo valN nbr as = V.create (actCC valN nbr as)

actCC :: forall s. Int -> VB.Vector [Int] -> [Int]
         -> ST s (VM.MVector s (Int, Int))
actCC valN nbr as = do
  clsfy <- VM.replicate valN (-1, 0)
  sub clsfy 0 0 
  forM_ (zip [0..] as) $ \(i, a) ->
    VM.modify clsfy (\(t, _) -> (t, a)) i
  return clsfy
  where
    sub :: VM.MVector s Int -> Int -> Int -> ST s ()
    sub clsfy i ccidx =
      if i == valN then return ()
      else do
        (c,_) <- VM.read clsfy i
        if c == -1
          then do
            sub2 clsfy i ccidx
            sub clsfy (i + 1) (ccidx + 1)
          else
            sub clsfy (i + 1) ccidx
    sub2 :: VM.MVector s Int -> Int -> Int -> ST s ()
    sub2 clsfy i ccidx = do
      sub3 [[i]]
      where
        sub3 :: [[Int]] -> ST s ()
        sub3 []             = return ()
        sub3 ([]:stack)     = sub3 stack
        sub3 ((j:js):stack) = do
          (c,_) <- VM.read clsfy j
          if c == -1
            then do
              VM.write clsfy j (ccidx,0)
              sub3 ((nbr VB.! j):js:stack)
            else sub3 (js:stack)

numCcs :: V.Vector Int -> Int
numCcs = (+ 1) . maximum . V.toList

sortTotal :: [Int] -> [(Int, Int)]
sortTotal as = sortOn (\(id,a) -> a) (zip [0..] as)

fLeastRest :: Int -> V.Vector (Int, Int) -> (V.Vector Int, [Int])
fLeastRest numCcs pInfo = 

mkRank :: Int -> [(Int, Int)] -> [Int]
mkRank valN sorted = V.toList vec
  where
    vec :: V.Vector Int
    vec = V.create act
    act :: forall s. ST s (VM.MVector s Int)
    act = do
      vec <- VM.new valN
      forM_ (zip [0..] sorted) $ \(rank, (id, _)) -> VM.write vec id rank
      return vec

leastInCC :: Int -> Int -> [Int] -> V.Vector Int -> V.Vector (Int, Int)
-- leastCC[cc] = (id, val) : the least value of connected component cc
leastInCC valN k rank vcc = leastCC
  where
    leastCC :: V.Vector (Int, Int)
    leastCC = V.create $ do
      least <- VM.replicate k (-1, big)
      forM_ (zip [0..] rank) $ \(id, r) -> do
        let cc = vcc V.! id
        (_, oldVal) <- VM.read least cc
        when (r < oldVal) (VM.write least cc (id, r))
      return least

mkSum1 :: V.Vector (Int, Int) -> Int
mkSum1 licc = V.foldl' (\acc (_, v) -> acc + v) 0 licc

mkSum2 :: Int -> V.Vector (Int, Int) -> [(Int, Int)] -> V.Vector Int
          -> Maybe Int
mkSum2 k licc sorted vcc = 
  if length ids == k - 2
     then Just $ sum $ map snd ids
     else Nothing
  where
    ids = take (k-2) $
          filter (\(i,_) -> fst (licc V.! (vcc V.! i)) /= i) sorted

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let answer = solve (map bsReadInts (B.lines conts))
  putStrLn answer
