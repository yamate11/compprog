{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [(Int,Int)] -> Int
solve n xrs = runST act0
  where
    u0:us = concatMap (sort . map snd) $ groupBy f
                $ sortOn fst [(x-r, x+r) | (x,r) <- xrs]
      where f (u1, _) (u2, _) = u1 == u2

    act0 :: forall s. ST s Int
    act0 = do
      vec <- VUM.new (2*(n+1))
      VUM.write vec n u0
      act1 vec
      where
      act1 :: VUM.MVector s Int -> ST s Int
      act1 vec = act n n us where

        act lo hi [] = return $ hi - lo + 1
        act lo hi (u:us) = VUM.read vec hi >>= selectH
          where
          go :: Int -> Int -> Int -> ST s Int
          go newlo newhi idx = do
            VUM.write vec idx u
            act newlo newhi us

          selectH vhi
            | vhi <= u = go lo hi hi
            | otherwise = VUM.read vec lo >>= selectL

          selectL vlo
            | u < vlo  = go (lo-1) hi (lo-1) 
            | u == vlo  = act lo hi us
            | otherwise = binsch lo hi >>= go lo hi

          binsch lo hi
            | hi == lo + 1 = return lo
            | otherwise = VUM.read vec mid >>= sub
            where
              mid = (lo + hi) `div` 2
              sub vmid | vmid == u = return mid
                       | u < vmid  = binsch lo mid
                       | vmid < u  = binsch mid hi

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      xrs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n xrs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3\n1 1\n0 3\n3 2\n"
inp2 = "2\n1 1\n2 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == 2
test2 = tv2 == 1
alltest = test1 && test2
