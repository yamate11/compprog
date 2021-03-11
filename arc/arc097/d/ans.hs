{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM
import qualified Data.IntSet as IS
import Debug.Trace

solve :: Int -> Int -> [Int] -> [(Int,Int)] -> Int
solve n m ps xys = answer where
  
  grp0 = foldr (uncurry uftMerge) IM.empty xys

  im1 :: IM.IntMap (IS.IntSet, IS.IntSet)
--  grp0xxx = (trace ("grp0" ++ show grp0) grp0)
  grp0xxx = grp0
  (im1, _) = foldr op (IM.empty, grp0xxx) (zip [1..] ps) where
    op :: (Int, Int) -> (IM.IntMap (IS.IntSet, IS.IntSet), IM.IntMap Int)
       -> (IM.IntMap (IS.IntSet, IS.IntSet), IM.IntMap Int)
    op (n, p) (jm, grp) = (jm', grp') where
      (r, grp') = getRoot n grp
      jm' = IM.alter f r jm where
        f Nothing         = Just (IS.singleton n, IS.singleton p)
        f (Just (cn, cp)) = Just (IS.insert n cn, IS.insert p cp)

  answer = foldr op 0 im1 where
    op (cn, cp) sum = sum + IS.size (IS.intersection cn cp)

uftMerge :: Int -> Int -> IM.IntMap Int -> IM.IntMap Int
uftMerge x y im | rx == ry = im
                | otherwise = IM.insert rx ry im2
  where (rx, im1) = getRoot x im
        (ry, im2) = getRoot y im1

getRoot :: Int -> IM.IntMap Int -> (Int, IM.IntMap Int)
getRoot x im = case IM.lookup x im of
                 Nothing -> (x, im)
                 Just y -> let (root, im1) = getRoot y im
                           in (root, IM.adjust (const root) x im1)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n,bs_m]:remLines1 = remLines0
      n = readBInt bs_n
      m = readBInt bs_m
      line2:remLines2 = remLines1
      ps = map readBInt line2
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines2
  in solve n m ps xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

----------------------------------------------------------------------

inp1 = "5 2\n5 3 1 4 2\n1 3\n5 4\n"
inp2 = "3 2\n3 2 1\n1 2\n2 3\n"
inp3 = "10 8\n5 3 6 8 7 10 9 1 2 4\n3 1\n4 1\n5 9\n2 5\n6 5\n3 5\n8 9\n7 9\n"
inp4 = "5 1\n1 2 3 4 5\n1 5\n"
inp5 = "5 5\n5 4 1 2 3\n4 3\n2 3\n3 1\n1 5\n4 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 2
test2 = tv2 == 3
test3 = tv3 == 8
test4 = tv4 == 5
alltest = test1 && test2 && test3 && test4
