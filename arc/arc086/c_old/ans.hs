{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> Int
solve n k as = n - freq where
  cnt = VU.toList $ VU.create $ do
    v <- VUM.replicate (n+1) 0
    forM_ as $ \a -> VUM.modify v (+ 1) a
    return v

  freq = sum $ take k $ sortOn (* (-1)) cnt

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_k]:remLines1 = remLines0
      n = readBInt bs_n
      k = readBInt bs_k
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n k as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "5 2\n1 1 2 2 5\n"
inp2 = "4 4\n1 1 2 2\n"
inp3 = "10 3\n5 1 3 2 4 1 1 2 3 4\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 1
test2 = tv2 == 0
test3 = tv3 == 3
alltest = test1 && test2 && test3
