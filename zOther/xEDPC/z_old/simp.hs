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
import Data.STRef
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [Int] -> Int
solve bN bC hs = results VU.! 1
  where

  vecH = VU.fromListN (bN+1) (0:hs)

  results = VU.create $ do
    vec <- VUM.new (bN+1)
    act vec
    where
    act vec = act' where
      act' = do
        VUM.write vec bN 0
        forM_ [bN-1, bN-2 .. 1] $ \i -> do
          let hi = vecH VU.! i
          vals <- forM [i+1 .. bN] $ \j -> do
            let hj = vecH VU.! j
            vj <- VUM.read vec j
            let val = (hi - hj) * (hi - hj) + bC + vj
            return (val, j)
          let (vi, j) = minimum vals
          VUM.write vec i vi
          traceL "val" (i,vi,j) (return ())
        return vec

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bC]:remLines1 = remLines0
      bN = readBInt bs_bN
      bC = readBInt bs_bC
      line2:remLines2 = remLines1
      hs = map readBInt line2
  in solve bN bC hs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "5 6\n1 2 3 4 5\n"
inp2 = "2 1000000000000\n500000 1000000\n"
inp3 = "8 5\n1 3 4 5 10 11 12 13\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 20
test2 = tv2 == 1250000000000
test3 = tv3 == 62
alltest = test1 && test2 && test3

