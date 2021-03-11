{-# LANGUAGE BangPatterns #-}

func1 :: Int -> IO Bool
func1 3 = return True
func1 10 = undefined
func1 _ = return False

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

lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

{-
  sumM   = lzFold' (+) 0
  prodM  = lzFold' (+) 1
  mSumM  = lzFold' mAdd 0
  mProdM = lzFold' mMul 1
  maximumM xs = lzFold' max (head xs) (tail xs)
  minimumM xs = lzFold' min (head xs) (tail xs)
  ...
-}
