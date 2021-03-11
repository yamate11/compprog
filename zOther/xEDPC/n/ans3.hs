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
  cost = buildVec VU.! (enc (bN,0))

  buildVec = VU.create $ do
    vec <- VUM.replicate size (-1)
    calc vec (bN,0)
    return vec
    where
      calc vec (1,_) = return 0
      calc vec (len,i) = do
        val <- VUM.read vec (enc (len,i))
        if val >= 0 then return val
          else do
          newVal <- top <$> minimumM (map f [1 .. len-1])
          VUM.write vec (enc (len,i)) newVal
          return newVal
        where
          top v = v + (acc VU.! (i+len)) - (acc VU.! i)
          f k = (+) <$> calc vec (k, i) <*> calc vec (len-k, i+k)

minimumM :: (Monad m, Ord a) => [m a] -> m a
minimumM [] = error "list is empty for minimumM"
minimumM (x:xs) = x >>= sub xs
  where sub []     !p = return p
        sub (x:xs) !p = do
          q <- x
          sub xs (min p q) 


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

