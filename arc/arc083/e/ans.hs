{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
-- import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ = id

solve :: Int -> [Int] -> [Int] -> Bool
solve n ps xs = func 1 /= Nothing
  where

  tree = trace ("tree" ++ show tree0) tree0
  tree0 = V.create $ do
    vec <- VM.replicate (n+1) []
    forM_ (zip [2..] ps) $ \(c, p) -> VM.modify vec (c :) p
    return vec

  vx = VU.fromListN (n+1) (0 : xs)

  func :: Int -> Maybe (Int, Int)
  func i = trace ("func " ++ show(i,a)) a
    where a = func' i
  func' i = mapM func (tree V.! i) >>= g (vx VU.! i)
    where
    g :: Int -> [(Int, Int)] -> Maybe (Int, Int)
    g xi pqs | finBit == 0    = Nothing
             | otherwise = Just (xi, finSum - y)
      where
      (finBit, finSum) = foldr op (1, 0) pqs
      mask :: Integer
      mask = 2 ^ (xi + 1) - 1
      op :: (Int, Int) -> (Integer, Int) -> (Integer, Int)
      op (p, q) (bit, sum) 
        = (mask .&. (shift bit p .|. shift bit q), sum + p + q)
      y = head $ [i | i <- [xi,xi-1..0], testBit finBit i]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Bool
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      ps = map readBInt line2
      line3:remLines3 = remLines2
      xs = map readBInt line3
  in solve n ps xs

outAnswer :: Bool -> IO ()
outAnswer x = putStrLn (if x then "POSSIBLE" else "IMPOSSIBLE")

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n1 1\n4 3 2\n"
inp2 = "3\n1 2\n1 2 3\n"
inp3 = "8\n1 1 1 3 4 5 5\n4 1 6 2 2 1 3 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == True
test2 = tv2 == False
test3 = tv3 == True
inp4 = "1\n\n0\n"
tv4 = tmain $ B.pack inp4
test4 = tv4 == True
alltest = test1 && test2 && test3 && test4
