import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import Control.Monad
import System.Environment

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

getMax :: V.Vector Int -> Int
getMax = V.foldl1' max 

getMax2 :: V.Vector Int -> Int
getMax2 vec = maximum $ V.toList vec

main :: IO ()
main = do
  [sarg] <- getArgs
  let arg = read sarg
  conts <- B.getContents
  let strs = B.words conts
      vec = V.fromList $ map (fst . fromJust . B.readInt) $ strs
      m = case arg of
        1 -> getMax vec
        2 -> getMax2 vec
        3 -> vec V.! 399999
  putStrLn (show m)
