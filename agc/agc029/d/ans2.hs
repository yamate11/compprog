import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.ST
import Debug.Trace
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

type MyS = (Int, Int, [(Int, [Int])])

solve :: Int -> Int -> Int -> [(Int,Int)] -> Int
solve bigH bigW bigN xys = minH - 1
  where
  board0 = map f_form $ groupBy f_grp $ mysortOn f_sort xys
  f_grp (_,y) (_,y') = y == y'
  f_sort (x,y) = y * (bigH+1) + x
  f_form lst@((_,y):_) = (y, map fst lst)

  minH = minimum (catMaybes (unfoldr f_stUpd initState) ++ [bigH+1])
  initState :: MyS
  initState = (1, 1, board0)
  f_stUpd :: MyS -> Maybe (Maybe Int, MyS)
  f_stUpd (_, _, []) = Nothing
  f_stUpd (x, y, ((by, bxs):rem)) = Just (h, (newX, by, rem))
    where (newX, h) = vacSeat (x + (by - y)) bxs

-- vacSeat 5 [3,4,5,6] ---> (7,Nothing)
-- vacSeat 5 [3,4,5,6,10,12] ---> (7,Just 10)
vacSeat :: Int -> [Int] -> (Int, Maybe Int)
vacSeat t ts =
  head $ filter (\(p,q) -> Just p /= q) $ zip [t..]
  $ map Just (dropWhile (< t) ts) ++ [Nothing]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigH,bs_bigW,bs_bigN]:remLines1 = remLines0
      bigH = readBInt bs_bigH
      bigW = readBInt bs_bigW
      bigN = readBInt bs_bigN
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bigH bigW bigN xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------
mysort :: (Ord a, VU.Unbox a, Show a) => [a] -> [a]
mysort as = VU.toList $ runST $ do
  v <- VU.unsafeThaw (VU.fromList as)
  mymsort v
  VU.unsafeFreeze v

mysortOn :: (Ord a, Ord b, VU.Unbox a, VU.Unbox b, Show a, Show b) =>
            (a -> b) -> [a] -> [a]
mysortOn f as = VU.toList $ runST $ do
  v <- VU.unsafeThaw $ VU.fromList $ map (\a -> (f a, a)) as
  mymsort v
  (VU.map snd) <$> (VU.unsafeFreeze v)

mymsort :: (PrimMonad m, Ord a, VUM.Unbox a, Show a) =>
           VUM.MVector (PrimState m) a -> m ()
mymsort v = do
  let n = VUM.length v
  sub v 0 (n-1)
  where
  sub v lo hi
    | hi - lo <= 6 = myisort v lo hi
    | otherwise = do
        (pL, pR) <- mypartition v lo hi
--        vv <- VU.freeze v
--        sub v lo ((trace (show (vv, pL, pR)) pL)-1)
        sub v lo (pL-1)
        sub v (pR+1) hi

myisort v lo hi = do
  forM_ [lo+1..hi] $ \i -> do
    x <- VUM.read v i
    j <- sub_start lo i x
    VUM.unsafeMove (VUM.unsafeSlice (j+1) (i-j) v) (VUM.unsafeSlice j (i-j) v)
    VUM.write v j x
  where
    sub_start k i x
      | k == i = return i
      | otherwise = do
          y <- VUM.read v k
          if x < y then return k
                   else sub_start (k+1) i x

mypartition :: (PrimMonad m, Ord a, VUM.Unbox a, Show a) =>
               VUM.MVector (PrimState m) a -> Int -> Int -> m (Int, Int)
mypartition v lo hi = do
  let mid = (lo + hi) `div` 2
  xLo <- VUM.read v lo
  xMid <- VUM.read v mid
  xHi <- VUM.read v hi
  when (xMid < xLo) (VUM.swap v lo mid)
  when (xHi < xLo) (VUM.swap v lo hi)
  when (xMid < xHi) (VUM.swap v mid hi)
  pivot <- VUM.read v hi
--  (i0, j0) <- sub (trace ("pivot = " ++ show pivot) pivot) lo lo hi
  (i0, j0) <- sub pivot lo lo hi
  let w = min (j0-i0) (hi-j0+1)
  forM_ [0..w-1] $ \i -> VUM.swap v (i0+i) (hi-i)
  return (i0, i0+hi-j0+1-1)
  where
    sub pivot i0 j0 k0
      | j0 == k0  = return (i0, j0)
      | otherwise = VUM.read v j0 >>= sub2
      where sub2 x | x > pivot  = sub pivot i0 (j0+1) k0
                   | x == pivot = do
                                  VUM.swap v j0 (k0-1)
                                  sub pivot i0 j0 (k0-1)
                   | otherwise  = do
                                  VUM.swap v i0 j0
                                  sub pivot (i0+1) (j0+1) k0
-------------------------------------------------------------------------------

inp1 = "3 3 1\n3 2\n"
inp2 = "10 10 14\n4 3\n2 2\n7 3\n9 10\n7 7\n8 1\n10 10\n5 4\n3 4\n2 8\n6 4\n4 4\n5 8\n9 2\n"
inp3 = "100000 100000 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 6
test3 = tv3 == 100000
alltest = test1 && test2 && test3
