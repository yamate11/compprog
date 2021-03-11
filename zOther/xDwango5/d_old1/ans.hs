-------------------------------------------------------------------------------
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

trace s a = a

solve :: Int -> Int -> [(Int,Int)] -> Int
solve n d xys = lenA * d + (binsch 0 d) - 1
  where

  enc x y = (y * d) + x

  vec :: VU.Vector Int
  vec = VU.create $ do
    v <- VUM.replicate (d*d) 0
    forM_ xys $ \(x,y) -> do
      VUM.modify v (+ 1) (enc (x `mod` d) (y `mod` d))
    return v

  dMax = VU.maximum vec
  lenA = sqrtP dMax - 1
  brdrB = lenA * lenA
  brdrA = lenA * (lenA + 1)

  dAdd p q = (p + q) `mod` d
  distAx = trace ("dist " ++ show (distAx0, distAy, distByx)) distAx0
  distAx0 = VU.fromList $
    scanl' (+) 0 [b2i (or [over x y brdrA | y <- [0..d-1]]) | x <- [0..d-1]]
  distAy = VU.fromList $
    scanl' (+) 0 [b2i (or [over x y brdrA | x <- [0..d-1]]) | y <- [0..d-1]]
  distByx = VU.fromList $
    scanl' (+) 0 [b2i (over x y brdrB) | y <- [0..d-1], x <- [0..d-1]]
  over x y brdr = vec VU.! (enc x y) > brdr

  sat b = trace ("sat " ++ show (b, a)) a
    where a = sat0 b

  sat0 b = or [satX x | x <- [0..d-1]]
    where
    wid = d - b

    satX x = vSame distAx xb && or (snd (mapAccumL f boxB [0..d-1]))
      where
        xb = x `dAdd` b
        f count y = (newCnt, count == 0 && vSame distAy yb)
          where
          yb = y `dAdd` b
          newCnt = count - bDif yb + bDif (yb `dAdd` (wid+1))
        boxB = sum $ map bDif [b..d-1]
        bDif yy = vDiff distByx (enc xb yy)

    vDiff vec base = trace ("vDiff " ++ show (vec, base, a)) a
      where a = vDiff0 vec base
    vDiff0 vec base | p1 == p2 = vec VU.! (p1*d + q2) - vec VU.! (p1*d + q1)
                    | otherwise = vec VU.! (p1*d + q2) - vec VU.! (p1*d)
                                 + vec VU.! (p2*d) - vec VU.! (p1*d + q1)
      where (p1, q1) =  base        `divMod` d
            (p2, q2) = (base + wid) `divMod` d
    vSame vec base = vDiff vec base == 0

  binsch lo hi | hi == lo + 1 = hi
  binsch lo hi | sat mid      = binsch lo mid
               | otherwise    = binsch mid hi
    where mid = (hi + lo) `div` 2

b2i :: Bool -> Int
b2i True = 1
b2i False = 0
  
sqrtP :: Int -> Int
sqrtP x | y * y == x = y
        | otherwise  = y+1
  where y = floor $ sqrt (fromIntegral x)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_d]:remLines1 = remLines0
      n = readBInt bs_n
      d = readBInt bs_d
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n d xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "3 1\n0 0\n1 0\n2 0\n"
inp2 = "19 2\n1 3\n2 3\n0 1\n1 1\n2 1\n3 1\n4 4\n5 4\n6 4\n7 4\n8 4\n8 3\n8 2\n8 1\n8 0\n7 0\n6 0\n5 0\n4 0\n"
inp3 = "8 3\n0 0\n0 3\n3 0\n3 3\n2 2\n2 5\n5 2\n5 5\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 1
test2 = tv2 == 4
test3 = tv3 == 4
inp4 = "2 3\n0 0\n1 1\n"
tv4 = tmain $ B.pack inp4
test4 = tv4 == 1
inp5 = "10 7\n6 6\n6 6\n6 6\n6 6\n7 6\n7 6\n7 6\n7 6\n9 6\n9 6\n"
tv5 = tmain $ B.pack inp5
test5 = tv5 == 8
alltest = test1 && test2 && test3 && test4 && test5
