{-# LANGUAGE RankNTypes #-}

{-
This answer was written after referring to the editorial.
-}
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Data.List
import Control.Monad
import Debug.Trace

bigP = 998244353

addM x y = (x + y) `mod` bigP
multM x y = (x * y) `mod` bigP
subtM x y = (bigP + x - y) `mod` bigP
negM x = subtM 0 x

vec_pow = VU.fromListN 2010 $ iterate (multM 2) 1
pow2M = (VU.!) vec_pow

vec_fact = VU.fromListN 4020 $ scanl' multM 1 [1..]
fact = (VU.!) vec_fact

{-
  "memovec mf size" is a function created from mf using vector 
  memoization.
  mf defines the calculation of the vector.  For example, if you
  want the fibonacci function: 

      mf :: Monad m => (Int -> m Int) -> (Int -> m Int)
      mf act 0 = return 1
      mf act 1 = return 1
      mf act n = (+) <$> act (n-1) <*> act (n-2)

      fib :: Int -> Int
      fib = memovec mf 100000
-}
memovec :: VU.Unbox a =>
           (forall m. Monad m => (Int -> m a) -> (Int -> m a)) ->
           Int -> (Int -> a)
memovec mf size = (VU.!) vecx
  where vecx = VU.create $ do
          v <- VUM.new size
          forM_ [0..size-1] $ \i -> mf (VUM.read v) i >>= VUM.write v i
          return v

mfinv act 0 = return 0 -- dummy
mfinv act 1 = return 1
mfinv act n = do
  let (a,b) = divMod bigP n
  x <- act b
  return ((negM a) `multM` x)

inv = memovec mfinv 4030

vec_inv_fact = VU.fromListN 4024 $ scanl' f 1 [1..]
  where f s t = s `multM` (inv t)
inv_fact = (VU.!) vec_inv_fact

-- cmb m r | trace ("cmb " ++ show (m,r)) False = undefined
cmb m r = (fact m) `multM` (inv_fact r) `multM` (inv_fact (m-r))

solve :: Int -> Int -> [Int]
solve k n =
  map s_solve [2..2*k]
  -- map s_solve [2]
  where

  s_solve t = 
    -- trace ("s_solve " ++ show [t,a,xx]) xx
    xx
    where a = num_diff_pair t
          xx = foldl' addM 0 [face_cnt_cstr_tot t p (a-p) | p <- [0..a]]
  
  face_cnt m r 
    | mm >= 0 && rr >= 0 && mm >= rr = cmb mm rr
    | otherwise                      = 0
    where mm = m+r-1
          rr = r-1

  -- z: (1+)
  -- y: 0
  -- w: 1
     -- face_cnt_cstr z y w
     -- | trace ("face_cnt_cstr " ++ show (n,k,z,y,w)) False = undefined
  face_cnt_cstr z y w = face_cnt (n-z-w) (k-y-w)

  -- p: 1+/0
  -- q: 0/0
  -- u: 1 if k/2 should be 1
  -- v: 1 if k/2 should be 0
  face_cnt_cstr_tot t p q = xx
    where xx = (cmb (p+q) p) `multM` (pow2M p) `multM` e
          e | t `mod` 2 == 1 = face_cnt_cstr p (p+2*q)   0
            | otherwise =      face_cnt_cstr p (p+2*q)   1
                             + face_cnt_cstr p (p+2*q+1) 0

{-
k == 7
2 -> 0
3 -> 1  (1-2/2-1)
4 -> 1  (1-3/3-1)
5 -> 2  (1-4/4-1, 2-3/3-2)
6 -> 2  (1-5/5-1, 2-4/4-2)
7 -> 3  (1-6/6-1, 2-5/5-2, 3-4/4-3)
13 -> 1 (6-7/7-6)
12 -> 1 (5-7/7-5)
11 -> 2 (4-7/7-4, 5-6/6-5)
10 -> 2 (3-7/7-3, 4-6/6-4)
9  -> 3 (2-7/7-2, 3-6/6-3, 4-5/5-4)
8  -> 3 (1-7/7-1, 2-6/6-2, 3-5/5-3)
-}

  num_diff_pair t
    | t <= k    = (t-1) `div` 2
    | otherwise = (2*k - t + 1) `div` 2


main = do
  cont <- getContents
  let [k,n] = map read $ words cont
  putStr $ unlines $ map show $ solve k n
