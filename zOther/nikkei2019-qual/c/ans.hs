{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [(Int,Int)] -> Int
solve n lst_ab = xtak - xaok
  where
    lst = sortOn (\(x,t) -> -x) (map f lst_ab)
      where 
        f :: (Int,Int) -> (Int, (Int,Int))
        f (a,b) = (a+b, (a,b))
    (tak, aok) = partition (\(p,q) -> even p) (zip [0..] lst)
    xtak = sum (map (fst.snd.snd) tak)
    xaok = sum (map (snd.snd.snd) aok)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      abs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n abs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n10 10\n20 20\n30 30\n"
inp2 = "3\n20 10\n20 20\n20 30\n"
inp3 = "6\n1 1000000000\n1 1000000000\n1 1000000000\n1 1000000000\n1 1000000000\n1 1000000000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 20
test2 = tv2 == 20
test3 = tv3 == -2999999997
alltest = test1 && test2 && test3

