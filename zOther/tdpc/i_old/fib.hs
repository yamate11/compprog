{-# LANGUAGE BangPatterns #-}

import System.Environment
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.ST

spec _ 0 = 1
spec _ 1 = 1
spec mf n = mf (n-2) + mf (n-1)

data Tree a = Tree (Tree a) a (Tree a)
instance Functor Tree where
  fmap f (Tree l m r) = Tree (fmap f l) (f m) (fmap f r)

index :: Tree a -> Int -> a
index (Tree _ m _) 0 = m
index (Tree l _ r) n =
  case (n - 1) `divMod` 2 of
    (q,0) -> index l q
    (q,1) -> index r q

nats :: Tree Int
nats = go 0 1 where
  go !n !s = Tree (go l s') n (go r s') where
    l = n + s
    r = l + s
    s' = s * 2

f_tree :: Tree Int
f_tree = fmap (spec fastest_f) nats

fastest_f :: Int -> Int
fastest_f = index f_tree

withgen :: Int -> Int
withgen n = head (drop n gen)

gen = unfoldr f (1,1)
  where f (n,m) = Just (n, (m, n+m))

withvec :: Int -> Int
withvec n = runST $ do
  v <- VUM.replicate (n+1) (-1)
  act v n
  where
    act :: VUM.MVector s Int -> Int -> ST s Int
    act v 0 = return 1
    act v 1 = return 1
    act v n = do
      x <- VUM.read v n
      if x >= 0 then return x else do
        y1 <- act v (n-1)
        y2 <- act v (n-2)
        VUM.write v n (y1+y2)
        return (y1+y2)

main :: IO ()
main = do
  [x] <- getArgs
  putStrLn $ show $ fastest_f (read x)
  -- putStrLn $ show $ withgen (read x)
  -- putStrLn $ show $ withvec (read x)
