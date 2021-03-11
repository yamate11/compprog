{-
This file demonstrates how to read data from standard input.
-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

-- bsReadInts bstr
--   Reads and returns the list of int separated by space.
--   Usually bstr is one line, but can consist of two or more lines.
bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

{-
Example:
----------------------------------------
n k
a_11 a_12 ... a_1k
...
a_n1 a_n2 ... a_nk
----------------------------------------
-}

main :: IO ()
main = do
  conts <- B.getContents
  let [n, k] : iss = map bsReadInts (B.lines conts)
      answer = solve n k iss
  putStrLn (show answer)
  where solve :: Int -> Int -> [[Int]] -> Int
        solve n k iss = n + k + (iss !! 0 !! 0)  + (iss !! (n - 1) !! (k - 1))

{-
Note:
ByteString for output may not be very effective.  when nss is [[Int]],
(1) is much faster than (2):
    putStr   $ unlines   $ map (unwords   . map show)            nss -- (1)
    B.putStr $ B.unlines $ map (B.unwords . map (B.pack . show)) nss -- (2)
  
-}

