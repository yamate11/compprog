{-# LANGUAGE ViewPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as M
import Data.List

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

data Tree = Leaf Int Int [Int]
          | Node Int Tree Tree
            deriving(Show)
leafList :: Tree -> [Int]
leafList (Leaf _ _ lst) = lst

mkLeaf :: Int -> M.IntMap Int -> Int -> Int -> Tree
mkLeaf k im i num =
  Leaf i num $ take (num - (k-1)) $ sort [im M.! x | x <- [i .. i+num-1]]

bldNode :: Int -> Tree -> Tree -> Tree
bldNode idx (leafList -> []) (leafList -> []) = Leaf idx 0 []
bldNode _   (leafList -> []) right            = right
bldNode _   left             (leafList -> []) = left
bldNode idx left             right            = Node idx left right

nextTree :: Int -> M.IntMap Int -> Int -> Tree -> Tree
nextTree k im idx tr@(Leaf i num _)
  | i <= idx && idx < i + num
        = bldNode idx (mkLeaf k im i         (idx - i))
                      (mkLeaf k im (idx + 1) (num - (idx - i) - 1))
  | otherwise = tr
nextTree k im idx (Node i trL trR)
  | idx < i   = Node i (nextTree k im idx trL) trR
  | otherwise = Node i trL (nextTree k im idx trR)
  
allEff :: Tree -> [Int]
allEff (Leaf _ _ lst)      = lst
allEff (Node _ left right) = allEff left ++ allEff right

step :: Int -> Int -> M.IntMap Int -> Int -> Tree -> Maybe (Int, Tree)
step k q im idx tr
  = let eff = allEff tr
        y:_ = drop (q-1) (sort eff)
    in if length eff <= q-1 then Nothing
                            else Just (y - im M.! idx, nextTree k im idx tr)

mkrec :: Int -> Int -> M.IntMap Int -> [Int] -> Tree -> [Int]
mkrec k q im [] tree = []
mkrec k q im (idx : indices) tree =
  case step k q im idx tree of
  Nothing           -> []
  Just (y, newTree) -> y : mkrec k q im indices newTree

solve :: Int -> Int -> Int -> [Int] -> Int
solve n k q as =
  let ias = zip [0..] as 
      im = M.fromList ias
  in minimum $ mkrec k q im (map fst $ sortOn snd ias) $ mkLeaf k im 0 n

main :: IO ()
main = do
  conts <- B.getContents
  let n:k:q:as = bsReadInts conts
      answer = solve n k q as
  putStrLn (show answer)

test1 = 10 == val1
val1 = solve 5 3 2 [40,30,10,50,20]
test1a = 0 == solve 3 1 1 [40,30,10]
test1b = 10 == solve 3 1 2 [10,30,40]

test2 = 70 == solve 10 1 6
                   [10, 10, 20, 30, 50, 80, 130, 210, 340, 550]
test3 = 451211184 ==
  solve 11 7 5
        [24979445,861648772,623690081,433933447,476190629,262703497,211047202,971407775,628894325,731963982,822804784]

