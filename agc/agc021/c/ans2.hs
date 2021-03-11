-------------------------------------------------------------------------------
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace a b = b

-- data T2 = H2 | V2 | H1 | V1 | C | N
type T2 = Char

patT2 :: T2 -> (String, String)
patT2 'H' = ("<>", "<>")
patT2 'V' = ("^^", "vv")
patT2 'h' = ("<>", "..")
patT2 'v' = ("^.", "v.")
patT2 'C'  = (">^", ".v")
patT2 'N'  = ("..", "..")

solve :: Int -> Int -> Int -> Int -> Maybe String
solve n m a b | a0D + b0D + length rems <= n2d * m2d = Just answer
              | otherwise                            = Nothing
  where
  (m2d, m2m) = divMod m 2
  (n2d, n2m) = divMod n 2
  a0 | odd  n = a - aT
     | even n = a
  b0 | odd  m = b - bR
     | even m = b
  (a0D, a0M) = divMod a0 2
  (b0D, b0M) = divMod b0 2
  aT = min a m2d
  bR = min b n2d
  bottom :: [String]
  bottom | odd n = [take (2*m2d) (concat (replicate aT "<>") ++ repeat '.')]
         | otherwise = []
  left   | odd m && even n = left1
         | odd m && odd n = topLeft : left1
         | otherwise = repeat ""
    where
    left1 = map (\c -> [c]) $ concat (replicate bR "^v") ++ repeat '.'
    topLeft | odd a0 && odd b0 = "<"
            | otherwise = "."

  spec :: VU.Vector T2
  spec = VU.fromListN (n2d*m2d)
         $ rems ++ replicate a0D 'H' ++ replicate b0D 'V' ++ repeat 'N'

  rems | odd n && odd m && odd a0 && odd b0  = ['C']
       | otherwise =    (if a0M == 0 then [] else ['h'])
                     ++ (if b0M == 0 then [] else ['v'])

  strSpec :: [String]
  strSpec = concatMap f [0..n2d-1]
    where f j = [g fst j, g snd j]
          g sel j = concatMap (\i -> sel (patT2 (spec VU.! (j*m2d+i))))
                    [0..m2d-1]

  answer :: String
  answer = unlines $ zipWith (++) left (strSpec ++ bottom)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m,bs_a,bs_b]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      a = readBInt bs_a
      b = readBInt bs_b
  in solve n m a b

outAnswer :: Maybe String -> IO ()
outAnswer Nothing = putStrLn "NO"
outAnswer (Just s) = putStr ("YES\n" ++ s)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3 4 4 2\n"
inp2 = "4 5 5 3\n"
inp3 = "7 9 20 20\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
