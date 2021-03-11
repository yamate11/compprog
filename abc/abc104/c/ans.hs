{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [(Int,Int)] -> Int
solve d g pcs = minimum (catMaybes (map f power_d))
  where
    vec = VU.fromList ((0,0):pcs)
    power_d = power [1..d]
    f is | cs >= g = Just cn
         | otherwise = remainCount vec cn (g - cs) (filter h [d, d-1 .. 1])
      where
        (cn, cs) = complMark vec is
        h i = not (i `elem` is)

power :: [a] -> [[a]]
power [] = [[]]
power (x:ys) = map (x:) zs ++ zs
  where zs = power ys

complMark vec [] = (0, 0)
complMark vec (i:is) = (num + p, score + 100*i*p + c)
  where (p,c) = vec VU.! i
        (num, score) = complMark vec is

remainCount vec !acc !goal [] = Nothing
remainCount vec !acc !goal (i:is)
  | 100*i*(p-1) >= goal = Just $ acc + ((goal + 100*i-1) `div` (100*i))
  | otherwise = remainCount vec (acc+(p-1)) (goal-i*(p-1)) is
  where
    (p,c) = vec VU.! i

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_d,bs_g]:remLines1 = remLines0
      d = readBInt bs_d
      g = readBInt bs_g
      pcs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve d g pcs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-- --------------------------------------------------------------------

inp1 = "2 700\n3 500\n5 800\n"
inp2 = "2 2000\n3 500\n5 800\n"
inp3 = "2 400\n3 500\n5 800\n"
inp4 = "5 25000\n20 1000\n40 1000\n50 1000\n30 1000\n1 1000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 3
test2 = tv2 == 7
test3 = tv3 == 2
test4 = tv4 == 66
alltest = test1 && test2 && test3 && test4
