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
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> Int
solve bN as = x-y
  where
  vA = VU.fromListN bN as
  total = VU.sum vA

  enc (i,j) = i*bN + j
  dec z = divMod z bN

  quest = (0, bN-1)
  
  mf :: Monad m => ((Int,Int) -> m (Int,Int)) -> (Int,Int) -> m (Int,Int)
  mf rd (h,t)
    | h == t = return (vA VU.! h, 0)
    | otherwise = do
        (sh, fh) <- rd (h+1,t)
        (st, ft) <- rd (h,t-1)
        let gh = fh + vA VU.! h
            gt = ft + vA VU.! t
        return $ max (gh, sh) (gt, st)

  (x,y) = func_from_memo (memovec enc dec (bN*bN) mf [quest]) quest

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
           (d -> Int) -> (Int -> d) -> Int ->
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> (VU.Vector a, VU.Vector Bool, d -> Int)
memovec encode decode size mf ds = (vecV, vecF, encode)
  where
    (vecV, vecF) = mv_enc mf' (map encode ds)

    mf' f' i = mf (f' . encode) (decode i)

    mv_enc :: (forall m. Monad m => (Int -> m a) -> Int -> m a)
           -> [Int] -> (VU.Vector a, VU.Vector Bool)
    mv_enc mf xs = runST $ do
      v      <- VUM.new size
      flags  <- VUM.replicate size False
      forM_ xs $ \x -> calc v flags x
      v'     <- VU.unsafeFreeze v
      flags' <- VU.unsafeFreeze flags
      return (v', flags')

      where

        calc :: forall s. VUM.MVector s a -> VUM.MVector s Bool
                          -> Int -> ST s a
        calc v flags x = VUM.read flags x >>= ite231 (VUM.read v x) else_e
          where
            else_e = do
              val <- mf (calc v flags) x
              VUM.write v x val
              VUM.write flags x True
              return val

func_from_memo :: VU.Unbox a =>
                  (VU.Vector a, VU.Vector Bool, d->Int) -> d -> a
func_from_memo (vecV, vecF, enc) d
  | vecF VU.! x = vecV VU.! x
  | otherwise   = undefined
  where x = enc d

ite231 :: a -> a -> Bool -> a
ite231 then_part else_part cond = if cond then then_part else else_part

-------------------------------------------------------------------------------

inp1 = "4\n10 80 90 30\n"
inp2 = "3\n10 100 10\n"
inp3 = "1\n10\n"
inp4 = "10\n1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1\n"
inp5 = "6\n4 2 9 7 1 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 10
test2 = tv2 == -80
test3 = tv3 == 10
test4 = tv4 == 4999999995
test5 = tv5 == 2
alltest = test1 && test2 && test3 && test4 && test5

