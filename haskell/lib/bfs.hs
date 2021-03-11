{-# LANGUAGE ViewPatterns, ScopedTypeVariables #-}
{-
BFS - Breadth First Search
-}
import qualified Data.Sequence as Q
import qualified Data.Set as S

bfs :: forall s a. (Ord s) => (s -> [s]) -> (a -> s -> a) -> s -> a -> a
bfs children valUpd initS initA =
  f S.empty initA (Q.fromList [initS])
  where
    f :: S.Set s -> a -> Q.Seq s -> a
    f _       a (Q.viewl -> Q.EmptyL)     = a
    f visited a (Q.viewl -> s Q.:< queue) =
      if (S.member s visited) then f visited a queue
      else f (S.insert s visited)
             (valUpd a s)
             (queue Q.>< Q.fromList (children s))

test1 :: [Int]
test1 = reverse $ bfs t1Children t1ValUpd 1 []
  where
    k = 19
    t1Children n = [2*n `mod` k , 3*n `mod` k, 4*n `mod` k]
    t1ValUpd recd n = n : recd
-- test1 = [1,2,3,4,6,8,9,12,16,18,5,13,17,10,7,15,14,11]
