import Data.List
import Data.Char
import Debug.Trace

mPrime = 10^9+7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mPow :: Int -> Int -> Int
mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x

mSum = foldl' mAdd 0

solve :: String -> Int
solve str = ans
-- (trace (show (cntL, cntR)) ans)
  where
    cntR = scanr f [0,0,0,0] str
      where f c v = zipWith (+) (vc c) v
    aCnt = head cntR
    cntL = map (zipWith (-) aCnt) cntR
    ans = mSum $ zipWith3 f str (init cntL) (tail cntR)
      where
        f z [la, lb, lc, lq] [ra, rb, rc, rq]
          | z == 'B' || z == '?' = (numz la lq) `mMul` (numz rc rq)
          | otherwise            = 0
        numz x 0 = x
        numz x y = (x `mMul` (mPow 3 y)) `mAdd` (y `mMul` (mPow 3 (y-1)))
    
vc 'A' = [1,0,0,0]
vc 'B' = [0,1,0,0]
vc 'C' = [0,0,1,0]
vc '?' = [0,0,0,1]

main :: IO ()
main = putStrLn . show . solve . takeWhile (not . isSpace) =<< getContents

tv1 = solve "A??C"
tv2 = solve "ABCBC"
tv3 = solve "????C?????B??????A???????"

test1 = tv1 == 8
test2 = tv2 == 3
test3 = tv3 == 979596887

