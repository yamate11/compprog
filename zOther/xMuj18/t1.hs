import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.Primitive
import Control.Monad.ST

-- act :: ST s (VUM.MVector s Int)
act :: ST s (VU.Vector Int)
act = do
  arr <- VUM.replicate 40 1
  VUM.write arr 5 20
  VU.unsafeFreeze arr

foo = (runST act) VU.! 5
