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
solve bN bM lstAB = map (snd . theFunc) [1..bN]
  where
    
  parent :: V.Vector [Int]
  parent = V.create $ do
    vec <- VM.replicate (bN+1) []
    forM lstAB $ \(a,b) -> do
      VM.modify vec (a:) b
    return vec

  mf :: Monad m => (Int -> m (Int,Int)) -> Int -> m (Int,Int)
  mf rc i = do
    case (parent V.! i) of
      [] -> return (0, 0)
      ps -> do
        let f x = (,x) <$> rc x
        ((n, _), p) <- maximumM (map f ps)
        return (n+1, p)

  theMemo = memovec id (bN+1) mf [1..bN]
  theFunc = func_memo id theMemo

-------------------------------------------------------------------------------
    
lzFold' :: Monad m => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

lzFold1' :: Monad m => (a -> a -> a) -> [m a] -> m a
lzFold1' op (ma:mas) = ma >>= flip (lzFold' op) mas

maximumM :: (Monad m, Ord a) => [m a] -> m a
maximumM = lzFold1' max

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
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bM lstAB

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr (unlines (map show xs))

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


inp1 = "3 1\n1 2\n1 3\n2 3\n"
inp2 = "6 3\n2 1\n2 3\n4 1\n4 2\n6 1\n2 6\n4 6\n6 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == [0,1,2]
test2 = tv2 == [6,4,2,0,6,2]
alltest = test1 && test2

