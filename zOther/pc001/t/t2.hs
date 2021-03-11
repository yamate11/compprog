{-# LANGUAGE ScopedTypeVariables #-}
-- import qualified Data.Vector as VB
-- import qualified Data.Vector.Mutable as VBM
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a


func1 :: Int
func1 = sv V.! i
  where act2 = act1 >>= return . fst
        sv = V.create act2
        act3 = act1 >>= return . snd
        i = runST act3


act1 :: forall s. ST s (VM.MVector s Int, Int)
act1 = do
  vec <- VM.replicate 10 0
  VM.write vec 3 200
  VM.write vec 5 (trace "vec5" 400)
  return (vec, 5)
