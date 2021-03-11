{-
  lazily evaluate monadic operations in lists
-}

-- and, or, all, any

ite3 :: a -> a -> Bool -> a
ite3 t e c = if c then t else e

(&&&) :: Monad m => m Bool -> m Bool -> m Bool
ma &&& mb = ma >>= ite3 mb (return False)

andM :: Monad m => [m Bool] -> m Bool
andM = foldr (&&&) (return True)

(|||) :: Monad m => m Bool -> m Bool -> m Bool
ma ||| mb = ma >>= ite3 (return True) mb

orM :: Monad m => [m Bool] -> m Bool
orM = foldr (|||) (return False)

allM :: Monad m => (a -> m Bool) -> [a] -> m Bool
allM act = andM . map act

anyM :: Monad m => (a -> m Bool) -> [a] -> m Bool
anyM act = orM . map act

-- sumM, prodM, mSumM, maximumM, ...

lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

lzFold1' :: Monad m => (a -> a -> a) -> [m a] -> m a
lzFold1' op (ma:mas) = ma >>= flip (lzFold' op) mas

sumM :: Monad m => [m Int] -> m Int
sumM = lzFold' (+)  0

prodM :: Monad m => [m Int] -> m Int
prodM = lzFold' (*)  1

maximumM :: (Monad m, Ord a) => [m a] -> m a
maximumM = lzFold1' max

minimumM :: (Monad m, Ord a) => [m a] -> m a
minimumM = lzFold1' min

-- You need definitions of mAdd and mMul from mod.hs

mSumM :: Monad m => [m Int] -> m Int
mSumM = lzFold' mAdd 0

mProdM :: Monad m => [m Int] -> m Int
mProdM = lzFold' mMul 1

