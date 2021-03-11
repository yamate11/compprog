import Data.List
import Data.Bits
import Control.Monad
import Control.Monad.ST
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM



{-
  inchworm pred xs == is
  <=> k0 = (is !! j) is the largest k s.t.
          pred (xs !! j) (xs !! (j + k))
      holds.  Note that
      - pred should be decreasing: pred x y && y' < y => pred x y'
      - k0 can be negative.
      - if there is not such k, j+k0 := -1
-}
inchworm :: (a -> a -> Bool) -> [a] -> [Int]
inchworm pred xs = unfoldr f (0, xs, xs)
  where
    f (_, [], _)    = Nothing
    f (s, x:xs, ys) = Just (s', (s', xs, y2s))
      where (y1s, y2s) = span (pred x) ys
            s' = s - 1 + length y1s

test_inchworm_1 = 
    [2,1,1,2,1,1,1,0]
    == inchworm (\x y -> y <= x+5) [1,4,5,10,11,14,18,20]
test_inchworm_2 = 
    [-1,-2,-3,-1,-2,-3,-2,-2]
    == inchworm (\x y -> y <= x-5) [1,4,5,10,11,14,18,20]


{-
  BIT
    params: vbit ... VUM.Vector
            size ... Int
    Indices 1..size of vbit are used.
    That is, the length of vbit should be size+1 (or more) and
    vbit[0] will not be used.
-}

bit_int_sum vbit x y = (-) <$> bit_sum vbit y <*> bit_sum vbit x

bit_sum vbit i = sum <$> mapM (VUM.read vbit) (sum_indices i)

bit_add size vbit i x = 
  forM_ (add_indices size i) (VUM.modify vbit (+ x))

sum_indices = unfoldr f
  where f i | i == 0 = Nothing
            | otherwise = Just (i, i - (lsb i))

add_indices size = unfoldr f
  where f i | i > size = Nothing
            | otherwise = Just (i, i + (lsb i))

bit_debug_cont size vbit = forM [1..size] (\i -> bit_int_sum vbit (i-1) i)

lsb i = i .&. (-i)

size=8
act = runST $ do
  vbit <- VUM.replicate (size+1) (0 :: Int)
  bit_add size vbit 2 4
  bit_add size vbit 6 3
  bit_add size vbit 5 2
  bit_add size vbit 2 4
  forM [1..size] $ \i -> do
    bit_int_sum vbit 0 i
