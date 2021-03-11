{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: String -> Int
solve spec = VU.foldl' mAdd 0 dp
  where
  blues = VU.postscanl' mAdd 0 (VU.fromList (map f spec))
    where f c = read [c]
  len = VU.length blues
  totBlue = blues VU.! (len-1)
  dp = VU.ifoldl' f initV (blues VU.++ (VU.replicate len totBlue))
    where
    initV = VU.fromList [1]
    -- f vec i nb = traceL "vect" (i,x) x
    --      where x = fX vec i nb
    f vec i nb = VU.generate (i+2) g
      where
      nr | i < len   = (i+1)*2 - nb
         | otherwise = len*2 - nb
      g j | nb < j || nr < (i+1 - j) = 0
          | j == 0                   = vec VU.! 0
          | j == i+1                 = vec VU.! i
          | otherwise                = (vec VU.! (j-1)) `mAdd` (vec VU.! j)

----------------------------------------------------------------------
mPrime = 998244353

-- mAdd x y = (x + y) `mod` mPrime
mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

-- mSub x y = (x - y) `mod` mPrime    -- ok even if x < y
mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_spec]:remLines1 = remLines0
      spec = B.unpack bs_spec
  in solve spec

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


-------------------------------------------------------------------------------

inp1 = "02\n"
inp2 = "1210\n"
inp3 = "12001021211100201020\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 55
test3 = tv3 == 543589959
alltest = test1 && test2 && test3

