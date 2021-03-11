import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> [Int] -> (Int,Int)
solve n as = (p, q)
  where
    p = maximum as
    (_, q) = minimum $ map f $ filter (/= p) as
      where f a = (abs (2 * a - p), a)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> (Int,Int)
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: (Int,Int) -> IO ()
outAnswer (x,y) = putStrLn $ unwords $ map show [x,y]

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "5\n6 9 4 2 11\n"
inp2 = "2\n100 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == (11, 6)
test2 = tv2 == (100, 0)
alltest = test1 && test2
