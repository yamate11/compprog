{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.STRef
-- import Debug.Trace
-- trace _ = id


-- Let v = tarjan n edges.
-- Then, for each i in range(v), c(i) := [j | v ! j == i] is an SCC.
-- If c(i) is reachable from c(i'), then i < i'.  (reverse topological order)
tarjan :: Int -> [(Int,Int)] -> VU.Vector Int
tarjan n edges = VU.create $ do
  nbr <- VM.replicate n []
  forM_ edges $ \(i,j) -> VM.modify nbr (j :) i
  results <- VUM.replicate n (-1)
  index <- VUM.replicate n (-1)
  lowlink <- VUM.new n
  onStack <- VUM.replicate n False
  stack <- newSTRef []
  idxVal <- newSTRef (0 :: Int)
  tVal <- newSTRef 0
  action nbr results index lowlink onStack stack idxVal tVal
  where
  action nbr results index lowlink onStack stack idxVal tVal = act
    where
    act = do
      forM_ [0..n-1] $ \i -> do
        u <- VUM.read index i
        when (u == (-1)) (body i)
      return results

    body i = do
      idx <- readSTRef idxVal
      VUM.write index i idx
      VUM.write lowlink i idx
      modifySTRef idxVal (+ 1)
      modifySTRef stack (i :)
      VUM.write onStack i True
      iNbr <- VM.read nbr i
      forM_ iNbr $ \j -> do
        j_index <- VUM.read index j
        if j_index == (-1)
          then do
            body j
            x <- VUM.read lowlink j
            VUM.modify lowlink (min x) i
          else do
            p <- VUM.read onStack j
            when p (VUM.modify lowlink (min j_index) i)
      i_lowlink <- VUM.read lowlink i
      i_index   <- VUM.read index i
      when (i_lowlink == i_index) $ do
        st <- readSTRef stack
        t <- readSTRef tVal
        let (lst1, lst2) = span (/= i) st
        forM_ (i:lst1) $ \j -> do
          VUM.write onStack j False
          VUM.write results j t
        writeSTRef stack (tail lst2)
        modifySTRef tVal (+ 1)
          
