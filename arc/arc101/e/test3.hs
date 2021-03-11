import Data.List
import qualified Data.Vector as V
import Data.Vector.Unboxed ((!))
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM

convolve :: Num a => [a] -> [a] -> [a]
convolve xs ys =
  map (sum . zipWith (*) (reverse ys))
      (init (tails (replicate (length ys - 1) 0 ++ xs)))

foo = V.fromList [0..10]
bar = VU.fromList [0..10]
baz :: Int
baz = foo V.! 3 + bar ! 5
