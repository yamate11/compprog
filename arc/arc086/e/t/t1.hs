-- {-# LANGUAGE RankNTypes #-}

import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Mutable as VM
import Control.Monad.ST
import Data.Foldable


k :: Int
k = 1000000007
-- k = 100

n :: Int
n = 200000
-- n = 10

vecPow :: VU.Vector Int
vecPow = VU.iterateN (n + 1) f 1
  where f x = (x * 2) `rem` k

foo :: VU.Vector Int
foo = VU.fromList [0, 0, 1, 2, 0, 3, 1, 4]

revv :: V.Vector [Int]
revv = V.create f
  where
    f :: ST s (V.MVector s [Int])
    f = do
      let len = VU.length foo
      v <- VM.replicate (len + 1) []
      for_ [1 .. len] $ \i -> VM.modify v (i :) (foo VU.! (i - 1))
      return v

main = do
  putStrLn $ show $ vecPow VU.! n
