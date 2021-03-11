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

solve :: Int -> String -> Maybe String
solve n s = foldr op Nothing (map (tryF n s) ["SS", "SW", "WS", "WW"])
  where
  op (Just p) _ = Just p
  op Nothing q = q

tryF n s [p_start, q_start] | res2 == [p_start, q_start] = Just (res2 ++ res1)
                            | otherwise                  = Nothing
  where
  (_, results) = mapAccumL f (p_start, q_start) (tail s ++ [head s])
    where f (p,q) u = ((q, newP), newP)
            where newP = nxt p q u
  (res1, res2) = splitAt (n-2) results

nxt p1 p2 u = nxt'' u (nxt' p1 p2)
  where
    nxt' 'S' = id
    nxt' 'W' = rev_SW
    nxt'' 'o' = id
    nxt'' 'x' = rev_SW

rev_SW 'S' = 'W'
rev_SW 'W' = 'S'



readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      [bs_s]:remLines2 = remLines1
      s = B.unpack bs_s
  in solve n s

outAnswer :: Maybe String -> IO ()
outAnswer (Just s) = putStrLn s
outAnswer Nothing  = putStrLn "-1"

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "6\nooxoox\n"
inp2 = "3\noox\n"
inp3 = "10\noxooxoxoox\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == Just "SSSWWS"
test2 = tv2 == Nothing
test3 = tv3 == Just "SSWWSSSWWS"
alltest = test1 && test2 && test3

