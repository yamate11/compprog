{-# LANGUAGE BangPatterns #-}
import Data.Bits
import Data.Foldable
import System.Environment
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad.ST
import Control.Monad
import Data.Trie

search :: [Bool] -> Bool
search = not . or . map search . nexts

nexts :: [Bool] -> [[Bool]]
nexts [] = []
nexts [False] = []
nexts [True] = [[]]
nexts (False : bs) = map (False :) (nexts bs)
nexts (True : bs) =
  map (False :) (bs : flips bs) ++ map (True :) (nexts bs)

flips :: [Bool] -> [[Bool]]
flips [b] = [[not b]]
flips (b : bs) = (not b : bs) : map (not b :) (flips bs)

toBits :: [Int] -> [Bool]
toBits = foldr f []
  where f x bs = True : take (x - (length bs) - 1) (repeat False) ++ bs

toInts :: [Bool] -> [Int]
toInts bs = reverse [i | (i, b) <- zip [1..] (reverse bs), b]

searchB :: Int -> Bool
searchB x = not $ or $ map searchB $ nextsB (topPos x) x

searchBV0 :: Int -> Bool
searchBV0 x = runST act
  where act :: ST s Bool
        act = do
          vec <- VM.replicate (x + 1) (-1)
          searchBV x vec
  

searchBV :: Int -> VM.MVector s Int -> ST s Bool
searchBV x vec = do
  let ys = nextsB (topPos x) x
  bs <- flip mapM ys $ \y -> do
    b <- VM.read vec y
    if b >= 0 then return (b > 0)
      else do
      newb <- searchBV y vec
      VM.write vec y (if newb then 1 else 0)
      return newb
  return (not (or bs))


think = [(i,j) | i <- [2 .. 14], j <- [1 .. (i-1)], 
         searchBV0 (toBitsB [i,j])]


nextsB :: Int -> Int -> [Int]
nextsB _ 0 = []
nextsB _ 1 = [0]
nextsB pos x
  | testBit x pos = (rem : flipsB pos rem)
                    ++ map (top .|.) (nextsB (pos - 1) rem)
  | otherwise = nextsB (pos - 1) x
  where top = (bit pos) .&. x
        rem = (complement (bit pos)) .&. x

flipsB :: Int -> Int -> [Int]
flipsB 1 0 = [1]
flipsB 1 1 = [0]
flipsB n x = complementBit x (n - 1) :
               map (newtop .|.)
                   (flipsB (n - 1) (clearBit x (n - 1)))
  where newtop = (bit (n - 1)) .&. (complement x)

toBitsB :: [Int] -> Int
toBitsB [] = 0
toBitsB (n : ns) = setBit (toBitsB ns) (n - 1) 

toIntsB :: Int -> [Int]
toIntsB x = toIntsBX 0 [] x
toIntsBX _ acc 0 = acc
toIntsBX i acc x = toIntsBX (i + 1) newacc (shiftR x 1)
  where newacc = if testBit x 0 then (i + 1) : acc else acc


topPos :: Int -> Int
topPos x = floor (logBase 2 (fromIntegral x))


  
