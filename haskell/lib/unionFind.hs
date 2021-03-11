{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST


data UnionFind s = UnionFind {
  ufLeader :: VUM.MVector s Int,
  ufRank :: VUM.MVector s Int
}

ufInit :: Int -> ST s (UnionFind s)
{-# INLINE ufInit #-}
ufInit size = do
  leader <- VUM.new size
  forM_ [0..size-1] $ \i -> VUM.write leader i i
  rank <- VUM.replicate size 1
  return $ UnionFind { ufLeader = leader, ufRank = rank }
  
ufGetLeader :: UnionFind s -> Int -> ST s Int
{-# INLINE ufGetLeader #-}
ufGetLeader uf i = do
  x <- VUM.read (ufLeader uf) i
  if x == i
    then return i
    else do
      y <- ufGetLeader uf x
      VUM.write (ufLeader uf) i y
      return y

ufMerge :: UnionFind s -> Int -> Int -> ST s Int
{-# INLINE ufMerge #-}
ufMerge uf i j = do
  x <- ufGetLeader uf i
  y <- ufGetLeader uf j
  if x == y
    then return x
    else do
      rx <- VUM.read (ufRank uf) x
      ry <- VUM.read (ufRank uf) y
      case () of
        () | rx < ry -> _merge x y
           | rx > ry -> _merge y x
           | otherwise -> do
               VUM.modify (ufRank uf) (+ 1) y
               _merge x y
  where
    _merge x y = do
      VUM.write (ufLeader uf) x y
      return y

ufSameCC :: UnionFind s -> Int -> Int -> ST s Bool
{-# INLINE ufSameCC #-}
ufSameCC uf i j = (==) <$> ufGetLeader uf i <*> ufGetLeader uf j

----------------------------------------------------------------------

test1 :: String
test1 = runST $ act where
  act = do
    uf <- ufInit 10
    mapM_ (uncurry (ufMerge uf)) [(3,5),(2,5),(7,1),(9,1),(5,8)]
    b1 <- ufSameCC uf 3 8
    unless b1 (error "Failed A")
    b2 <- ufSameCC uf 3 7
    when b2 (error "Failed B")
    b3 <- ufSameCC uf 5 4
    when b3 (error "Failed C")
    return "OK"
