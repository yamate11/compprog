{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [[Int]] -> Int
solve bN ass = answer
  where
  compat i j = (aV V.! i) VU.! j
    where aV = V.fromListN bN (map (VU.fromListN bN) ass)
  nps :: Int
  nps = 2 ^ bN
  isFull = nps - 1
  answer = runST $ do
    vec <- VUM.replicate nps 0
    forM_ [0..bN-1] $ \i -> forM_ [i+1..bN-1] $ \j -> do 
      let comp = compat i j
          isIJ = (bit i) `setBit` j
          isK = isFull `xor` isIJ
      mapM_ (VUM.modify vec (+ comp)) (map (.|. isIJ) (powerset isK))
    forM_ [0..isFull] $ \isK -> do
      forM_ (powerset isK) $ \isX -> do
        x <- VUM.read vec isX
        y <- VUM.read vec (isK `xor` isX)
        VUM.modify vec (max (x+y)) isK
    VUM.read vec isFull

-------------------------------------------------------------------------------

powerset :: (Bits a, Num a) => a -> [a]
powerset a = a : unfoldr f a
  where f 0 = Nothing
        f x = let t = a .&. (x-1) in Just (t, t)

lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

lzFold1' :: Monad m => (a -> a -> a) -> [m a] -> m a
lzFold1' op (ma:mas) = ma >>= flip (lzFold' op) mas

maximumM :: (Monad m, Ord a) => [m a] -> m a
maximumM = lzFold1' max


readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      ass = map (map readBInt) remLines1
  in solve bN ass

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n0 10 20\n10 0 -100\n20 -100 0\n"
inp2 = "2\n0 -10\n-10 0\n"
inp3 = "4\n0 1000000000 1000000000 1000000000\n1000000000 0 1000000000 1000000000\n1000000000 1000000000 0 -1\n1000000000 1000000000 -1 0\n"
inp4 = "16\n0 5 -4 -5 -8 -4 7 2 -4 0 7 0 2 -3 7 7\n5 0 8 -9 3 5 2 -7 2 -7 0 -1 -4 1 -1 9\n-4 8 0 -9 8 9 3 1 4 9 6 6 -6 1 8 9\n-5 -9 -9 0 -7 6 4 -1 9 -3 -5 0 1 2 -4 1\n-8 3 8 -7 0 -5 -9 9 1 -9 -6 -3 -8 3 4 3\n-4 5 9 6 -5 0 -6 1 -2 2 0 -5 -2 3 1 2\n7 2 3 4 -9 -6 0 -2 -2 -9 -3 9 -2 9 2 -5\n2 -7 1 -1 9 1 -2 0 -6 0 -6 6 4 -1 -7 8\n-4 2 4 9 1 -2 -2 -6 0 8 -6 -2 -4 8 7 7\n0 -7 9 -3 -9 2 -9 0 8 0 0 1 -3 3 -6 -6\n7 0 6 -5 -6 0 -3 -6 -6 0 0 5 7 -1 -5 3\n0 -1 6 0 -3 -5 9 6 -2 1 5 0 -2 7 -8 0\n2 -4 -6 1 -8 -2 -2 4 -4 -3 7 -2 0 -9 7 1\n-3 1 1 2 3 3 9 -1 8 3 -1 7 -9 0 -6 -8\n7 -1 8 -4 4 1 2 -7 7 -6 -5 -8 7 -6 0 -9\n7 9 9 1 3 2 -5 8 7 -6 3 0 1 -8 -9 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 20
test2 = tv2 == 0
test3 = tv3 == 4999999999
test4 = tv4 == 132
alltest = test1 && test2 && test3 && test4

