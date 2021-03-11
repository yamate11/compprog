{-# LANGUAGE BangPatterns #-}

import Data.Function (fix)

f :: (Int -> Int) -> Int -> Int
f mf 0 = 0
f mf n = max n $ mf (n `div` 2) + mf (n `div` 3) + mf (n `div` 4)

f_list :: [Int]
f_list = map (f faster_f) [0..]

faster_f :: Int -> Int
faster_f n = f_list !! n

data Tree a = Tree (Tree a) a (Tree a)
instance Functor Tree where
  fmap f (Tree l m r) = Tree (fmap f l) (f m) (fmap f r)

index :: Tree a -> Int -> a
index (Tree _ m _) 0 = m
index (Tree l _ r) n = case (n - 1) `divMod` 2 of
                         (q,0) -> index l q
                         (q,1) -> index r q

nats :: Tree Int
nats = go 0 1
  where
    go !n !s = Tree (go l s') n (go r s')
      where
        l = n + s
        r = l + s
        s' = s * 2

f_tree :: Tree Int
f_tree = fmap (f fastest_f) nats

fastest_f :: Int -> Int
fastest_f = index f_tree

g :: (Int -> Integer) -> Int -> Integer
g _ 0 = 1
g _ 1 = 1
g mg n = mg (n-1) + mg (n-2)

g_list :: [Integer]
g_list = map (g faster_g) [0..]

faster_g :: Int -> Integer
faster_g n = g_list !! n

g_tree :: Tree Integer
g_tree = fmap (g fastest_g) nats

fastest_g :: Int -> Integer
fastest_g = index g_tree

combi :: (Int -> Int -> Integer) -> Int -> Int -> Integer
combi c _ 0 = 1
combi c n r | n == r = 1
            | otherwise = c (n-1) (r-1) + c (n-1) r

com1 :: Int -> Int -> Integer
com1 = fix combi

{--
combi_list :: [[Integer]]
combi_list = [[combi com2 n r | r <- [0..]] | n <- [0..]]
             -- map (\n -> [combi com2 n r | r <- [0..]]) [0..]
             -- map (\n -> (map (combi com2 n) [0..])) [0..]
--}

mapNatList :: (Int -> a) -> [a]
mapNatList f = map f [0..]

combi_list :: [[Integer]]
combi_list = mapNatList (mapNatList . (combi com2))

com2 :: Int -> Int -> Integer
com2 n r = (combi_list !! n) !! r

mapNatTree :: (Int -> a) -> Tree a
mapNatTree f = fmap f nats

combi_tree :: Tree (Tree Integer)
combi_tree = mapNatTree (mapNatTree . (combi com3))

com3 :: Int -> Int -> Integer
com3 n r = index (index combi_tree n) r
