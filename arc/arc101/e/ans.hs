-- This code was written after reading the editorial.

{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ a = a

solve :: Int -> [(Int,Int)] -> Int
solve n xys = head oTbl `mSub` head eTbl
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

  calc v0 = trace ("calc " ++ show (v0, a)) a
    where a = calc0 v0

  calc0 v0 = partZero partOnePlus
    where
    partOnePlus = foldl op ([1], []) (map calc (children V.! v0))
      where
      op (eTblP, oTblP) (eTblC, oTblC)
        = trace ("popop " ++ show (v0, eTblP, oTblP, eTblC, oTblC, a)) a
        where a = op0 (eTblP, oTblP) (eTblC, oTblC)
      op0 (eTblP, oTblP) (eTblC, oTblC)
        = (conv2 eTblP eTblC oTblP oTblC, conv2 eTblP oTblC oTblP eTblC)
      conv2 v1 v2 v3 v4 = zipWithMAddL (mConvolve v1 v2) (mConvolve v3 v4)

    partZero (eL, oL) = (f eL oL, f oL eL)
      where f ls1 ls2 = mSum (zipWith mMul cmbPair ls2) : ls1

  cmbPair = unfoldr op (1,1)
    where op (k,prev) | odd k     = Just (0, (k+1,prev))
                      | otherwise = Just (cur, (k+1,cur))
            where !cur = (k-1) `mMul` prev

zipWithMAddL [] bs = bs
zipWithMAddL as [] = as
zipWithMAddL (a:as) (b:bs) = (a `mAdd` b) : zipWithMAddL as bs

mConvolve :: [Int] -> [Int] -> [Int]
mConvolve xs ys = trace ("mConvolve " ++ show (xs, ys, a)) a
  where a = mConvolve0 xs ys
mConvolve0 xs ys =
  map (mSum . zipWith mMul (reverse ys))
      (init (tails (replicate (length ys - 1) 0 ++ xs)))

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
