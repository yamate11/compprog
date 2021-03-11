{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}

import System.Environment
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace

solve s = runST $ do
  dp1 <- VUM.replicate ((n+1)*(n+1)) undefV
  dp2 <- VUM.replicate ((n+1)*(n+1)) undefV
  act dp1 dp2

  where

  n = length s
  cs = VU.fromList s
  enc (i,j) = i * (n+1) + j

  act :: forall s.
         VUM.MVector s Int -> VUM.MVector s Int -> ST s Int
  act dp1 dp2 = count (0, n-1) where

    count :: (Int, Int) -> ST s Int
    count = memoize do_count dp1 enc id id undefV

    do_count :: (Int, Int) -> ST s Int
    do_count (i,j)
      | j < i+2 = return 0
      | otherwise = compl (i,j) >>=
           ite3
             (return ((j+1-i) `div` 3))
             (maximumM $ [count(i, j-1), count(i+1, j)] ++ map f [i+3 .. j-3])
      where f k = (+) <$> count (i, k-1) <*> count (k+1, j)

    enc2 True = 1
    enc2 False = 0
    dec2 x = x == 1
    compl = memoize do_compl dp2 enc enc2 dec2 undefV

    do_compl :: (Int, Int) -> ST s Bool
    do_compl (i,j)
      | j == i-1 = return True
      | (j-i) `mod` 3 /= 2 = return False
      | cs VU.! i /= 'i' || cs VU.! j /= 'i' = return False
      | otherwise = anyM chk1 [i+1 .. j-1] ||| anyM chk2 ks2
      where
        ks2 = takeWhile (< j) [i + 3*p - 1 | p <- [1..]]
        chk1 k = 
          (return (cs VU.! k == 'w')) &&&
             compl (i+1, k-1) &&& compl (k+1, j-1)
        chk2 k = 
          (return (cs VU.! k == 'i')) &&&
             compl (i, k) &&& compl (k+1, j)

maximumM :: Monad m => [m Int] -> m Int
maximumM (mi:mis) = foldr op mi mis
  where op mi mj = max <$> mi <*> mj

sumM :: Monad m => [m Int] -> m Int
sumM mis = foldr op (return 0) mis
  where op mi mj = (+) <$> mi <*> mj

memoize :: (VUM.Unbox vt, Eq vt) =>
           (a -> ST s b) -> (VUM.MVector s vt) ->
           (a -> Int) -> (b -> vt) -> (vt -> b) -> vt ->
           (a -> ST s b)
memoize f v encA encB decB undef x = do
  let idx = encA x
  z <- VUM.read v idx
  if z /= undef then return (decB z) else do
    w <- f x
    VUM.write v idx (encB w)
    return w

      
                
undefV :: Int
undefV = -1

main :: IO ()
main = do
  [x] <- getArgs
  -- putStrLn $ show $ fastest_f (read x)
  -- putStrLn $ show $ withgen (read x)
  -- putStrLn $ show $ withvec (read x)
  putStrLn $ show $ solve x

ite3 :: a -> a -> Bool -> a
ite3 t e c = if c then t else e

(&&&) :: Monad m => m Bool -> m Bool -> m Bool
ma &&& mb = ma >>= ite3 mb (return False)

andM :: Monad m => [m Bool] -> m Bool
andM = foldr (&&&) (return True)

(|||) :: Monad m => m Bool -> m Bool -> m Bool
ma ||| mb = ma >>= ite3 (return True) mb

orM :: Monad m => [m Bool] -> m Bool
orM = foldr (|||) (return False)

allM :: Monad m => (a -> m Bool) -> [a] -> m Bool
allM act = foldr (\x y -> act x &&& y) (return True)

anyM :: Monad m => (a -> m Bool) -> [a] -> m Bool
anyM act = foldr (\x y -> act x ||| y) (return False)
