{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> Int
solve bN as = cost
  where
  vA = VU.fromListN bN as
  acc = VU.scanl' (+) 0 vA

  enc (len,i) = len * bN + i
  size = bN*(bN+1)
  cost = func_memo enc (memovec enc size mf [(bN,0)]) (bN,0)
  mf rd (1,_) = return 0
  mf rd (len,i) = top <$> mapM f [1 .. len-1]
    where
      top lst = (minimum lst) + (acc VU.! (i+len)) - (acc VU.! i)
      f k = (+) <$> rd (k, i) <*> rd (len-k, i+k)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve bN as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

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

-------------------------------------------------------------------------------

inp1 = "4\n10 20 30 40\n"
inp2 = "5\n10 10 10 10 10\n"
inp3 = "3\n1000000000 1000000000 1000000000\n"
inp4 = "6\n7 6 8 6 1 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 190
test2 = tv2 == 120
test3 = tv3 == 5000000000
test4 = tv4 == 68
alltest = test1 && test2 && test3 && test4

