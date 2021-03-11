{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE AllowAmbiguousTypes #-}
{-# LANGUAGE RankNTypes #-}

import Data.List
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.Primitive
import Control.Monad.ST
import Control.Monad
import Data.List
import Debug.Trace

type VUM2Vec m a = (VUM.MVector (PrimState m) a, Int)
type VU2Vec a = (VU.Vector a, Int)

vum2new :: (PrimMonad m, VUM.Unbox a) => (Int,Int) -> m (VUM2Vec m a)
vum2new (p,q) = do
  arr <- VUM.new (p*q)
  return (arr, p)

vum2replicate :: (PrimMonad m, VUM.Unbox a)
              => (Int,Int) -> a -> m (VUM2Vec m a)
vum2replicate (p,q) a = do
  arr <- VUM.replicate (p*q) a
  return (arr, p)

vum2read :: (PrimMonad m, VUM.Unbox a)
         => VUM2Vec m a -> (Int,Int) -> m a
vum2read (arr,p) (x,y) = VUM.read arr (x+p*y)

vum2write :: (PrimMonad m, VUM.Unbox a)
          => VUM2Vec m a -> (Int,Int) -> a -> m ()
vum2write (arr,p) (x,y) a = VUM.write arr (x+p*y) a

vu2create :: forall a. VU.Unbox a
          => (forall s. ST s (VUM2Vec (ST s) a)) -> VU2Vec a
vu2create act = runST $ do
  (marr,p) <- act
  arr <- VU.unsafeFreeze marr
  return (arr, p)

vu2lookup :: VU.Unbox a => VU2Vec a -> (Int,Int) -> a
vu2lookup (arr,p) (x,y) = arr VU.! (x+p*y)

vu2fromList :: VU.Unbox a => Maybe Int -> [[a]] -> VU2Vec a
vu2fromList Nothing ass = vu2fromList (Just (length (head ass))) ass
vu2fromList (Just p) ass = (VU.fromList (concat ass), p)


-- bsReadInts bstr
--   Reads and returns the list of int separated by space.
--   Usually bstr is one line, but can consist of two or more lines.
bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

-------------------------------------------------------------------------------
solve :: Int -> Int -> Int -> [(Int,Int)] -> [(Int,Int)] -> [Int]
solve n m _ lrs pqs = map f pqs
  where 
    tbl = vu2create $ act n m lrs
    (arr, _) = tbl
    f (p,q) = vu2lookup tbl (q,q) - vu2lookup tbl (p-1,q)
    
act :: Int -> Int -> [(Int,Int)] -> ST s (VUM2Vec (ST s) Int)
act n m lrs = do
  tbl <- vum2replicate (n+1,n+1) 0
  forM_ lrs $ \(l,r) -> do
    z <- vum2read tbl (l,r)
    vum2write tbl (l,r) (z+1)
  forM_ [1..n] $ \l -> accum1 n l tbl l 0
  forM_ [1..n] $ \r -> accum2 n r tbl 1 0
  return tbl

accum1 :: Int -> Int -> VUM2Vec (ST s) Int -> Int -> Int -> ST s ()
accum1 n l tbl r a
  | r == n+1 = return ()
  | otherwise = do
      t <- vum2read tbl (l,r)
      vum2write tbl (l,r) (a+t)
      accum1 n l tbl (r+1) (a+t)

accum2 :: Int -> Int -> VUM2Vec (ST s) Int -> Int -> Int -> ST s ()
accum2 n r tbl l a
  | l == r+1 = return ()
  | otherwise = do
      t <- vum2read tbl (l,r)
      vum2write tbl (l,r) (a+t)
      accum2 n r tbl (l+1) (a+t)

tmain :: B.ByteString -> [Int]
tmain cont =
  let line1 : rest = B.lines cont
      [n,m,q] = bsReadInts line1
      (part1, part2) = splitAt m rest
      form lines = map ((\[s,e] -> (s,e)) . bsReadInts) lines
  in solve n m q (form part1) (form part2)

main :: IO ()
main = do
  cont <- B.getContents
  putStr $ unlines $ map show $ tmain cont

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == [3]
test2 = tv2 == [1,1]
test3 = tv3 == [7,9,10,6,8,9,6,7,8,10]
alltest = test1 && test2 && test3

inp1 = "\
\2 3 1\n\
\1 1\n\
\1 2\n\
\2 2\n\
\1 2\n\
\"

inp2 = "\
\10 3 2\n\
\1 5\n\
\2 8\n\
\7 10\n\
\1 7\n\
\3 10\n\
\"

inp3 = "\
\10 10 10\n\
\1 6\n\
\2 9\n\
\4 5\n\
\4 7\n\
\4 7\n\
\5 8\n\
\6 6\n\
\6 7\n\
\7 9\n\
\10 10\n\
\1 8\n\
\1 9\n\
\1 10\n\
\2 8\n\
\2 9\n\
\2 10\n\
\3 8\n\
\3 9\n\
\3 10\n\
\1 10\n\
\"
