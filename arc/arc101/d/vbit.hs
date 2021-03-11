{-# LANGUAGE BangPatterns #-}
{-
  This code was written after reading the editorial.
-}

import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.ByteString.Lazy.Char8 as B
import Control.Monad.Primitive
import Data.Function
import Data.List
import Data.Maybe
import Control.Monad
import Control.Monad.ST
import Data.Bits
import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = binsch (minimum as) (maximum as + 1)
  where
    binsch xMin xMax | xMin + 1 == xMax = xMin
                     | try mid n as     = binsch mid xMax
                     | otherwise        = binsch xMin mid
      where mid = (xMax + xMin) `div` 2

try :: Int -> Int -> [Int] -> Bool
try x n as =
  t >= ((n * (n+1) `div` 2) + 1) `div` 2
  where
    t = numIncr (2*n + 1) ss
    ss = scanl' (+) (n+1) $ map (\a -> if a >= x then 1 else -1) as

numIncr lim as = runST $ do
  v <- VUM.replicate (lim+1) 0
  sub v 0 as
  where
    sub v !acc [] = return acc
    sub v !acc (a:as) = do
      y <- bit_intv v a
      bit_add v lim a 1
      sub v (acc+y) as

{--
  bit_add v n i x ... a_i += x
--}
bit_add :: VUM.MVector s Int -> Int -> Int -> Int -> ST s ()
bit_add v n i x = sub i
  where
    sub !j | j > n     = return ()
           | otherwise = do
               VUM.modify v (+ x) j
               sub (j + (j .&. (-j)))

{--
  bit_intv v i    ... \Sum_{j=1}^{i} a_i
--}
bit_intv :: VUM.MVector s Int -> Int -> ST s Int
bit_intv v i = sub 0 i
  where
    sub !acc 0 = return acc
    sub !acc !j = do
      y <- VUM.read v j
      sub (acc+y) (j - (j .&. (-j)))

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> Int
tmain cont =
  let n : as = bsReadInts cont
  in solve n as

main = putStrLn . show . tmain =<< B.getContents
  
----------------------------------------------------------------------

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5

test1 = tv1 == 30
test2 = tv2 == 10
test3 = tv3 == 8
test4 = tv4 == 3
test5 = tv5 == 3
alltest = test1 && test2 && test3 && test4 && test5

inp1 = "\
\3\n\
\10 30 20\n\
\"

inp2 = "\
\1\n\
\10\n\
\"

inp3 = "\
\10\n\
\5 9 5 9 8 9 3 5 4 3\n\
\"

inp4 = "\
\4\n\
\1 2 3 4\n\
\"

inp5 = "\
\4\n\
\1 4 2 3\n\
\"

