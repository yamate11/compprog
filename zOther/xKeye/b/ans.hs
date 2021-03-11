{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: String -> Bool
solve s = "keyence" `elem` ts
  where
    len = length s
    ts = [ take i s ++ drop j s | i <- [0..len], j <- [i..len] ]
    

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Bool
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_s]:remLines1 = remLines0
      s = B.unpack bs_s
  in solve s

outAnswer :: Bool -> IO ()
outAnswer x = if x then putStrLn "YES" else putStrLn "NO"

main :: IO ()
main = outAnswer . tmain =<< B.getContents

