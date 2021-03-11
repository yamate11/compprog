-- This code was written after reading the editorial.

{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import Data.Vector.Unboxed ((!))
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [(Int,Int)] -> Int
solve n xys = (oTbl ! 0) `mSub` (eTbl ! 0)
  where

  nbrs :: V.Vector [Int]
  nbrs = V.create $ do
    vec <- VM.replicate (n+1) []
    forM_ xys $ \(x,y) -> do
      VM.modify vec (y:) x
      VM.modify vec (x:) y
    return vec

  children :: V.Vector [Int]
  children = V.create $ do
    vec <- VM.new (n+1)
    VM.write vec 1 (nbrs V.! 1)
    forM_ (nbrs V.! 1) $ \i -> act vec 1 i
    return vec
    where
      act vec p c = do
        let cs = filter (/= p) (nbrs V.! c)
        VM.write vec c cs
        forM_ cs $ \j -> act vec c j

  (eTbl, oTbl) = calc 1

  calc v0 = partZero partOnePlus
    where
    childResults = map calc (children V.! v0)
    partOnePlus = case childResults of
      [] -> (VU.fromList [1], VU.fromList [])
      [r] -> r
      _ -> foldl' op (VU.fromList [1], VU.fromList []) childResults
      where
      op vP@(eTblP, oTblP) (eTblC, oTblC)
        | VU.length oTblC == 0 && VU.length eTblC == 1 && eTblC ! 0 == 1
        = vP
        | VU.length oTblC == 1 && oTblC ! 0 == 0 && VU.length eTblC == 2
          && eTblC ! 0 == 0 && eTblC ! 1 == 1
        = (VU.cons 0 eTblP, VU.cons 0 oTblP)
        | otherwise
        = (conv2 eTblP eTblC oTblP oTblC, conv2 eTblP oTblC oTblP eTblC)
      conv2 v1 v2 v3 v4 = vzWMA (vmConv v1 v2) (vmConv v3 v4)

    partZero (!eL, !oL) = (f eL oL, f oL eL)
      where
      f ls1 ls2 = VU.cons theSum ls1
        -- theSum = vmSum (VU.zipWith mMul vcmbPair ls2)
        where theSum = vmSum (VU.zipWith (*) vcmbPair ls2)

  vcmbPair = VU.unfoldrN (n+1) op (1,1)
    where op (k,prev) | odd k     = Just (0, (k+1,prev))
                      | otherwise = Just (cur, (k+1,cur))
            where !cur = (k-1) `mMul` prev

vzWMA :: VU.Vector Int -> VU.Vector Int -> VU.Vector Int
vzWMA !v1 !v2 = VU.create $ do
  let len1 = VU.length v1
      len2 = VU.length v2
      lMax = max len1 len2
      lMin = min len1 len2
      (w1, w2) | len1 >= len2 = (v1, v2)
               | otherwise = (v2, v1)
  v <- VUM.new lMax
  forM_ [0..lMin-1] $ \i -> VUM.write v i ((w1 ! i) `mAdd` (w2 ! i))
  forM_ [lMin..lMax-1] $ \i -> VUM.write v i (w1 ! i)
  return v

vmConv :: VU.Vector Int -> VU.Vector Int -> VU.Vector Int
vmConv v1 v2 = VU.create $ do
  let l1 = VU.length v1
      l2 = VU.length v2
  v <- VUM.new (l1 + l2 - 1)
  forM_ [0..l1+l2-2] $ \k -> do
    VUM.write v k (mSum [(v1 ! i) * (v2 ! (k-i))
                       | i <- [(max 0 (k-l2+1)) .. (min (l1-1) k)]])

  return v

vmSum = VU.foldl' mAdd 0
mSum = foldl' mAdd 0

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "4\n1 2\n2 3\n3 4\n"
inp2 = "4\n1 2\n1 3\n1 4\n"
inp3 = "6\n1 2\n1 3\n3 4\n1 5\n5 6\n"
inp4 = "10\n8 5\n10 8\n6 5\n1 5\n4 8\n2 10\n3 6\n9 2\n1 7\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 2
test2 = tv2 == 3
test3 = tv3 == 10
test4 = tv4 == 672
alltest = test1 && test2 && test3 && test4
