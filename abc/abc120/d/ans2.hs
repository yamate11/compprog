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
    uf <- uftInit (bN+1)
    ccSize <- VUM.replicate (bN+1) 1
    diff <- VUM.new bM
    forM_ (zip [0..bM-1] (reverse lstAB)) $ \(i, (a,b)) -> do
      a' <- uftFind uf a
      b' <- uftFind uf b
      if a' == b' then VUM.write diff i 0 else do
        nA <- VUM.read ccSize a'
        nB <- VUM.read ccSize b'
        let nSum = nA + nB
        let thisDiff = (combi2 nSum) - (combi2 nA) - (combi2 nB)
        VUM.write diff i thisDiff
        uftUnion uf a' b'
        VUM.write ccSize b' nSum
    return diff
    

combi2 n = (n * (n-1)) `div` 2

----------------------------------------------------------------------

{-
   Union-Find Tree
      Note: only flattern part is implemented.
            length comparison part has not yet been implemented.
-}

-- Initialization
uftInit :: Int -> ST s (VUM.MVector s Int)
uftInit size = do
  vec <- VUM.new size
  forM_ [0..size-1] $ \i -> VUM.write vec i i
  return vec

-- Union, or merge
uftUnion :: VUM.MVector s Int -> Int -> Int -> ST s ()
uftUnion vec x y = do
  rx <- uftFind vec x
  ry <- uftFind vec y
  if rx == ry then return ()
              else VUM.write vec rx ry

-- Returns the root
uftFind :: VUM.MVector s Int -> Int -> ST s Int
uftFind vec x = do
  y <- VUM.read vec x
  if x == y then return x
            else uftFind vec y >>= vum_write_ret vec x

-- Tests if in the same group
uftSameGrp :: VUM.MVector s Int -> Int -> Int -> ST s Bool
uftSameGrp vec x y = (==) <$> uftFind vec x <*> uftFind vec y

vum_write_ret :: VUM.Unbox a => VUM.MVector s a -> Int -> a -> ST s a
vum_write_ret vec i a = VUM.write vec i a >> return a


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

