{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> Int -> Int -> [(Int,Int)] -> Double
solve xA yA xB yB bN lstXY =
  (fromIntegral ((xL+yL)*100)) + diffLen
  where
  cvtFX x | xA < xB = x - xA
          | otherwise = xA - x
  cvtFY y | yA < yB = y - yA
          | otherwise = yA - y
  cvtF (x,y) = (cvtFX x, cvtFY y)
  (xL, yL) = cvtF (xB, yB)
  vXY = VU.fromList $ sort $ filter eff $ map cvtF $ lstXY
    where eff (x,y) = 0 <= x && x <= xL && 0 <= y && y <= yL
  pt i = vXY VU.! i
  bM = VU.length vXY
  isXUR (x,y) (x',y') = x+1 == x' && y < y'
  isYUR (x,y) (x',y') = x < x' && y+1 == y'
  allUR prop = and [ prop (pt (i-1)) (pt i) | i <- [1..bM-1] ]
  isSpecCase1 = snd (pt 0) == 0 && snd (pt (bM-1)) == yL && allUR isYUR
  isSpecCase2 = fst (pt 0) == 0 && fst (pt (bM-1)) == xL && allUR isXUR
  diffLen
    | bM == 0 = 0
    | isSpecCase1 || isSpecCase2
      = (5*pi-20) * (fromIntegral (bM-1)) + (10*pi-20)
    | otherwise = (5*pi-20) * (fromIntegral dpHt)

  dpHt = runST $ VUM.new (bM+1) >>= dpSub
  dpSub vec = VU.foldM act 0 vXY where
    act ht (_,y) = do
      (idx, newHt) <- sch ht y
      VUM.write vec idx y
      return newHt

    sch 0 _ = return (1, 1)
    sch ht y = do
      yLast <- VUM.read vec ht
      if y > yLast then return (ht+1, ht+1)
                   else (,ht) <$> binsch 0 ht
      where
      binsch lo hi
        | lo + 1 == hi = return hi
        | otherwise = do
            let mid = (lo + hi) `div` 2
            yMid <- VUM.read vec mid
            if y < yMid then binsch lo mid else binsch mid hi

-------------------------------------------------------------------------------

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Double
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_xA,bs_yA,bs_xB,bs_yB]:remLines1 = remLines0
      xA = readBInt bs_xA
      yA = readBInt bs_yA
      xB = readBInt bs_xB
      yB = readBInt bs_yB
      [bs_bN]:remLines2 = remLines1
      bN = readBInt bs_bN
      lstXY = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve xA yA xB yB bN lstXY

outAnswer :: Double -> IO ()
outAnswer x = putStrLn $ show x

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa



-------------------------------------------------------------------------------

inp1 = "1 1 6 5\n3\n3 2\n5 3\n2 4\n"
inp2 = "3 5 6 4\n3\n3 2\n5 3\n2 4\n"
inp3 = "4 2 2 2\n3\n3 2\n5 3\n2 4\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 891.415926535897938
test2 = tv2 == 400.000000000000000
test3 = tv3 == 211.415926535897938
alltest = test1 && test2 && test3

