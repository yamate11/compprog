{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [(Int,Int)] -> Int
solve bigN bigM xys = maximum $ map theFunc [1..bigN]
  where
  theFunc = func_from_memo theMemo
  theMemo = memovec id id mf [1..bigN]

  mf rd x | null (mkDag V.! x) = return 0
          | otherwise = f <$> mapM rd (mkDag V.! x)
    where f vs = 1 + maximum vs

  mkDag = V.create $ do
    vec <- VM.replicate (bigN+1) []
    forM_ xys $ \(x,y) -> do
      VM.modify vec (\cs -> y:cs) x
    return vec

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n m xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

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

inp1 = "4 5\n1 2\n1 3\n3 2\n2 4\n3 4\n"
inp2 = "6 3\n2 3\n4 5\n5 6\n"
inp3 = "5 8\n5 3\n2 3\n2 4\n5 2\n5 1\n1 4\n4 3\n1 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 3
test2 = tv2 == 2
test3 = tv3 == 3
alltest = test1 && test2 && test3
