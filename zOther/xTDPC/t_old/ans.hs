{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> Int
solve k n | n <= k = 1
          | otherwise = runST act where

  bin_n = unfoldr f (n-1)
    where f 0 = Nothing
          f x = Just (q, p) where (p,q) = divMod x 2
  answer = runST act
  act :: ST s Int
  act = do
    matA <- VUM.replicate (k*k) 0
    forM_ [0..k-2] $ \i -> VUM.write matA (enc (i+1,i)) 1
    forM_ [0..k-1] $ \i -> VUM.write matA (enc (i,k-1)) 1
    matE <- VUM.replicate (k*k) 0
    forM_ [0..k-1] $ \i -> VUM.write matE (enc (i,i)) 1
    (matP0, _) <- foldM opFM (matE, matA) bin_n
    mSumM [VUM.read matP0 (enc (i,0)) | i <- [0..k-1]]
      where 
        opFM :: (VUM.MVector s Int, VUM.MVector s Int) -> Int ->
                ST s (VUM.MVector s Int, VUM.MVector s Int)
        opFM (matP, matAP) b = do
              matP' <- if b == 1 then matMult matP matAP else (return matP)
              matAP' <- matMult matAP matAP
              return (matP', matAP')

  enc (x,y) = y * k + x

  matMult :: VUM.MVector s Int -> VUM.MVector s Int -> 
             ST s (VUM.MVector s Int)
  matMult mat1 mat2 = do
    ret <- VUM.new (k*k)
    forM_ [(p,q) | p<-[0..k-1], q<-[0..k-1]] $ \(p,q) -> do
      mSumM [mMul <$> VUM.read mat1 (enc (p,r))
                  <*> VUM.read mat2 (enc (r,q)) | r <- [0..k-1]]
        >>= VUM.write ret (enc (p,q))
    return ret
    
mSumM :: Monad m => [m Int] -> m Int
mSumM = foldl' (liftM2 mAdd) (return 0)

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
      [bs_k,bs_n]:remLines1 = remLines0
      k = readBInt bs_k
      n = readBInt bs_n
  in solve k n

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

