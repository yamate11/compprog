import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Data.Vector.Unboxed ((!))
import qualified Data.Vector.Unboxed as VU

solve :: Int -> [Int] -> Int
solve n as = (fact n) `mMul` (mSum lst)
  where 
    revsum = mkRevsum n
    lst = [a `mMul` (1 `mAdd` (revsum ! (n-i+1)) `mAdd` (revsum ! i))
          | (i, a) <- zip [1..] as]

mkRevsum n = VU.fromListN (n+1) $ 0 : (scanl' mAdd 0 (unfoldr f 2))
  where f n = Just (mInv n, n + 1)

fact n = foldl' mMul 1 [1..n]

mSum = foldl' mAdd 0

-------------------------------------------------------------------------------

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

mPrime = 10^9 + 7

mAdd :: Int -> Int -> Int
mAdd x y = (x + y) `mod` mPrime

mSub :: Int -> Int -> Int
mSub x y = (x - y) `mod` mPrime    -- ok even if x < y

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

mInv :: Int -> Int
mInv x = let (_, a, _) = eGCD x mPrime in if a < 0 then a + mPrime else a

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)

-------------------------------------------------------------------------------

inp1 = "2\n1 2\n"
inp2 = "4\n1 1 1 1\n"
inp3 = "10\n1 2 4 8 16 32 64 128 256 512\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 9
test2 = tv2 == 212
test3 = tv3 == 880971923
alltest = test1 && test2 && test3
