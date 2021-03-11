{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE RankNTypes #-}

-------------------------------------------------------------------------------

import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Primitive
-- import Debug.Trace

memovec :: forall a d. (VU.Unbox a, Show a, Show d) =>
           (d -> Int) -> Int -> 
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> VU.Vector a
memovec encode size mf ds = VU.create $ do
  vec <- VUM.new size
  flags <- VUM.replicate size False
  mapM_ (calc vec flags) ds
  return vec
  where
    calc vec flags d = do
      fv <- VUM.read flags (encode d)
      if fv then VUM.read vec (encode d)
        else do
        val <- mf (calc vec flags) d
        VUM.write vec   (encode d) val
        VUM.write flags (encode d) True
        return val

func_memo :: VU.Unbox a => (d->Int) -> VU.Vector a -> d -> a
func_memo encode vecV d = vecV VU.! (encode d)

----------------------------------------------------------------------
-- Usage:

{-
  Memoization

  "memovec mf size" is a function created from mf using vector 
  memoization.
  mf defines the calculation of the vector.  For example, if you
  want the fibonacci function: 
-}

mf :: Monad m => (Int -> m Int) -> Int -> m Int
mf pre 0 = return 1
mf pre 1 = return 1
mf pre n = (+) <$> pre (n-1) <*> pre (n-2)

{-
  What makes the definition complicated is the existence of monad.
  This is inevitable because we use vectors.

  If we could use lists, definitions will be simpler:

    mf' :: (Int -> Int) -> Int -> Int
    mf' pre' 0 = 0
    mf' pre' 1 = 1
    mf' pre' n = (pre' (n-1)) + (pre' (n-2))

  pre' is a prefix of the function being defined.  For calculating n,
  we need the values of n-1 and n-2.  To access those values
  we use function pre'.  And the rest is:

    lst' = map (mf' fib') [0..]
    fib' n = lst' !! n

  However, we want to use vectors (MVector) for performance.
  Calculated values stored in MVectors need to be accessed by action
             VUM.read :: MVector -> Int -> m a
  instead of a pure function.  Thus, the type of mf must be as above.
  The following rewrite might help to understand what to do:

    mf pre 0 = return 1
    mf pre 1 = return 1
    mf pre n = liftM2 g (pre (n-1)) (pre (n-2))
      where g x y = x + y

  I.e., write a pure function g with args that will be filled with
  (pre xx), and use liftM? to get an action.

  The following version does not work, unfortunately:
    mf pre g = liftM3 g (return n) (pre (n-1)) (pre (n-2))
      where g 0 _ _ = 1
            g 1 _ _ = 1
            g _ x y = x + y
  because, in "liftM3 f x1 x2 x3", x's are evaluated before they
  are passed to f.

  Haskell vectors only supports Int as indices, so we may need
  encoding/decoding functions.  When indices are happen to be Int,
  you specify function id for both encoding and decoding.

  memovec makes memo in a lazy way.  It starts the value you supplied
  as goals.  Values that are not needed for the goals are remained
  undefined.

  Now, Fibonacci function (up to 100000, mod 2^64) can be defined
  as follows:
-}

memo_fib = memovec id 100001 mf [100000]
fib :: Int -> Int
fib = func_memo id memo_fib



{-
Dynamic Programming

Example (Knapsack)
  For given items [(weight_i, value_i) | 0 <= i < n0], choose items
  so that the sum of values gets maximized while the sum of weights
  is equal to or less than w0.

DP:
  dp[k][w] := the max of the sum of values from items < k
              while the sum of weights <= w

  dp[0][w] = 0
  dp[k][w] = max(dp[k-1][w-weight[k-1]] + value[k-1],
                 dp[k-1][w]                         )  if weight[k-1] <= w
           = dp[k-1][w]                                ow
-}

weight_value_pair :: [(Int,Int)]
weight_value_pair = [(2,3),(1,2),(3,6),(2,1),(1,3),(5,85)]
weight = VU.fromList $ map fst $ weight_value_pair
value  = VU.fromList $ map snd $ weight_value_pair
n0 = 6
w0 = 8

type DP = (Int, Int)

enc :: DP -> Int
-- enc (k,w) | trace ("enc " ++ show (k,w)) False = undefined
enc (k,w) = k*(w0+1) + w

dec :: Int -> DP
-- dec i | trace ("dec " ++ show i) False = undefined
dec i = flip divMod (w0+1) i

{-
  We define mf1, which calculates a value using already calculated
  values.  "already calculated values" are captured using the first
  parameter pre.
-}


mf1 :: Monad m => (DP -> m Int) -> DP -> m Int
mf1 pre (0,w) = return 0
mf1 pre (k,w) | wshift >= 0 = liftM2 g1 (pre (k-1, wshift)) (pre (k-1, w))
              | otherwise   = pre (k-1, w)
  where wshift = w - weight VU.! (k-1)
        g1 x y = max (x + value VU.! (k-1)) y 

{-
  Using this function, the dp table can be extracted as follows
-}

memo_knapsack = memovec enc (enc (n0,w0) + 1) mf1 [(n0,w0)]
ans_knapsack = func_memo enc memo_knapsack (n0,w0)

