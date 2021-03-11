import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (mPrime + x - y) `mod` mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

mPow :: Int -> Int -> Int
mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
  where
    f 0 _ = 1
    f 1 t = t
    bin_f 0 = Nothing
    bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
    binpow x = iterate (\t -> mMul t t) x

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let n : hs = bsReadInts conts
      answer = solve n hs
  putStrLn (show answer)

mk_blks :: Int -> [Int] -> (Int, [[Int]])
mk_blks _ [] = (0, [])
mk_blks mn hs = error ""
  case len of
    0 -> mk_blks mn (tail hs)
    1 -> let h1 : _ : rest = hs
             (n, result) = mk_blks mn rest
         in (n + (h1 - mn), result)
    _ -> let (n, result) = mk_blks mn (drop len hs)
         in (n, (talls : result))
  where
    talls = takeWhile (> mn) hs
    len = length talls

cnt_blk :: [Int] -> Int
cnt_blk hs = n + sum (map cnt_blk blks)
  where
    mn = minimum hs
    (n, blks) = mk_blks mn hs

solve :: Int -> [Int] -> Int
solve n hs = mPow 2 (2 * grp + indep)
  where
    (n0, blocks) = mk_blks 1 hs
    n1 = n - sum [length b | b <- blocks]
    n2 = sum [cnt_blk b | b <- blocks]
    indep = n0 + n1 + n2
    grp = length blocks
