mPrime = 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime
-- mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

