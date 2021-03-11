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

solve :: Int -> [Int] -> Int
solve bL as = minimum finVals
  where
  finVals = foldl f [0,0,0,0,0] as
    where
    f vals a = zipWith (\fn !v -> v + fn a)
                 fns (tail (scanl' min maxBound vals))

fns = [id, gRet, gOw, gRet, id]

gRet 0 = 2
gRet x | odd x = 1
       | even x = 0

gOw x | odd x = 0
      | even x = 1

-------------------------------------------------------------------------------

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
      [bs_bL]:remLines1 = remLines0
      bL = readBInt bs_bL
      as = map (\[x] -> readBInt x) remLines1
  in solve bL as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "4\n1\n0\n2\n3\n"
inp2 = "8\n2\n0\n0\n2\n1\n3\n4\n1\n"
inp3 = "7\n314159265\n358979323\n846264338\n327950288\n419716939\n937510582\n0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 1
test2 = tv2 == 3
test3 = tv3 == 1
alltest = test1 && test2 && test3

