{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}

--------------------------------------------------------------------------------
import System.Environment
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.Bits
import Debug.Trace

inf :: Double
inf = 1000000.0

solve n xs = runST act where

  act :: forall s. ST s Double
  act = do
    dp <- VUM.replicate (2^n) (-1.0 :: Double)
    act0 dp 

  act0 :: forall s. VUM.MVector s Double -> ST s Double
  act0 dp = do_calc tobits where
    
    tobits = foldr op 0 xs
      where op x bs = setBit bs x

    calc = memoize do_calc dp id id id
    
    do_calc :: Int -> ST s Double
    do_calc 0 = return 0.0
    do_calc bs = minimumM $ map f $ takeWhile ((<= bs) . (2^)) [0..]
      where
      f :: Int -> ST s Double
      f i = liftM (f1 i nSuc) sumExp
        where
          (nSuc, sumExp) = foldr op (0,return 0.0) $ map g [i-1, i, i+1]
            where op (x1,y1) (x2,y2) = (x1+x2,(+)<$>y1<*>y2)
                  g j | bs' == bs = (0, return 0.0)
                      | otherwise = (1, calc bs')
                    where
                      bs' | j < 0 || j >= n = bs
                          | otherwise       = clearBit bs i

      f1 :: Int -> Int -> Double -> Double
      f1 i nSuc sumExp | nSuc == 0 = inf
                       | nSuc == 1 = sumExp / 3.0 + 3.0
                       | nSuc == 2 = sumExp / 2.0 + 1.5
                       | nSuc == 3 = sumExp / 3.0 + 0.0
                            

main = do
  cont <- getContents
  let (n:xs) = map read $ words cont
  putStrLn $ show $ solve n xs


memoize :: (VUM.Unbox vt, Eq vt, Ord vt, Num vt) =>
           (a -> ST s b) -> (VUM.MVector s vt) ->
           (a -> Int) -> (b -> vt) -> (vt -> b) -> 
           (a -> ST s b)
memoize f v encA encB decB x = do
  let idx = encA x
  z <- VUM.read v idx
  if z < 0 then return (decB z) else do
    w <- f x
    VUM.write v idx (encB w)
    return w

minimumM :: (Monad m, Num a, Ord a) => [m a] -> m a
minimumM (mi:mis) = foldr op mi mis
  where op mi mj = min <$> mi <*> mj

