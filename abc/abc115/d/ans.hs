import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU

solve :: Int -> Int -> Int
solve 0 0 = 0
solve 0 1 = 1
solve n x
  | x <= 1
  = 0
  | x <= 1 + lPrev
  = solve (n-1) (x-1)
  | x == 1 + lPrev + 1
  = pPrev + 1
  | x <= 1 + lPrev + 1 + lPrev
  = pPrev + 1 + solve (n-1) (x - (1 + lPrev + 1))
  | x == 1 + lPrev + 1 + lPrev + 1
  = pPrev + 1 + pPrev
  where lPrev = nLayer VU.! (n-1)
        pPrev = nPatty VU.! (n-1)

nLayer :: VU.Vector Int
nLayer = VU.fromListN 51 $ unfoldr f 1
  where f k = Just (k, 2*k + 3)
  
nPatty :: VU.Vector Int
nPatty = VU.fromListN 51 $ unfoldr f 1
  where f k = Just (k, 2*k + 1)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_x]:remLines1 = remLines0
      n = readBInt bs_n
      x = readBInt bs_x
  in solve n x

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "2 7\n"
inp2 = "1 1\n"
inp3 = "50 4321098765432109\n"
inp4 = "1 2\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 4
test2 = tv2 == 0
test3 = tv3 == 2160549382716056
test4 = tv4 == 1
alltest = test1 && test2 && test3 && test4
