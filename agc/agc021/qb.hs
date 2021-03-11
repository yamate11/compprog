import qualified Data.ByteString.Lazy.Char8 as B
import Control.Monad
import Data.Maybe
import Data.List

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

intersRange :: (Double, Double) -> (Double, Double) -> (Double, Double)
intersRange (arg1, sp1) (arg2, sp2) =
  chooseOne
    (sub (arg1, sp1) (arg2 - 2*pi, sp2))
    (sub (arg1, sp1) (arg2,        sp2))
    (sub (arg1, sp1) (arg2 + 2*pi, sp2))
  where
    sub :: (Double,Double) -> (Double,Double) -> (Double,Double)
    sub (arg1, sp1) (arg2, sp2)
      | left < right = (left, right - left)
      | otherwise    = (0, 0)
      where left = max arg1 arg2
            right = min (arg1 + sp1) (arg2 + sp2)
    chooseOne (arg1,sp1) (arg2,sp2) (arg3,sp3)
      | sp1 > 0 = (arg1,sp1)
      | sp2 > 0 = (arg2,sp2)
      | otherwise = (arg3,sp3)

getRange :: (Int,Int) -> (Int,Int) -> (Double, Double)
getRange (x1,y1) (x2,y2) =
  (arg1, pi)
  where
    arg1 = (atan2 (fromIntegral (y2-y1)) (fromIntegral (x2-x1))) + (pi / 2.0)

solve :: Int -> [[Int]] -> [Double]
solve n iss =
  map calcProb [0..n-1]
  where
    calcProb :: Int -> Double
    calcProb i = (snd $ cpsub (iss !! i) iss) / (2*pi)

    cpsub :: [Int] -> [[Int]] -> (Double, Double)
    cpsub [x0,y0] iss = foldl1' intersRange
                           [getRange (x0,y0) (x1,y1) | [x1,y1] <- iss,
                                                       (x0,y0) /= (x1,y1)]

main :: IO ()
main = do
  conts <- B.getContents
  let [n] : iss = map bsReadInts (B.lines conts)
      answer = solve n iss
  forM_ answer $ \d -> do
    putStrLn (show d)
    
