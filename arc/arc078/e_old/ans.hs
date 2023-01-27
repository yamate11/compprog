{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import System.IO
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ = id

solve :: Maybe Int -> IO Int
solve nForTest =
  ask (10^10) >>= ite3 (binsch2 1 0 9) (binsch (10^8) (10^9 - 1))
  where

  binsch :: Int -> Int -> IO Int
  binsch lo hi
    | lo + 1 == hi = phase2 hi
    | otherwise = do
        let mi = (lo + hi) `div` 2
        ask (mi * 10) >>= ite3 (binsch lo mi) (binsch mi hi)
    
  phase2 :: Int -> IO Int
  phase2 n = binsch2 b 0 (k+1)
    where (b,k) = nDiv10 0 n
  
  binsch2 :: Int -> Int -> Int -> IO Int
  binsch2 b x y
    | x == y = return $ b * (10 ^ x)
    | otherwise = do
        let mL = (x + y) `div` 2
            mR = mL + 1
            t = (b * 10^mL + b * 10^mR) `div` 2
            cons = isConsis (b * (10 ^ x)) t
        ask t >>= ite3 (binsch2 b x mL) (binsch2 b mR y) . (== cons)
  
  ask :: Int -> IO Bool
  ask n = traceLM "ask" (n,) z
    where z = askX n
  askX n = sub n nForTest where
    sub n (Just n0) = return $ isConsis n n0
    sub n Nothing = do
      putStrLn $ "? " ++ show n
      line <- getLine
      let [resp] = words line
      return $ resp == "Y"

nDiv10 :: Int -> Int -> (Int, Int)
nDiv10 !acc n | r == 0 = nDiv10 (acc+1) d
              | otherwise = (n,acc)
  where (d,r) = divMod n 10
  
isConsis :: Int -> Int -> Bool
isConsis a b = traceL "isConsis" (a,b,z) z
  where z = isConsisX a b
isConsisX a b = (a < b) == (show a < show b)

main :: IO ()
main = do
  hSetBuffering stdin  NoBuffering
  hSetBuffering stdout NoBuffering
  n <- solve Nothing
  putStrLn $ "! " ++ show n
  
-------------------------------------------------------------------------------

ite3 :: a -> a -> Bool -> a
ite3 t e i = if i then t else e

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

-------------------------------------------------------------------------------

lstTest = [1,10,100,10^9,3712,5000,60000,789000000,949741092,
           9,979,999,999000,10^9-1]
alltest = do
  forM_ lstTest $ \n -> do
    m <- solve (Just n)
    unless (m == n) (error ("Test Failed.  " ++ show (n,m)))
  putStrLn "pass."
  
