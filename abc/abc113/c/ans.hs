{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import Control.Monad

solve :: Int -> Int -> [(Int,Int)] -> [String]
solve n m pys = answer where
  
  perPref = V.create $ do
    vec <- VM.replicate (n+1) []
    forM_ (zip [0..] pys) $ \(i,(p,y)) -> VM.modify vec ((y,i):) p
    return vec

  answer = map snd $ sort $ concat [label p (perPref V.! p) | p <- [1..n]]

label p yis = zipWith f [1..] (sort yis) where
  f j (_,i) = (i, fmt p ++ fmt j)

fmt x = let s = "00000" ++ (show x)
        in drop (length s - 6) s

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [String]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      pys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve n m pys

outAnswer :: [String] -> IO ()
outAnswer = putStrLn . unlines

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "2 3\n1 32\n2 63\n1 12\n"
inp2 = "2 3\n2 55\n2 77\n2 99\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
