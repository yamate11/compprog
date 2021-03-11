{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace

solve :: Int -> [(Int,Int)] -> Int
solve n abs = runST act where

  act :: forall s. ST s Int
  act = do
    vec1 <- VUM.replicate ((n+1)*(n+1)) (-1)
    vec2 <- VUM.replicate ((n+1)*(n+1)) (-1)
    run vec1 vec2 where

      run :: VUM.MVector s Int -> VUM.MVector s Int -> ST s Int
      run vec1 vec2 = mSumM (map top_merge abs) where
  
        top_merge (a,b) =
          let f p1 p2 m1 m2 = (mCombi (m1+m2) m1) `mMul` p1 `mMul` p2
          in liftM4 f (count (a,b)) (count (b,a)) (size (a,b)) (size (b,a))
  
        size = memoize doSize vec1 enc id id

        doSize :: (Int,Int) -> ST s Int
        doSize (q,p) = sum <$> (mapM f $ filter (/= q) $ vNbr V.! p)
          where f r = (+ 1) <$> size (p,r)

        count = memoize doCount vec2 enc id id
  
        doCount :: (Int,Int) -> ST s Int
        doCount (q,p) = do
          let succs = filter (/= q) (vNbr V.! p)
          ss <- mapM size (map (\r -> (p,r)) succs)
          let places = cntPlaces (map (+ 1) ss)
          liftM2 mMul (return places)
                      (mProd <$> (mapM (\r -> count (p,r)) succs))

  enc (i,j) = i * (n+1) + j
  
  vNbr = V.create $ do
    v <- VM.replicate (n+1) []
    forM_ abs $ \(a,b) -> do
      VM.modify v (a:) b
      VM.modify v (b:) a
    return v

cntPlaces :: [Int] -> Int
cntPlaces [] = 1
cntPlaces [_] = 1
cntPlaces xs = mFact (sum xs) `mMul` (mInv (mProd (map mFact xs)))

mFact 0 = 1
mFact n = n `mMul` (mFact (n-1))

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      abs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n abs

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

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

mPow :: Int -> Int -> Int
mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x

mCombi n r | n-r < r = mCombi n (n-r)
mCombi n 0 = 1
mCombi n r = foldl1' mMul (d : [n-r+1..n])
  where d = mInv $ foldl1' mMul [1..r]

mProd = foldl' mMul 1

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

sumM :: (Monad m, Num a) => [m a] -> m a
sumM = foldl' (liftM2 (+)) (return 0)

mProdM :: (Monad m) => [m Int] -> m Int
mProdM = foldl' (liftM2 mMul) (return 1)

mSumM :: (Monad m) => [m Int] -> m Int
mSumM = foldl' (liftM2 mAdd) (return 0)

----------------------------------------------------------------------

inp1 = "4\n1 2\n2 3\n3 4\n"
inp2 = "8\n1 2\n4 6\n6 7\n3 2\n2 4\n4 5\n8 6\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == 4
test2 = tv2 == 752
alltest = test1 && test2
