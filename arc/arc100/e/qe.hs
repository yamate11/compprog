{-# LANGUAGE BangPatterns #-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import qualified Data.Vector.Unboxed as VU
import Data.List
import Debug.Trace

type Vec = VU.Vector (Int, Int)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

cum_max :: [Int] -> [Int]
cum_max = tail . scanl' max 0

nextZeta :: Int -> Vec -> Int -> Vec
nextZeta en v i = VU.fromList $ map op [0..en-1]
  where
    op x | testBit x i = f (v VU.! (clearBit x i)) (v VU.! x)
         | otherwise   = v VU.! x
      where
        f (q1, q2) (p1, p2) | q1 >= p1  = (q1, max q2 p1)
                            | otherwise = (p1, max p2 q1)

zeta :: Int -> [Int] -> Vec
zeta n as = foldl' (nextZeta en) initvec [0..n-1] 
  where
    en = 2^n
    initvec = VU.fromList [(a,0) | a <- as]

solve :: Int -> [Int] -> [Int]
solve n as = cum_max $ tail $ map (\(p,q)->p+q) $ VU.toList $ zeta n as

main :: IO ()
main = do
  conts <- B.getContents
  let n : as = bsReadInts conts
      answer = solve n as
  putStr (unlines (map show answer))

run1 = solve 2 [1,2,3,1]
test1 = run1 == [3,4,5]

run2 = solve 3 [10,71,84,33,6,47,23,25]
test2 = run2 == [81,94,155,155,155,155,155]

run3 = solve 4 [75,26,45,72,81,47,97,97,2,2,25,82,84,17,56,32]
test3 = run3 == [101,120,147,156,156,178,194,194,194,194,194,194,194,194,194]
