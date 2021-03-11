import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let n : ds = bsReadInts conts
      x = length (nub ds)
  putStrLn $ show x
