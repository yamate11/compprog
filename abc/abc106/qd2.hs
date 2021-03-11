import Data.List
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.ST
import Control.Monad

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> Int -> Int -> [(Int,Int)] -> [(Int,Int)] -> [Int]
solve n _ _ lrs pqs = map f pqs
  where 
    f (p,q) = tbl V.! q VU.! q - tbl V.! (p-1) VU.! q
    tbl = V.scanl1' (VU.zipWith (+)) 
          $ V.map (VU.scanl1' (+))
          $ V.generate (n+1)
          $ \i -> VU.slice (i*(n+1)) (n+1) $ VU.create $ act n lrs
    
act :: Int -> [(Int,Int)] -> ST s (VUM.MVector s Int)
act n lrs = do
  vec <- VUM.replicate ((n+1) * (n+1)) 0
  forM_ lrs $ \(s,r) -> VUM.modify vec (+ 1) (s*(n+1) + r)
  return vec

tmain :: B.ByteString -> [Int]
tmain cont =
  let line1 : rest = B.lines cont
      [n,m,q] = bsReadInts line1
      (part1, part2) = splitAt m rest
      form = map ((\[s,e] -> (s,e)) . bsReadInts)
  in solve n m q (form part1) (form part2)

main :: IO ()
main = putStr . unlines . map show . tmain =<< B.getContents

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == [3]
test2 = tv2 == [1,1]
test3 = tv3 == [7,9,10,6,8,9,6,7,8,10]
alltest = test1 && test2 && test3

inp1 = "\
\2 3 1\n\
\1 1\n\
\1 2\n\
\2 2\n\
\1 2\n\
\"

inp2 = "\
\10 3 2\n\
\1 5\n\
\2 8\n\
\7 10\n\
\1 7\n\
\3 10\n\
\"

inp3 = "\
\10 10 10\n\
\1 6\n\
\2 9\n\
\4 5\n\
\4 7\n\
\4 7\n\
\5 8\n\
\6 6\n\
\6 7\n\
\7 9\n\
\10 10\n\
\1 8\n\
\1 9\n\
\1 10\n\
\2 8\n\
\2 9\n\
\2 10\n\
\3 8\n\
\3 9\n\
\3 10\n\
\1 10\n\
\"
