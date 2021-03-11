{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int)] -> [Int]
solve bN bM xys = map ans [1..bN]
-- solve bN bM xys = map fst $ VU.toList (nodeVec V.! bN)
  where

  brcVec = VU.fromListN (bN-1) xys
  getNodeFromBranch (b,0) = fst (brcVec VU.! b)
  getNodeFromBranch (b,1) = snd (brcVec VU.! b)

  -- nodeVec = trace ("nodeVec " ++ show (nodeVecA)) nodeVecA
  nodeVec = V.map VU.fromList $ V.create $ do
    nodeV <- VM.replicate (bN+1) []
    forM_ [0..bN-2] $ \b -> do
      let (x,y) = brcVec VU.! b
      VM.modify nodeV ((b,0):) x
      VM.modify nodeV ((b,1):) y
    return nodeV

  enc (b,d) = b*2 + d
  theMemo = memovec enc ((bN-1)*2) mf [(b,d)| b <- [0..bN-2], d <- [0,1]]
  theFunc = func_memo enc theMemo

  -- mf rc (b,d) | traceL "mf in" (b,d) False = undefined
  -- mf rc (b,d) = traceLM "mf" (b,d,) (mfA rc (b,d))
  mf rc (b,d) = lzFold' (mMul bM) 1 f nvec
    where
    x = getNodeFromBranch (b,d)
    nvec = nodeVec V.! x
    -- nvec = traceL "nvec" (b,d,x,nvecA) nvecA
    f (b',d') | b == b' = return 1
              | otherwise = (+ 1) <$> rc (b', 1-d')

  ans x = VU.foldl' (mMul bM) 1
                    (VU.map (\(b',d') -> 1 + theFunc(b',1-d'))
                            (nodeVec V.! x))

mMul m x y = (x * y) `mod` m
-------------------------------------------------------------------------------

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

withActVal :: Monad m => m a -> (a -> m ()) -> m a
withActVal actWithVal act = do
  x <- actWithVal
  act x
  return x

lzFold' :: (Monad m, VU.Unbox c) =>
           (b -> a -> b) -> b -> (c -> m a) -> VU.Vector c -> m b
lzFold' op b0 f vc = sub b0 0 where
  sub !acc i | i == VU.length vc = return acc
             | otherwise = f (vc VU.! i) >>= (\a -> sub (op acc a) (i+1))

memovec :: forall a d. (VU.Unbox a, Show a, Show d) =>
           (d -> Int) -> Int -> 
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> VU.Vector a
memovec encode size mf ds = VU.create $ do
  vec <- VUM.new size
  flags <- VUM.replicate size False
  mapM_ (calc vec flags) ds
  return vec
  where
    calc vec flags d = do
      fv <- VUM.read flags (encode d)
      if fv then VUM.read vec (encode d)
        else do
        val <- mf (calc vec flags) d
        VUM.write vec   (encode d) val
        VUM.write flags (encode d) True
        return val

func_memo :: VU.Unbox a => (d->Int) -> VU.Vector a -> d -> a
func_memo encode vecV d = vecV VU.! (encode d)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bM xys

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr $ unlines $ map show xs

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3 100\n1 2\n2 3\n"
inp2 = "4 100\n1 2\n1 3\n1 4\n"
inp3 = "1 100\n"
inp4 = "10 2\n8 5\n10 8\n6 5\n1 5\n4 8\n2 10\n3 6\n9 2\n1 7\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
