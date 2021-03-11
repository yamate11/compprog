{-# LANGUAGE BangPatterns #-}
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.Bits
import Data.List
import System.Random

{--
  BIT represented by v :: VUM.MVector s Int
    v_1 = a_1
    v_2 = a_1 + a_2
    v_3 = a_3
    v_4 = a_1 + a_2 + a_3 + a_4
    v_5 = a_5
    v_6 = a_5 + a_6
    ...
  The size of a is n; i.e. a = (a_i | 1 <= i <= n).
  The biggest index of v is n, thus, v must be initialized by:
      v <- VUM.replicate (n+1) 0
--}

{--
  bit_add v n i x ... a_i += x
--}
bit_add :: VUM.MVector s Int -> Int -> Int -> Int -> ST s ()
bit_add v n i x = sub i
  where
    sub !j | j > n     = return ()
           | otherwise = do
               VUM.modify v (+ x) j
               sub (j + (j .&. (-j)))

{--
  bit_intv v i    ... \Sum_{j=1}^{i} a_i
                      i can be 0, in which case 0 is returned
--}
bit_intv :: VUM.MVector s Int -> Int -> ST s Int
bit_intv v i = sub 0 i
  where
    sub !acc 0 = return acc
    sub !acc !j = do
      y <- VUM.read v j
      sub (acc+y) (j - (j .&. (-j)))


-- (application)
-- bitXchgCount ns
--   Counts the number of pairs (i, j) s.t. i < j and ns !! i > ns !! j,
--   where ns is a permutation of [0 .. size-1].
bitXchgCount :: [Int] -> Int
bitXchgCount ns = runST $ do
  v <- VUM.replicate (n+1) 0
  preserved <- liftM sum $ forM ns $ \i -> do
    bit_add v n (i+1) 1
    bit_intv v i
  return $ (n * (n-1)) `div` 2 - preserved
  where
    n = length ns




-- test

test1 :: IO ()
test1 = do
  unless (bitXchgCount [4,0,1,3,2] == 5) $ error "test1.1"
  unless (bitXchgCount [2,3,0,1] == 4) $ error "test1.2"

test2 :: IO ()
test2 = do
  gen <- getStdGen
  sub gen 5
  where
    sub :: RandomGen g => g -> Int -> IO ()
    sub _ 21 = return ()
    sub gen k = do
      let (gen1, gen') = split gen
          (gen2, gen3) = split gen'
          ixs = take 100 $ zip (randomRs (1,k) gen1)
                               (randomRs (-100, 100) gen2)
      unless (for_test2 k ixs) $ error $ "test2: ixs = " ++ show ixs
      sub gen3 (k+1)

for_test2 :: Int -> [(Int, Int)] -> Bool
for_test2 n ixs = runST $ do
  v <- VUM.replicate (n+1) 0
  w <- VUM.replicate (n+1) 0
  forM_ ixs $ \(i,x) -> do
    VUM.modify w (+ x) i
    bit_add v n i x
  liftM and $ forM [1..n] $ \i -> do
    s <- VUM.read w i
    t1 <- bit_intv v i
    t2 <- bit_intv v (i-1)
    return $ s == t1 - t2
  
  
  
