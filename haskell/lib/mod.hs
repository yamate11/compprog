import Data.List

mPrime = 10^9 + 7

-- mAdd x y = (x + y) `mod` mPrime
mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y
mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

-- eGCD a b = (g,s,t) ==> g = (a,b) = a*s + b*t
eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

mPow :: Int -> Int -> Int
mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x

mCombi n r | n-r < r = mCombi n (n-r)
mCombi n 0 = 1
mCombi n r = foldl1' mMul (d : [n-r+1..n])
  where d = mInv $ foldl1' mMul [1..r]


