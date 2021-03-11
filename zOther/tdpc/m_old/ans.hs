{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Data.Bits
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [[Int]] -> Int
solve h r conn = head (head matPower) where
  connV :: V.Vector [Int]
  connV = V.fromList $ map f conn
    where f :: [Int] -> [Int]
          f bs = catMaybes $ zipWith f1 [0..] bs
            where f1 i 0 = Nothing
                  f1 i 1 = Just i
  mat0 = unfoldr f (runST $ act)
    where f [] = Nothing
          f lst = Just (splitAt r lst)
  e_r = map f [0..r-1]
    where f i = take i (repeat 0) ++ 1 : take (r-1-i) (repeat 0)
  powerMat = unfoldr f mat0
    where f mat = Just (mat, mat `matProd` mat)
  bin_h = unfoldr f h
    where f 0 = Nothing
          f x = Just (r, d)
            where (d, r) = x `divMod` 2
  matPower :: [[Int]]
  matPower = foldr matProd e_r (zipWith f bin_h powerMat)
    where f 0 mat = e_r
          f 1 mat = mat
  act :: forall s. ST s [Int]
  act = do
    vec <- VUM.replicate ((2^r)*r*r) (-1)
    run vec
      where
      run :: VUM.MVector s Int -> ST s [Int]
      run vec = 
        forM [(i,j) | i <- [0..r-1], j <- [0..r-1]] (\(i,j) -> count i j)
        where
        count :: Int -> Int -> ST s Int
        count i j = countX (0,i,j)
        countX :: (Int,Int,Int) -> ST s Int
        countX = memoize do_countX vec enc id id
        enc (pat,i,j) = (pat * r + i) * r + j

        do_countX :: (Int,Int,Int) -> ST s Int
        do_countX (pat,i,j) 
          | i == j = return 1
          | otherwise = 
              modSumM [countX (setBit pat i,i',j)
                          | i' <- connV V.! i, not (testBit pat i') ]
  
matProd :: [[Int]] -> [[Int]] -> [[Int]]
matProd mat1 mat2 = ans
  where mat2t = transpose mat2
        ans = [[foldl' mAdd 0 (zipWith mMul a b) | b <- mat2t] | a <- mat1]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_h,bs_r]:remLines1 = remLines0
      h = readBInt bs_h
      r = readBInt bs_r
      g = map (map readBInt) remLines1
  in solve h r g

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (mPrime + x - y) `mod` mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mem_undef :: (Ord vt, Num vt) => vt -> Bool
mem_undef = (< 0)

memoize :: (VUM.Unbox vt, Num vt, Ord vt) =>
           (a -> ST s b) -> (VUM.MVector s vt) ->
           (a -> Int) -> (b -> vt) -> (vt -> b) ->
           (a -> ST s b)
memoize f v encA encB decB x = do
  let idx = encA x
  z <- VUM.read v idx
  if not (mem_undef z) then return (decB z) else do
    w <- f x
    VUM.write v idx (encB w)
    return w

modSumM :: Monad m => [m Int] -> m Int
modSumM mis = foldr op (return 0) mis
  where op mi mj = mAdd <$> mi <*> mj

