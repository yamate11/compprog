{-# LANGUAGE BangPatterns #-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.Bits
import Debug.Trace

data MyTrie = MTnode Bool (Maybe MyTrie) (Maybe MyTrie)
            deriving(Show)

mtAdd :: Maybe MyTrie -> B.ByteString -> MyTrie
mtAdd xx@(Just (MTnode b mt0 mt1)) bs
  | B.null bs        = MTnode True mt0 mt1
  | B.head bs == '0' = MTnode b (Just (mtAdd mt0 (B.tail bs))) mt1
  | B.head bs == '1' = MTnode b mt0 (Just (mtAdd mt1 (B.tail bs)))
  | otherwise        = mtAdd xx (B.tail bs)
mtAdd Nothing bs = mtAdd (Just (MTnode False Nothing Nothing)) bs
  
toIntList :: Int -> Maybe MyTrie -> [Int]
toIntList _ Nothing = []
toIntList _ (Just (MTnode True Nothing Nothing)) = []
toIntList _ (Just (MTnode True _ _)) = error "Should not happen"
toIntList !d (Just (MTnode False (Just mt0) Nothing)) = tILSingle d mt0
toIntList !d (Just (MTnode False Nothing (Just mt1))) = tILSingle d mt1
toIntList !d (Just (MTnode False (Just mt0) (Just mt1))) 
  = toIntList (d - 1) (Just mt0) ++ toIntList (d - 1) (Just mt1)

tILSingle :: Int -> MyTrie -> [Int]
tILSingle !d mt = d : toIntList (d - 1) (Just mt)

toLSB :: Int -> Int
toLSB x = bit (countTrailingZeros x)

solve :: Int -> [B.ByteString] -> String
solve cL bss =
  let mt = foldr (\x y -> Just (mtAdd y x)) Nothing bss
      ns = toIntList cL mt
      val = foldr xor 0 (map toLSB ns)
  in if val == 0 then "Bob" else "Alice"

main :: IO ()
main = do
  cont <- B.getContents
  let line1 : lines = B.lines cont
  let [_, cL] = (map (fst . fromJust . B.readInt) . B.words) line1
--  putStrLn (show lines)
  putStrLn $ solve cL lines

