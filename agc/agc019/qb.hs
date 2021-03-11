import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM
import Data.Char
import Data.List
import Control.Monad

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: String -> Int
solve a = 1 + answer
  where
    vec = V.create $ do
      v <- VM.replicate 26 0
      forM a $ \c -> do
        let idx = ord c - ord 'a'
        when (idx >= 0 && idx < 26) (VM.modify v (+ 1) idx)
      return v
    lst = V.toList vec
    answer = sum $ zipWith (*) lst $ map sum $ tail (tails lst)

main :: IO ()
main = do
  cont <- getContents
--  cont <- B.getContents
--  let answer = solve (B.unpack cont)
  let answer = solve cont
  putStrLn $ show answer
  
