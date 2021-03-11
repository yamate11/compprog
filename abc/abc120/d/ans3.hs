{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntMap.Strict as IM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int)] -> [Int]
solve bN bM lstAB = map (\x -> (combi2 bN) - x) conn
  where
  conn = reverse $ VU.toList $ VU.prescanl' (+) 0 vDiff

  vDiff :: VU.Vector Int
  -- vDiff = traceL "vDiff" vDiff0 vDiff0
  vDiff = VU.create $ do
    uf <- ufInit (bN+1)
    diff <- VUM.new bM
    forM_ (zip [0..bM-1] (reverse lstAB))
      $ \(i, (a,b)) -> getDiff uf a b >>= VUM.write diff i
    return diff

    where
    getDiff uf a b = do
      a0 <- ufGetLeader uf a
      b0 <- ufGetLeader uf b
      if a0 == b0
        then return 0
        else do
          ca <- VUM.read (ufCCSize uf) a0
          cb <- VUM.read (ufCCSize uf) b0
          newL <- ufMerge uf a0 b0
          cNewL <- VUM.read (ufCCSize uf) newL
          return $ (combi2 cNewL) - (combi2 ca) - (combi2 cb)

combi2 n = (n * (n-1)) `div` 2

----------------------------------------------------------------------

data UnionFind s = UnionFind {
  ufLeader :: VUM.MVector s Int,
  ufRank :: VUM.MVector s Int,
  ufCCSize :: VUM.MVector s Int
}

ufInit :: Int -> ST s (UnionFind s)
{-# INLINE ufInit #-}
ufInit size = do
  leader <- VUM.new size
  forM_ [0..size-1] $ \i -> VUM.write leader i i
  rank <- VUM.replicate size 1
  ccsize <- VUM.replicate size 1
  return $ UnionFind { ufLeader = leader, ufRank = rank, ufCCSize = ccsize }
  
ufGetLeader :: UnionFind s -> Int -> ST s Int
{-# INLINE ufGetLeader #-}
ufGetLeader uf i = do
  x <- VUM.read (ufLeader uf) i
  if x == i
    then return i
    else do
      y <- ufGetLeader uf x
      VUM.write (ufLeader uf) i y
      return y

ufMerge :: UnionFind s -> Int -> Int -> ST s Int
{-# INLINE ufMerge #-}
ufMerge uf i j = do
  x <- ufGetLeader uf i
  y <- ufGetLeader uf j
  if x == y
    then return x
    else do
      rx <- VUM.read (ufRank uf) x
      ry <- VUM.read (ufRank uf) y
      case () of
        () | rx < ry -> _merge x y
           | rx > ry -> _merge y x
           | otherwise -> do
               VUM.modify (ufRank uf) (+ 1) y
               _merge x y
  where
    _merge x y = do
      cx <- VUM.read (ufCCSize uf) x
      VUM.modify (ufCCSize uf) (+ cx) y
      VUM.write (ufLeader uf) x y
      return y

ufSameCC :: UnionFind s -> Int -> Int -> ST s Bool
{-# INLINE ufSameCC #-}
ufSameCC uf i j = (==) <$> ufGetLeader uf i <*> ufGetLeader uf j

----------------------------------------------------------------------

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bM lstAB

outAnswer :: [Int] -> IO ()
outAnswer ns = putStr (unlines (map show ns))

main :: IO ()
main = outAnswer . tmain =<< B.getContents

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

-------------------------------------------------------------------------------

inp1 = "4 5\n1 2\n3 4\n1 3\n2 3\n1 4\n"
inp2 = "6 5\n2 3\n1 2\n5 6\n3 4\n4 5\n"
inp3 = "2 1\n1 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == [0,0,4,5,6]
test2 = tv2 == [8,9,12,14,15]
test3 = tv3 == [1]
alltest = test1 && test2 && test3

