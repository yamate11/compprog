import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import Data.Foldable
import Control.Monad.ST
import Control.Monad

main :: IO ()
main =
  putStr . unlines . map (unwords . map show)
  . solveG
  . map (map (fst . fromJust . B.readInt) . B.words) . B.lines
  =<< B.getContents

solveG :: [[Int]] -> [[Int]]
solveG [[n], as] = [[solve n as]]

divisors :: Int -> V.Vector [Int]
divisors n = V.create $ do
  vec <- VM.replicate (n + 1) []
  for_ [1 .. n] $ \i ->
    for_ [i, (2*i) .. n] $ \j ->
      VM.modify vec (i :) j
  return vec

solve :: Int -> [Int] -> Int
solve n as = 0
  where

    nDivisors = divisors n

    f :: ST s Int
    f = do
      vecA <- VM.new (n + 1)
      for_ (zip [1..] as) $ \(i, a) -> VM.write vecA i (a, True)
      vecS <- VM.new (n + 1)
--      for_ [1 .. n] $ \i -> sumVec [i, i*2 .. n] vecA >>= VM.write vecS i 
      act [n, n-1 .. 1] vecA vecS

    sumVec :: [Int] -> VM.MVector s (Int, Bool) -> ST s Int
    sumVec is vecA = foldM f 0 is
      where f x i = return . (+ x) . fst =<< VM.read vecA i

    act :: [Int] -> VM.MVector s (Int, Bool)
      -> VM.MVector s Int -> ST s Int
    act [] _ vecS = VM.read vecS 1
    act (c : cands) vecA vecS = do
      s <- sumVec [c, c*2 .. n] vecA
      VM.write vecS c s
      if s >= 0 then act cands vecA vecS else
        for_ [c, 2*c, .. n] $ \i -> do
          (a, st) <- VM.read vecA i
          chgsA <- if st do
            VM.write vecA (0, False)
            divs <- VM.read nDivisors i
            chgs <- for [d | d <- divs, d > c] $ \d -> do
              v <- VM.read vecS d
              VM.write vecS d (v - a)
              return if v >= 0 && v - a < 0 then [d] else []
            return (concat chgs)
          else return []
