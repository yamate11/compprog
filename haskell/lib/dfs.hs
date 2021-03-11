{-# LANGUAGE ScopedTypeVariables #-}

{-
DFS - Depth First Search
-}

import qualified Data.Set as S
import Control.Monad.State
import System.Environment

type SchState s a = State (S.Set s, a)

-- naive implementation
dfs :: forall s a. (Eq s, Ord s) =>
       (s -> [s]) -> (a -> s -> a) -> s -> a -> a
dfs children valUpd initS initA = a
  where
    (_, (_, a)) = runState act (S.empty, initA) 

    act :: SchState s a ()
    act = aDfs initS

    aDfs :: s -> SchState s a ()
    aDfs s0 = do
      (visited, curA) <- get
      if S.member s0 visited
        then return ()
        else do
        put (S.insert s0 visited, valUpd curA s0)
        forM_ (children s0) aDfs

-- tail recursion version
dfsTR :: forall s a. (Ord s) =>
         (s -> [s]) -> (a -> s -> a) -> s -> a -> a
dfsTR children valUpd initS initA = 
  f S.empty initA [[initS]]
  where
    f :: (S.Set s) -> a -> [[s]] -> a
    f _ a [] = a
    f visited a ([] : sss) = f visited a sss
    f visited a ((s : ss) : sss) =
      if S.member s visited then f visited a (ss : sss)
      else f (S.insert s visited) (valUpd a s) ((children s) : ss : sss)
    -- You may want f to be strict on argument a,
    -- but we did not see much difference (in a simple case)
    -- by comparing executables with -O option.

test1 :: [Int]
test1 = reverse $ dfsTR t1Children t1ValUpd 1 []
  where
    t1Children n = [n * 2, n * 3 .. 50]
    t1ValUpd recd n = n : recd
-- test1 == [1,2,4,8,16,32,48,24,40,12,36,20,28,44,6,18,30,42,10,50,14,22,26,34,38,46,3,9,27,45,15,21,33,39,5,25,35,7,49,11,13,17,19,23,29,31,37,41,43,47]

test2 :: Int -> Int
test2 nMax = dfsTR t1Children t1ValUpd 1 0
  where
    t1Children n = [n * 2, n * 3 .. nMax]
    t1ValUpd recd n = n + recd

main :: IO ()
main = do
  a1 : _ <- getArgs
  putStrLn $ show $ test2 $ read a1

{-
According to an experimental measurement,
Tail Recursion version is a bit faster than naive version,
in -O and -O2 settings.
(0.37s vs 0.58s, for 10^5 states
-}
