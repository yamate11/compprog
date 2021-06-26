{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [Int] -> [(Int,Int)] -> Int
solve bN as uvs = error "notyet" where
  (nCut, vs) = combine 1
  answer | va VU.! 1 > 0 = nCut
         | otherwise = fromJust $ findIndex (< 0) vs

  vA = VU.fromListN (bN+1) as
  nbr = bldNbr bN uvs

  -- combine ! k == (x,ys) ... x   : cut numbers for no computers
  --                           y!i : min value for i cut
  combine :: Int -> VU.Vector (Int, Int)
  combine node = topModif nCut vs where
    vNode = vA VU.! node
    children = filter (/= node) (nbr VU.! node)
    (nCut, vs) = foldl' opComb initComb $ map combine children
    opComb (xa, va) (xc, vc) = (xa + xc, newV) where
      lenA = VU.length va
      lenC = VU.length vc
      newV = VU.generate (lenA + lenC - 1) conv
      conv k = minimum [va VU.! i + vc VU.! j | (i,j) <- idxConv k]
      idxConv k = [(i, k-i) | i <- [max 0 (k -lenB+1) .. min k (lenA-1)]]
    topModif nCut vs = (nCutNew, vs'') where
      vs' = VU.map (+ vNode) vs
      iNeg = findIndex (< 0) vs' 
      nCutNew = case iNeg of
        Just i -> if vNode > 0 then min nCut (i+1) else i+1
        Nothing -> nCut
      vs'' = if nCutNew+1 < VU.length vs' && vs' VU.! (nCutNew+1) > 0
        then VU.imap f1 vs'
        else if nCutNew+1 == VU.length vs' && vs' VU.! nCutNew > 0
             then VU.snoc vs' 0
             else vs'
        where f1 i v | nCutNew+1 <= i && v > 0 = 0
                     | otherwise               = v

bldNbr :: Int -> [(Int,Int)] -> V.Vector [Int]
bldNbr maxIdx uvs = V.create $ do
  nbr <- VM.replicate (maxIdx+1) []
  forM_ uvs $ \(u,v) -> do
    VM.modify nbr (u:) v
    VM.modify nbr (v:) u
  return nbr

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
      uvs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve n as uvs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "7\n-2 7 5 6 -8 3 4\n1 2\n2 3\n2 4\n1 5\n5 6\n5 7\n"
inp2 = "4\n1 2 3 4\n1 2\n1 3\n1 4\n"
inp3 = "6\n10 -1 10 -1 10 -1\n1 2\n2 3\n3 4\n4 5\n5 6\n"
inp4 = "8\n-2 3 6 -2 -2 -5 3 2\n3 4\n7 6\n6 2\n8 2\n5 3\n1 8\n3 7\n"
inp5 = "10\n3 4 9 6 1 5 -1 10 -10 -10\n7 4\n5 6\n8 1\n9 5\n7 1\n10 3\n2 8\n4 10\n9 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 1
test2 = tv2 == 0
test3 = tv3 == 5
test4 = tv4 == 3
test5 = tv5 == 3
alltest = test1 && test2 && test3 && test4 && test5
