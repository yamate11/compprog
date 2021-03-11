{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> Int -> Int
solve bigA bigB bigC = bigB + min (bigA + bigB + 1) bigC

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigA,bs_bigB,bs_bigC]:remLines1 = remLines0
      bigA = readBInt bs_bigA
      bigB = readBInt bs_bigB
      bigC = readBInt bs_bigC
  in solve bigA bigB bigC

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3 1 4\n"
inp2 = "5 2 9\n"
inp3 = "8 8 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 5
test2 = tv2 == 10
test3 = tv3 == 9
alltest = test1 && test2 && test3
