{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> Int -> [(Int,Int)] -> Int
solve n c xvs = answer where
  xs = map fst xvs
  vs = map snd xvs
  xsR = map (c -) (reverse xs)
  vsR = reverse vs
  answer = max (solveSub xs vs xsR vsR) (solveSub xsR vsR xs vs)

solveSub :: [Int] -> [Int] -> [Int] -> [Int] -> Int
solveSub xs vs xsR vsR = answer where
  calcG val cost = tail $ scanl' max 0 $
                        zipWith (-) (scanl' (+) 0 val) (0:cost)
  gainA = calcG vs (map (* 2) xs)
  gainB = calcG vsR xsR
  answer = maximum $ zipWith (+) gainA (reverse gainB)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_c]:remLines1 = remLines0
      n = readBInt bs_n
      c = readBInt bs_c
      xvs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n c xvs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3 20\n2 80\n9 120\n16 1\n"
inp2 = "3 20\n2 80\n9 1\n16 120\n"
inp3 = "1 100000000000000\n50000000000000 1\n"
inp4 = "15 10000000000\n400000000 1000000000\n800000000 1000000000\n1900000000 1000000000\n2400000000 1000000000\n2900000000 1000000000\n3300000000 1000000000\n3700000000 1000000000\n3800000000 1000000000\n4000000000 1000000000\n4100000000 1000000000\n5200000000 1000000000\n6600000000 1000000000\n8000000000 1000000000\n9300000000 1000000000\n9700000000 1000000000\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 191
test2 = tv2 == 192
test3 = tv3 == 0
test4 = tv4 == 6500000000
alltest = test1 && test2 && test3 && test4
