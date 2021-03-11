{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
trace _ a = a

solve :: Int -> [(String,Int)] -> Int
solve n cas = answer
  where

{--
k :: [0..2n-1]
i :: [0..n]
bwTbl ! (enc k col i)
  = # { p | k < p, (col,j) is located at p, i >= j }
--}    

  bwTbl :: VU.Vector Int
  bwTbl = trace ("bwTbl = " ++ show bwTbl0) bwTbl0

  bwTbl0 = VU.create $ do
    bwv <- VUM.new ((2*n+1)*2*(n+1))
    forM_ [0..n] $ \i -> do
      VUM.write bwv (enc 0 0 i) i
      VUM.write bwv (enc 0 1 i) i
    forM_ (zip [1..] cas) $ \(k, (c, a)) -> do
      forM_ [0..n] $ \i -> do
        forM_ [0,1] $ \col -> do
          x <- VUM.read bwv (enc (k-1) col i)
          let y | col == color c && i >= a = x-1
                | otherwise = x
          VUM.write bwv (enc k col i) y
    return bwv
  enc  k col i = k * (2*(n+1)) + col * (n+1) + i
  bwT k col i = trace ("bwT " ++ show (k,col,i,ans)) ans
    where ans = bwT0 k col i
  bwT0 k col i = bwTbl VU.! (enc (k+1) col i)

  posTbl :: VU.Vector Int
  posTbl = VU.create $ do
    vec <- VUM.new (2*(n+1))
    forM_ (zip [0..] cas) $ \(k, (c,a)) -> do
      VUM.write vec (encP (color c) a) k
    return vec
  encP col a = col * (n+1) + a
  posT col a = trace ("posT " ++ show (col,a,ans)) ans
    where ans = posT0 col a
  posT0 col a = posTbl VU.! (encP col a)
    
  revNums = foldl op [0] [1..2*n]
    where
    op rs m = trace ("op " ++ show (rs, m, a)) a
      where a = op0 rs m
    op0 rs m | m <= n    = zipWith3 f [0..] (dummy:rs) (rs++[dummy])
             | otherwise = zipWith3 f [m-n..] rs (tail rs)
      where
      f i a1 a2 = min putBlack putWhite
        where
        putBlack | i == 0 = inf
                 | otherwise = a1 + (right (posT 0 i) (i-1) (m-i))
        putWhite | m-i == 0 = inf
                 | otherwise = a2 + (right (posT 1 (m-i)) i (m-i-1))
        right k bn wn = bwT k 0 bn + bwT k 1 wn

  [answer] = revNums

dummy = 0
inf = maxBound :: Int

color s | head s == 'B' = 0
        | otherwise     = 1

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      cas = map (\[x1,x2] -> (B.unpack x1,readBInt x2)) remLines1
  in solve n cas

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "3\nB 1\nW 2\nB 3\nW 1\nW 3\nB 2\n"
inp2 = "4\nB 4\nW 4\nB 3\nW 3\nB 2\nW 2\nB 1\nW 1\n"
inp3 = "9\nW 3\nB 1\nB 4\nW 1\nB 5\nW 9\nW 2\nB 6\nW 5\nB 3\nW 8\nB 9\nW 7\nB 2\nB 8\nW 4\nW 6\nB 7\n"
inp4 = "2\nB 1\nW 1\nW 2\nB 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 4
test2 = tv2 == 18
test3 = tv3 == 41
test4 = tv4 == 0
alltest = test1 && test2 && test3 && test4
