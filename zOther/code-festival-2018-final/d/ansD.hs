-------------------------------------------------------------------------------
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.List
import Data.Bits
import Debug.Trace

solve d bigF bigT n xs = calc
  where
    xsa = 0 : xs ++ [d]

    coe = VU.fromList $ 0 : inchworm p xsa
      where p x y = y - x <= bigF - bigT

    ranL = VU.fromList (0 : inchworm p xsa)   -- excl
      where p x y = x - y > bigF

    ranH = VU.fromList (0 : inchworm p xsa)   -- incl
      where p x y = x - y >= bigF - bigT

    calc = runST $ do
      trace ("coe = " ++ show coe) (return ())
      trace ("ranL = " ++ show ranL) (return ())
      trace ("ranR = " ++ show ranH) (return ())
      let size = n+2
      vbit <- VUM.replicate (size+1) 0
      bit_add size vbit 1 1
      forM_ [1..size] $ \i -> do
        trace ("i = " ++ show i) (return ())
        s <- bit_int_sum vbit (i + (ranL VU.! i)) (i + (ranH VU.! i))
        bit_add size vbit i (s `mMul` (2 `mPow` (coe VU.! i)))
        cs <- bit_debug_cont size vbit
        trace ("vals = " ++ show cs) (return ())
      bit_int_sum vbit (n+1) (n+2)

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

{-
  BIT
    params: vbit ... VUM.Vector
            size ... Int
    Indices 1..size of vbit are used.
    That is, the length of vbit should be size+1 (or more) and
    vbit[0] will not be used.
-}

bit_int_sum vbit x y = mSub <$> bit_sum vbit y <*> bit_sum vbit x

bit_sum vbit i = mSum <$> mapM (VUM.read vbit) (sum_indices i)

bit_add size vbit i x = 
  forM_ (add_indices size i) (VUM.modify vbit (mAdd x))

sum_indices = unfoldr f
  where f i | i == 0 = Nothing
            | otherwise = Just (i, i - (lsb i))

add_indices size = unfoldr f
  where f i | i > size = Nothing
            | otherwise = Just (i, i + (lsb i))

lsb i = i .&. (-i)

bit_debug_cont size vbit = forM [1..size] (\i -> bit_int_sum vbit (i-1) i)


mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (mPrime + x - y) `mod` mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

mPow :: Int -> Int -> Int
mPow x y
  | y < 0 = error "mPow: negative"
  | otherwise = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x
    
mSum = foldl' mAdd 0

--           d bigF bitT n xs
val1 = solve 10 8    5   2 [3,7]
test1 = val1 == 2
{-
    1     2     3     4
    0     3     7    10

          [1

-}
val2 = solve 8 8 5 5 [1,2,3,4,5]
test2 = val2 == 32
val3 = solve 100 50 30 1 [40]
test3 = val3 == 0
val4 = solve 1000 752 681 10 [94,186,299,395,406,430,772,782,807,999]
test4 = val4 == 1002

alltest = test1 && test2 && test3 && test4
