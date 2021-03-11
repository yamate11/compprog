{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import Data.Bits
import qualified Data.IntMap.Strict as IM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [Int] -> Int
solve n as = answer
  where
  imap0 = foldl' op IM.empty as
    where op im a = IM.insertWith (+) a 1 im

  answer = sum $ unfoldr f imap0
    where
    f imap
      | IM.null imap = Nothing
      | x == b       = Just (m `div` 2, IM.delete x imapNxt)
      | otherwise    = fsub (IM.lookup x imap)
      where
      fsub Nothing = Just (0, imapNxt)
      fsub (Just k) | k <= m = Just (k, IM.delete x imapNxt)
                    | otherwise = Just (m, IM.adjust (+ (- m)) x imapNxt)
      ((b, m), imapNxt) = IM.deleteFindMax imap
      x = btox b

btox b = setBit 0 (64 - (countLeadingZeros b)) - b

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

----------------------------------------------------------------------

inp1 = "3\n1 2 3\n"
inp2 = "5\n3 11 14 5 13\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == 1
test2 = tv2 == 2
alltest = test1 && test2
