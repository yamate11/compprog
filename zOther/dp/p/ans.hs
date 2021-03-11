{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

data Color = Black | White
  deriving (Show)

solve :: Int -> [(Int,Int)] -> Int
solve bN xys = theFunc (Black,1) `mAdd` theFunc (White,1)
  where

  tree = rootedTree xys 1 (bN+1)

  theFunc = func_memo enc (memovec enc (2*(bN+1)) mf [(Black,1), (White,1)])

  enc (Black, i) = i
  enc (White, i) = bN+1 + i

  mf rc (Black,i) = mProdM [rc (White, j) | j <- tree i]
  mf rc (White,i) = mProdM [mAdd <$> rc (White, j) <*> rc (Black, j)
                           | j <- tree i]
                     
-------------------------------------------------------------------------------

rootedTree :: [(Int,Int)] -> Int -> Int ->
              Int -> [Int]
rootedTree xys root maxIdxPlusOne i = vec V.! i where
  vec = V.create (VM.replicate maxIdxPlusOne [] >>= vecAct)
  vecAct vec = do
    forM_ xys $ \(x,y) -> do
      VM.modify vec (x:) y
      VM.modify vec (y:) x
    VM.read vec root >>= mapM_ (removeParent root)
    return vec
    where
    removeParent parent idx = do
      cs <- filter (/= parent) <$> VM.read vec idx
      VM.write vec idx cs
      mapM_ (removeParent idx) cs
  
mPrime :: Int
mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = let w = x + y in if w < mPrime then w else w - mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

mProdM :: Monad m => [m Int] -> m Int
mProdM      = lzFold' mMul 1

memovec :: forall a d. (VU.Unbox a, Show a, Show d) =>
           (d -> Int) -> Int -> 
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> VU.Vector a
memovec encode size mf ds = VU.create $ do
  vec <- VUM.new size
  flags <- VUM.replicate size False
  mapM_ (calc vec flags) ds
  return vec
  where
    calc vec flags d = do
      fv <- VUM.read flags (encode d)
      if fv then VUM.read vec (encode d)
        else do
        val <- mf (calc vec flags) d
        VUM.write vec   (encode d) val
        VUM.write flags (encode d) True
        return val

func_memo :: VU.Unbox a => (d->Int) -> VU.Vector a -> d -> a
func_memo encode vecV d = vecV VU.! (encode d)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n1 2\n2 3\n"
inp2 = "4\n1 2\n1 3\n1 4\n"
inp3 = "1\n"
inp4 = "10\n8 5\n10 8\n6 5\n1 5\n4 8\n2 10\n3 6\n9 2\n1 7\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 5
test2 = tv2 == 9
test3 = tv3 == 2
test4 = tv4 == 157
alltest = test1 && test2 && test3 && test4

