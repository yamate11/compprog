{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as M
import Data.Bits

solve :: Int -> [Int] -> Int
solve n as = step 0 0 0 as as

step !acc !n _ _ [] = acc + sum [1..n]
step !acc !n !a (l:ls) (r:rs)
  | a + r == xor a r = step acc     (n+1) (a+r) (l:ls) rs
  | otherwise        = step (acc+n) (n-1) (a-l) ls     (r:rs)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let (n:as) = bsReadInts conts
      answer = solve n as
  putStrLn (show answer)
