{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> Int -> [(Int,Int)] -> Int
solve bH bW bN rcs = vResults VU.! bN
  where

  vWall = VU.fromListN (bN+1) (sort rcs ++ [(bH, bW)])

  vFact = VU.fromListN (bH+bW+1) $ scanl mMul 1 [1..(bH+bW)]
  vInvFact = VU.map mInv vFact

  combi n r = (vFact VU.! n) `mMul` (vInvFact VU.! r)
                             `mMul` (vInvFact VU.! (n-r))

  numPaths (r1,c1) (r2,c2)
    | r1 <= r2 && c1 <= c2 = combi ((r2-r1) + (c2-c1)) (r2-r1)
    | otherwise            = 0

  vResults = VU.create $ do
    vec <- VUM.new (bN+1)
    forM_ [0..bN] $ \i -> do
      let wi = vWall VU.! i
          f j = (mMul (numPaths (vWall VU.! j) wi)) <$> VUM.read vec j
      newVal <- (mSub (numPaths (1,1) wi)) <$> mSumM (map f [0 .. i-1])
      VUM.write vec i newVal
    return vec

-------------------------------------------------------------------------------

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y
mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

-- eGCD a b = (g,s,t) ==> g = (a,b) = a*s + b*t
eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

mSumM :: Monad m => [m Int] -> m Int
mSumM = lzFold' mAdd 0

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bH,bs_bW,bs_bN]:remLines1 = remLines0
      bH = readBInt bs_bH
      bW = readBInt bs_bW
      bN = readBInt bs_bN
      rcs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bH bW bN rcs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3 4 2\n2 2\n1 4\n"
inp2 = "5 2 2\n2 1\n4 2\n"
inp3 = "5 5 4\n3 1\n3 5\n1 3\n5 3\n"
inp4 = "100000 100000 1\n50000 50000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 3
test2 = tv2 == 0
test3 = tv3 == 24
test4 = tv4 == 123445622
alltest = test1 && test2 && test3 && test4

