{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> (Int, [(Int, Int)])
solve n = let ms = solve1 n in (length ms, ms)

solve1 n | even n = solveA n
         | n `mod` 4 == 1 = solveB n
         | n `mod` 4 == 3 = solveC n

solveA n = concat [f i | i <- [1..n]]
  where f i = [(i, j) | j <- [i+1..n], i /= j, i + j /= n+1]

solveB n = [(i,j) | i <- [1..n], j <- [i+1..n], not (except i j)]
  where
    except i j | i == j = True
               | i + j == n = True
               | otherwise = False

solveC n = [(i, j) | i <- grp1, j <- grp2]
  where
    m = (n - 1) `div` 4
    grp1 = sort ([4*k+1 | k <- [0..m]] ++ [4*k+2 | k <- [0..m]])
    grp2 = sort ([4*k+0 | k <- [1..m]] ++ [4*k+3 | k <- [0..m]])



readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int, [(Int, Int)])
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
  in solve n

outAnswer :: (Int, [(Int, Int)]) -> IO ()
outAnswer (m, lstAB) = do
  putStrLn $ show m
  forM_ lstAB $ \(a,b) -> putStrLn (show a ++ " " ++ show b)

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "3\n"
tv1 = tmain $ B.pack inp1
test1 = tv1 == (2, [(1,3), (2,3)])
alltest = test1

