{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
{-# LANGUAGE MultiWayIf #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.ST
import System.Random
import Debug.Trace
import System.Environment
-- trace _ = id

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

mPrime = 10^9 + 7

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  g <- getStdGen
  cont <- B.getContents
  let as = bsReadInts cont
      bs = mysort g as
  putStrLn (show (length bs))

mysort :: (Ord a, VU.Unbox a, Show a, RandomGen g) => g -> [a] -> [a]
mysort g as = VU.toList $ runST $ do
  v <- VU.unsafeThaw (VU.fromList as)
  mymsort g v
  VU.unsafeFreeze v

mysortOn :: (Ord a, Ord b, VU.Unbox a, VU.Unbox b,
             Show a, Show b, RandomGen g) =>
            g -> (a -> b) -> [a] -> [a]
mysortOn g f as = VU.toList $ runST $ do
  v <- VU.unsafeThaw $ VU.fromList $ map (\a -> (f a, a)) as
  mymsort g v
  (VU.map snd) <$> (VU.unsafeFreeze v)

mymsort :: (PrimMonad m, Ord a, VUM.Unbox a, Show a, RandomGen g) =>
           g -> VUM.MVector (PrimState m) a -> m ()
mymsort g v = sortBody g v 0 ((VUM.length v) - 1) 
  where

  sortBody g v lo hi | hi - lo <= 6 = isort v lo hi
                     | otherwise    = do
                         let (x, newG) = randomR (lo,hi) g 
                         -- let (x, newG) = (lo, g)
                         pivot <- VUM.read v x
                         (pL, pR) <- partition v lo hi x pivot
                         sortBody newG v lo (pL-1)
                         sortBody newG v (pR+1) hi

  isort v lo hi = do
    forM_ [lo+1..hi] $ \i -> do
      x <- VUM.read v i
      j <- position lo i x
      VUM.move (VUM.slice (j+1) (i-j) v) (VUM.slice j (i-j) v)
      VUM.write v j x
    where
      position k i x
        | k == i = return i
        | otherwise = do
            y <- VUM.read v k
            if x < y then return k
                     else position (k+1) i x

  -- Compares and moves elems of v against pivot in range [lo,hi]
  -- Precondition: v[x] == pivot
  -- Returns (pL, pR): for pL <= j <= pR, v[j] == pivot
  partition v lo hi x pivot = do
    VUM.swap v lo x
    (loW, hiW) <- partBody (lo+1) hi lo hi
    mapM_ (\i -> VUM.write v i pivot) [loW .. hiW]
    return (loW, hiW)
    where

    partBody loR hiR loW hiW
      | hiR < loR  = return (loW, hiW)
      | loR == loW = sub loR (loR+1) hiR
      | otherwise  = sub hiR loR (hiR-1)
      where
      sub rd newLoR newHiR = do
        t <- VUM.read v rd
        (newLoW, newHiW) <- aWrite loW hiW t
        partBody newLoR newHiR newLoW newHiW

    aWrite loW hiW t
      | t < pivot = VUM.write v loW t >> return (loW+1, hiW)
      | t > pivot = VUM.write v hiW t >> return (loW,   hiW-1)
      | otherwise =                      return (loW,   hiW)

