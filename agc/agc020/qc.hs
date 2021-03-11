import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Data.List

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> [Int] -> Int
solve valN as = head [i | i <- [half..], testBit set i]
  where
    half = ((sum as) + 1) `div` 2
    set :: Integer
    set = foldl' op (bit 0) as
      where op x a = x .|. (shiftL x a)

main :: IO ()
main = do
  conts <- B.getContents
  let valN : as = bsReadInts conts
      answer = solve valN as
  putStrLn $ show $ answer


