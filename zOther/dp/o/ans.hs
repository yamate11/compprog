{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [[Int]] -> Int
solve bN ass = ans
  where
  aV = V.fromListN bN (map f ass)
    where f as = [m | (m,a) <- zip [0..bN-1] as, a == 1]

  ans = runST $ do
    vec <- VUM.replicate (2^bN) 0
    VUM.write vec 0 1
    forM_ [0..2^bN-2] $ \is -> do
      cur <- VUM.read vec is
      when (cur > 0) $ do
        let k = popCount is
        forM_ (aV V.! k) $ \m -> do
          unless (testBit is m) $ do
            VUM.modify vec (mAdd cur) (setBit is m)
    VUM.read vec (2^bN-1)

-------------------------------------------------------------------------------

prime :: Int
prime = 10 ^ 9 + 7

mAdd x y | w < prime = w
         | otherwise = w - prime
  where w = x + y

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      ass = map (map readBInt) remLines1
  in solve bN ass

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3\n0 1 1\n1 0 1\n1 1 1\n"
inp2 = "4\n0 1 0 0\n0 0 0 1\n1 0 0 0\n0 0 1 0\n"
inp3 = "1\n0\n"
inp4 = "21\n0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1\n1 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 0\n0 0 1 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 1 1\n0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0\n1 1 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0\n0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 0 0 1\n0 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0\n0 0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1\n0 0 1 0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 1 1 1\n0 0 0 0 1 1 0 0 1 1 1 0 0 0 0 1 1 0 0 0 1\n0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0\n0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 0 1\n0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 1\n1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1\n0 0 0 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1\n1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 1 0 1 1 0\n0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 0 0 1\n0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 1\n0 0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 0 0 1 1 0\n1 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 0\n1 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 3
test2 = tv2 == 1
test3 = tv3 == 0
test4 = tv4 == 102515160
alltest = test1 && test2 && test3 && test4

