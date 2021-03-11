{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM
import qualified Data.IntSet as IS
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Data.List
import Debug.Trace

solve :: Int -> Int -> [Int] -> [(Int,Int)] -> Int
solve n m ps xys = runST act where
  
  act = do
    grp <- uftInit (n+1)
    mapM_ (uncurry (uftMerge grp)) xys
    vec <- VM.replicate (n+1) ([], [])
    forM_ (zip [n,n-1..1] (reverse ps)) $ \(i,p) -> 
      uftRoot grp i >>= VM.modify vec (\(is, ps) -> (i:is, p:ps))
    foldl' (op vec) (return 0) [1..n] where
      op vec msum j = do
        sum <- msum
        (is, ps) <- VM.read vec j
        return $ sum + IS.size (IS.intersection (IS.fromDistinctAscList is)
                                                (IS.fromList ps))

uftInit :: Int -> ST s (VUM.MVector s Int)
uftInit size = do
  vec <- VUM.new size
  forM_ [0..size-1] $ \i -> VUM.write vec i i
  return vec

uftMerge :: VUM.MVector s Int -> Int -> Int -> ST s ()
uftMerge vec x y = do
  rx <- uftRoot vec x
  ry <- uftRoot vec y
  if rx == ry then return ()
              else VUM.write vec rx ry

uftRoot :: VUM.MVector s Int -> Int -> ST s Int
uftRoot vec x = do
  y <- VUM.read vec x
  if x == y then return x
            else uftRoot vec y >>= vum_write_ret vec x

vum_write_ret :: VUM.Unbox a => VUM.MVector s a -> Int -> a -> ST s a
vum_write_ret vec i a = VUM.write vec i a >> return a

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      line2:remLines2 = remLines1
      ps = map readBInt line2
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve n m ps xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "5 2\n5 3 1 4 2\n1 3\n5 4\n"
inp2 = "3 2\n3 2 1\n1 2\n2 3\n"
inp3 = "10 8\n5 3 6 8 7 10 9 1 2 4\n3 1\n4 1\n5 9\n2 5\n6 5\n3 5\n8 9\n7 9\n"
inp4 = "5 1\n1 2 3 4 5\n1 5\n"
inp5 = "5 5\n5 4 1 2 3\n4 3\n2 3\n3 1\n1 5\n4 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 2
test2 = tv2 == 3
test3 = tv3 == 8
test4 = tv4 == 5
alltest = test1 && test2 && test3 && test4
