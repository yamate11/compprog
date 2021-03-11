{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> [(Int,Int,Int,Int)] -> [Bool]
solve t abcds = map solveB abcds

solveB :: (Int,Int,Int,Int) -> Bool
solveB (a,b,c,d) = 
  (a >= b) && (d >= b) &&
  (a - g * ((a - (c+1)) `div` g) - b >= 0)
  where g = gcd b d

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Bool]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_t]:remLines1 = remLines0
      t = readBInt bs_t
      abcds = map (\[x1,x2,x3,x4] ->
                     (readBInt x1,readBInt x2,readBInt x3,readBInt x4))
              remLines1
  in solve t abcds

outAnswer :: [Bool] -> IO ()
outAnswer bs = do
  forM_ bs $ \b -> do
    putStrLn (if b then "Yes" else "No")

main :: IO ()
main = outAnswer . tmain =<< B.getContents

