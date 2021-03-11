{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [String] -> Int
solve h w ss = runST $ VM.replicateM h (VUM.replicate w False) >>= act1
  where

  board = V.fromListN h (map (VU.fromListN w) ss)
  color (i,j) = board V.! i VU.! j

  nbr (i,j) = filter inBoard $
                map (addPair (i,j)) [(-1,0), (1,0), (0,-1), (0,1)]
  inBoard (i,j) = 0 <= i && i < h && 0 <= j && j < w

  indices = [(i,j) | i <- [0..h-1], j <- [0..w-1]]

  act1 visited = 
    collect <$> (forM indices $ \z -> act2 (color z) z)
    where
  
    collect = sum . map (\(s,t) -> s*t)
  
    act2 c0 (i,j) = do
      vi <- VM.read visited i
      b <- VUM.read vi j
      if b || (c0 /= color (i,j)) then return (0,0)
        else do
        VUM.write vi j True
        lst <- mapM (act2 (cRev c0)) (nbr (i,j))
        let (s, t) = sumPair lst
        return (t+1, s)

addPair (!a,!b) (!c,!d) = (a+c, b+d)
sumPair = foldl' addPair (0,0)
        
cRev '.' = '#'
cRev '#' = '.'

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_h,bs_w]:remLines1 = remLines0
      h = readBInt bs_h
      w = readBInt bs_w
      ss = map (\[x] -> B.unpack x) remLines1
  in solve h w ss

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "3 3\n.#.\n..#\n#..\n"
inp2 = "2 4\n....\n....\n"
inp3 = "4 3\n###\n###\n...\n###\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 10
test2 = tv2 == 0
test3 = tv3 == 6
alltest = test1 && test2 && test3
