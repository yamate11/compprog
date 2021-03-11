{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> (Int, [[Int]])
solve bigK = (wd, add ++ upper ++ lower)
  where
  upper = divide wd ht (cycle [1..m])
  lower = reverse $ map reverse upper

  wd | even bigK = 2 * size
     | odd bigK = 2 * size + 1
  ht = size
  add | even bigK = []
      | odd bigK = [replicate wd bigK]
  m | even bigK = bigK
    | odd bigK = bigK - 1

size = 4

divide wd ht xs = take ht $ unfoldr (Just . splitAt wd) xs

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int, [[Int]])
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigK]:remLines1 = remLines0
      bigK = readBInt bs_bigK
  in solve bigK

outAnswer :: (Int, [[Int]]) -> IO ()
outAnswer (n, xss) = do
  putStrLn $ show $ n
  putStr $ unlines $ map (unwords . map show) xss

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------
