{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ = id

type MyS = (Int, Int, Int, Bool, Int)

solve :: Int -> Int -> [Int] -> Int
solve bigL bigN xs = max (sub vec1 vec2) (sub vec2 vec1)
  where
  vec1 = VU.fromListN bigN xs
  vec2 = VU.map (bigL -) (VU.reverse vec1)

  sub :: VU.Vector Int -> VU.Vector Int -> Int
  sub vec1 vec2 = trace ("sub " ++ show a) a
    where a = sub0 vec1 vec2
  sub0 vec1 vec2 = maximum lst
    where
    lst = trace ("lst " ++ show lst0) lst0
    lst0 = unfoldr f initState
      where f Nothing = Nothing
            f (Just st) = Just (valState st, nextState st)

    initSum = VU.sum (VU.take initLen vec1) + VU.sum (VU.take initLen vec2)
    initLen = bigN `div` 2
    initState = trace ("initState " ++ show initStateA) initStateA
    initStateA = Just (0, initLen-1, initLen-1, even bigN, initSum)
  
    nextState :: MyS -> Maybe MyS
    nextState st = trace ("nextState " ++ show (st, a)) a
      where a = nextStateA st
    nextStateA (idx1T, idx1B, idx2B, isEven, sum)
      | (not isEven) && idx2B < 0 = Nothing
      | not isEven = Just (idx1T+1, idx1B+1, idx2B, True,
                           sum - vec1 VU.! idx1T + vec1 VU.! (idx1B+1))
      | idx2B > 0 = Just (idx1T+1, idx1B, idx2B-1, False,
                           sum - vec1 VU.! idx1T - vec2 VU.! idx2B)
      | otherwise = Nothing
  
    valState :: MyS -> Int
    valState (idx1T, idx1B, idx2B, isEven, sum)
      | isEven    = 2 * sum - (min (vec1 VU.! idx1B)     (vec2 VU.! idx2B))
      | otherwise = 2 * sum + (max (vec1 VU.! (idx1B+1)) (vec2 VU.! (idx2B+1)))

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigL,bs_bigN]:remLines1 = remLines0
      bigL = readBInt bs_bigL
      bigN = readBInt bs_bigN
      xs = map (\[x] -> readBInt x) remLines1
  in solve bigL bigN xs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

{-
   2,7,9
   1,3,8

-}


inp1 = "10 3\n2\n7\n9\n"
inp2 = "10 6\n1\n2\n3\n6\n7\n9\n"
inp3 = "314159265 7\n21662711\n77271666\n89022761\n156626166\n160332356\n166902656\n298992265\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 15
test2 = tv2 == 27
test3 = tv3 == 1204124749
alltest = test1 && test2 && test3
