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
import Debug.Trace
-- trace _ = id

type T3Int = (Int,Int,Int)

solve :: Int -> [Int] -> Double
solve bN as = theFunc initSt
  where

  enc (x1,x2,x3) = x1 + x2 * (bN+1) + x3 * (bN+1)*(bN+1)
  dec z = (x1,x2,x3)
    where (z', x1) = divMod z (bN+1)
          (x3, x2) = divMod z' (bN+1)

  initSt = foldl' opIS (0,0,0) as

  opIS (!x1,!x2,!x3) 1 = (x1+1, x2, x3)
  opIS (!x1,!x2,!x3) 2 = (x1, x2+1, x3)
  opIS (!x1,!x2,!x3) 3 = (x1, x2, x3+1)

  theFunc = func_from_memo theMemo
  theMemo = memovec enc dec mf [initSt]
    where

    mf :: forall m. Monad m => (T3Int -> m Double) -> T3Int -> m Double
    mf rd (0,0,0) = return 0
    mf rd (x,y,z) = do
      ex <- getE (x-1) y     z
      ey <- getE (x+1) (y-1) z
      ez <- getE x     (y+1) (z-1)
      let idmul i d = (fromIntegral i) * d
          rem = fromIntegral (x + y + z)
          comp = (fromIntegral bN) - rem
          rv = (idmul x ex + idmul y ey + idmul z ez + comp) / rem
      -- trace ("mf " ++ show (x,y,z,rv)) (return ())
      return rv
      where
  
      getE :: Int -> Int -> Int -> m Double
      getE x y z | x >= 0 && y >= 0 && z >= 0 = (+ 1) <$> rd (x,y,z)
                 | otherwise                  = return 0

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Double
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: Double -> IO ()
outAnswer x = putStrLn (show x)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

memovec :: forall a d. (VU.Unbox a, Show a, Show d) =>
           (d -> Int) -> (Int -> d) ->
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> (VU.Vector a, VU.Vector Bool, d -> Int)
memovec encode decode mf ds = (vecV, vecF, encode)
  where
    (vecV, vecF) = mv_enc mf' (map encode ds)

    mf' f' i = mf (f' . encode) (decode i)

    mv_enc :: (forall m. Monad m => (Int -> m a) -> Int -> m a)
           -> [Int] -> (VU.Vector a, VU.Vector Bool)
    mv_enc mf xs = runST $ do
      let size = (maximum xs + 1)
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

inp1 = "3\n1 1 1\n"
inp2 = "1\n3\n"
inp3 = "2\n1 2\n"
inp4 = "10\n1 3 2 3 3 2 3 2 1 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = near tv1 5.5
test2 = near tv2 3
test3 = near tv3 4.5
test4 = near tv4 54.48064457488221
alltest = test1 && test2 && test3 && test4
near x y = abs (x-y) < 10 ** (-9)
