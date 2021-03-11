{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace a b = b

data Tile = Horiz Int Int | Vert Int Int
  deriving (Eq, Show)

solve :: Int -> Int -> Int -> Int -> Maybe String
solve n m a b = answer
  where
  a0 | odd  n = a - aB
     | even n = a
  b0 | odd  m = b - bR
     | even m = b
  (a0D, a0M) = divMod a0 2
  (b0D, b0M) = divMod b0 2
  aB = min a m2d
  bR = min b n2d
  bottom | odd  n = [Horiz (n-1) (2*i) | i <- [0..aB-1]]
         | even n = []
  right  | odd  m = [Vert (2*j+p) (m-1) | j <- [0..bR-1]]
         | even m = []
    where p | odd n = 1
            | even n = 0
  (m2d, m2m) = divMod m 2
  (n2d, n2m) = divMod n 2
  addcell = odd n && odd m
  answer
    | a0 + b0 <= 2 * m2d * n2d - 1
      || ((a0 + b0 == 2 * m2d * n2d) && (even a0 || addcell))
    = Just str
    | otherwise = Nothing
  str = brd2str $ spec

  spec = trace ("spec " ++ show spec0) spec0
  spec0 = brd ++ rem a0M b0M ++ bottom ++ right

  brd = trace ("brd " ++ show brd0) brd0
  brd0 = concat $ zipWith f [(j,i) | j <- [n2d-1,n2d-2..0], i <- [0..m2d-1]]
                           (replicate a0D 'H' ++ replicate b0D 'V')
    where f (j,i) 'H' = [Horiz (2*j) (2*i), Horiz (2*j+1) (2*i)]
          f (j,i) 'V'  = [Vert  (2*j) (2*i), Vert  (2*j) (2*i+1)]
  rem 0 0 = []
  rem 1 0 = [Horiz 0 xTR]
  rem 0 1 = [Vert  0 xTR]
  rem 1 1 | addcell =   [Vert 0 xTR, Horiz 0 (xTR+1)]
          | otherwise = [Vert 0 xTR, Horiz 0 (xTR-2)]
  xTR = 2 * (m2d - 1)  

  brd2str spec = unlines $ unfoldr f $ VU.toList $ VU.create $ act spec
    where f "" = Nothing
          f s = Just (splitAt m s)

  enc j i = (j * m) + i

  act spec = do
    vec <- VUM.replicate (n*m) '.'
    mapM_ (f vec) spec
    return vec
    where
    f vec (Horiz j i) = do
      VUM.write vec (enc j i) '<'
      VUM.write vec (enc j (i+1)) '>'
    f vec (Vert j i) = do
      VUM.write vec (enc j i) '^'
      VUM.write vec (enc (j+1) i) 'v'

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m,bs_a,bs_b]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      a = readBInt bs_a
      b = readBInt bs_b
  in solve n m a b

outAnswer :: Maybe String -> IO ()
outAnswer Nothing = putStrLn "NO"
outAnswer (Just s) = putStr ("YES\n" ++ s)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3 4 4 2\n"
inp2 = "4 5 5 3\n"
inp3 = "7 9 20 20\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
