import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad

solve :: Int -> Int -> [(Int,Int,Char)] -> Int
solve n k xycs = answer where

  _cell = VU.create $ do
    vec <- VUM.replicate (k*k) 0
    forM_ (map (absPt k) xycs) $ \(x,y,t) -> VUM.modify vec (+ t) (enc x y)
    return vec
  
  enc x y = x*k + y
  cell x y = _cell VU.! (enc x y)

  bars0 = [sum [cell i j | i <- [0..k-1]] | j <- [0..k-1]]
  val0 = sum bars0

  starts = unfoldr f (0, val0, bars0) where
    f (i, val, bars) | i == k = Nothing
                     | otherwise = Just ((val, bars), (i+1, val', bars'))
      where
      bars' = zipWith g [0..] bars where
        g j x = x - 2 * cell i j
      val' = val - sum [2 * cell i j | j <- [0..k-1]]

  calcV (val, bars) = maximum (map abs (scanl' f val bars)) where
    f val bar = val - 2 * bar

  answer = (n + (maximum (map calcV starts))) `div` 2

absPt k (x,y,c) =
  let (dx, mx) = divMod x k
      (dy, my) = divMod y k
      t | (c == 'B') `xor` (dx `mod` 2 == 1) `xor` (dy `mod` 2 == 1) =  1
        | otherwise                                                  = -1
  in (mx, my, t)

xor :: Bool -> Bool -> Bool
xor x y = ((not x) && y) || (x && not y)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let line0:remLines1 = map B.words (B.lines cont)
      [n, k] = map readBInt line0
      fmt [x1, x2, x3] = (readBInt x1, readBInt x2, B.head x3)
      xycs = map fmt remLines1
  in solve n k xycs

main :: IO ()
main = putStrLn . show . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "4 3\n0 1 W\n1 2 W\n5 3 B\n5 4 B\n"
inp2 = "2 1000\n0 0 B\n0 1 W\n"
inp3 = "6 2\n1 2 B\n2 1 W\n2 2 B\n1 0 B\n0 6 W\n4 5 W\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 4
test2 = tv2 == 2
test3 = tv3 == 4
alltest = test1 && test2 && test3
