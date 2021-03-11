{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> [(Int,Int)] -> Int
solve bigN bigQ as xys =
  (mPow 2 bigQ) `mMul` (mSum [finTbl VU.! (enc ij) | ij <- indices])
  where
  vecA = VU.fromListN bigN as
  aof i = vecA VU.! (i-1)

  enc (i,j) = i * (bigN+1) + j

  indices = [(i,j) | i <- [1..bigN], j <- [1..bigN], i < j]

  finTbl = VU.create $ do
    v = VUM.new (bigN+1)*(bigN+1)
    forM_ indices $ \(i,j) -> do
      VU.write v (enc (i,j)) (if aof i > aof j then 1 else 0)
    forM_ xys $ \(x,y) -> do
      forM_ (modList vec x y) $ \(i, j, val) -> do
        z <- val
        VU.write v (enc (i,j)) z
    return v

  inv2 = (mPrime + 1) `div` 2

  modList :: MVector (Primstate m) Int -> Int -> Int -> m [(Int, Int, Int)]


  modList rd x y | x > y = modList' y x
                 | otherwise = modList' x y
    where
    modList' x y = concat $
      [[both x y]]
      ++ [[part1 i x, part1 i y] | i <- [0..x-1]]
      ++ [[part2a x i, part2b i y] | i <- [x+1..y-1]]
      ++ [[part3 x i, part3 y i] | i <- [y+1..bigN-1]]
    mean (i1,j1) (i2,j2) = do
      val1 <- rd i1 j1
      val2 <- rd i2 j2
      return $ (val1 `mAdd` val2) `mMul` inv2
    mean2 (i1,j1) (i2,j2) = do
      val1 <- rd i1 j1
      val2 <- rd i2 j2
      return $ (val1 `mAdd` (1 `mSub` val2)) `mMul` inv2
    both x y = (x, y, return inv2)
    part1 i x y = do
      val1 <- rd i x
      val2 <- rd i y
      let u = (val1 `mAdd` val2) `mMul` inv2
      return [(i, x, u), (i, y, u)]
    part3 i x y = do
      val1 <- rd x i
      val2 <- rd y i
      let u = (val1 `mAdd` val2) `mMul` inv2
      return [(x, i, u), (y, i, u)]
    part2 i x y = do
      val1 <- rd x i
      val2 <- rd i y
      let u1 = (val1 `mAdd` (1 - val2)) `mMul` inv2
          u2 = ((1 - val1) `mAdd` val2) `mMul` inv2
      return [(x, i, u1), (i, y, u2)]


mSum ns = foldl' mAdd 0 ns

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigN,bs_bigQ]:remLines1 = remLines0
      bigN = readBInt bs_bigN
      bigQ = readBInt bs_bigQ
      (lines2, remLines2) = splitAt (bigN) remLines1
      as = map (\[x] -> readBInt x) lines2
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve bigN bigQ as xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------
mPrime = 10^9 + 7

mPow :: Int -> Int -> Int
mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

-------------------------------------------------------------------------------

inp1 = "3 2\n1\n2\n3\n1 2\n1 3\n"
inp2 = "5 3\n3\n2\n3\n1\n4\n1 5\n2 3\n4 2\n"
inp3 = "9 5\n3\n1\n4\n1\n5\n9\n2\n6\n5\n3 5\n8 9\n7 9\n3 2\n3 8\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 6
test2 = tv2 == 36
test3 = tv3 == 425
alltest = test1 && test2 && test3
