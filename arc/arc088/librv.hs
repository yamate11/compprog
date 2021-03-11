import Data.List

data RedVec a

data RVtree a = RVleaf (Maybe a) | RVnode Int Int (RVtree a) (RVtree a)

-- number of a's
numAsCO :: Bool -> RVtree a -> Int
numAsCO _ (RVleaf Nothing) = 0
numAsCO _ (RVleaf (Just a)) = 1
numAsCO b (RVnode nC nO _ _) = if b then nC else nO

numAsC = numAsCO True
numAsO = numAsCO False

getCO :: (RVtree a -> Int) -> RVtree a -> Int -> a
getCO _ (RVleaf Nothing) _ = error "out of range"
getCO _ (RVleaf (Just a)) _ = a
getCO numAs (RVnode nC nO rvt1 rvt2) i = 
  let n1 = numAs rvt1
  in if i < n1 then getCO numAs rvt1 i
     else           getCO numAs rvt2 (i - n1)

removeCO :: (RVtree a -> Int) -> RVtree a -> Int -> RVtree a
removeCO _ (RVleaf Nothing) _ = error "out of range"
removeCO _ (RVleaf (Just a)) _ = RVleaf Nothing
removeCO numAs (RVnode nC nO rvt1 rvt2) i =
  let n1 = numAs rvt1
  in if i < n1 then RVnode (nC - 1) nO (removeCO numAs rvt1 i) rvt2
     else           RVnode (nC - 1) nO rvt1 (removeCO numAs rvt2 (i - n1))

removeC = removeCO numAsC
removeO = removeCO numAsO

constFromList :: [a] -> RVtree a
constFromList as = cFL (length as) as

cFL :: Int -> [a] -> RVtree a
cFL 0 [] = RVleaf Nothing
cFL 1 [a] = RVleaf (Just a)
cFL n as = let n1 = n `div` 2
               n2 = n - n1
               (as1, as2) = splitAt n1 as
           in RVnode n n (cFL n1 as1) (cFL n2 as2)
