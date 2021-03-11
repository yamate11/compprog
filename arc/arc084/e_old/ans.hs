{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace

solve :: Int -> Int -> [Int]
solve k n | even k = take n $ (k `div` 2) : repeat k
          | otherwise = unfoldr ufM initState
  where
  trSizes = reverse $ take n $ takeWhile (<= n)
                $ iterate (\x -> k*x + 1) (k+1) ++ repeat (n+1)
  initState = (-1, trSizes)
  ufM x = trace ("ufM " ++ show (x,a)) a
    where a = ufMA x
  ufMA (acc, []) = Nothing
  ufMA (acc, (trs:trss)) | thisX == 0 = Nothing
                         | otherwise  = Just (thisX, newState)
    where acc' | even (trs - acc) = acc 
               | otherwise        = acc + 1
          thisX = (1 + k - (acc' `div` trs)) `div` 2
          newState = (newAcc, trss)
          newAcc = acc + 1 + 2 * (thisX - ((k+1) `div` 2))

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_k,bs_n]:remLines1 = remLines0
      k = readBInt bs_k
      n = readBInt bs_n
  in solve k n

outAnswer :: [Int] -> IO ()
outAnswer x = error "outAnswer: not implemented."

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------
{-

[odd]

acc = leftOut - rightOut

at epsilon: leftIn == 0, rightIn == treeSize * k
at 1-Right: leftIn == 1 + treeSize - 1  == treeSize
            rightIn == treeSize * (k-1)
at 2-Right: leftIn == 1 + treeSize + treeSize - 1 == 2*treeSize
            rightIn == treeSize * (k-2)
at k-Right: leftIn == k*treeSize
            rightIn == 0

Condition:
  0 or 1 == right - left
         == rightOut + rightIn - (leftOut + leftIn)
         == -acc + rightIn - leftIn

if treeSize*k - acc == 0 or 1 --> epsilon
otherwise
  treeSize * (k-1) - treeSize - acc <= 0 or 1  ---> 1
otherwise
  treeSize * (k-2) - 2*treeSize - acc == 0 or 1


if acc == treeSize*k - (0or1) --> epsilon
elif acc >= treeSize*(k-2) - (0or1) --> 1
...

acc + (0or1) / treeSize

== k      epsilon
>= k-2    1
>= k-4    2
>= -k     k


acc' = acc  if even(treeSize-acc)
     = acc+1 o.w.

(1 + k - (acc' // treeSize)) // 2



-}
