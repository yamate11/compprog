import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

type MyS = (Int, Int, [(Int, [Int])])

solve :: Int -> Int -> Int -> [(Int,Int)] -> Int
solve bigH bigW bigN xys = minH - 1
  where
  board0 = map f_form $ groupBy f_grp $ sortOn f_sort xys
  f_grp (_,y) (_,y') = y == y'
  f_sort (x,y) = y * (bigH+1) + x
  f_form lst@((_,y):_) = (y, map fst lst)

  minH = minimum (catMaybes (unfoldr f_stUpd initState) ++ [bigH+1])
  initState :: MyS
  initState = (1, 1, board0)
  f_stUpd :: MyS -> Maybe (Maybe Int, MyS)
  f_stUpd (_, _, []) = Nothing
  f_stUpd (x, y, ((by, bxs):rem)) = Just (h, (newX, by, rem))
    where (newX, h) = vacSeat (x + (by - y)) bxs

-- vacSeat 5 [3,4,5,6] ---> (7,Nothing)
-- vacSeat 5 [3,4,5,6,10,12] ---> (7,Just 10)
vacSeat :: Int -> [Int] -> (Int, Maybe Int)
vacSeat t ts =
  head $ filter (\(p,q) -> Just p /= q) $ zip [t..]
  $ map Just (dropWhile (< t) ts) ++ [Nothing]

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bigH,bs_bigW,bs_bigN]:remLines1 = remLines0
      bigH = readBInt bs_bigH
      bigW = readBInt bs_bigW
      bigN = readBInt bs_bigN
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bigH bigW bigN xys

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents

inp1 = "3 3 1\n3 2\n"
inp2 = "10 10 14\n4 3\n2 2\n7 3\n9 10\n7 7\n8 1\n10 10\n5 4\n3 4\n2 8\n6 4\n4 4\n5 8\n9 2\n"
inp3 = "100000 100000 0\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 2
test2 = tv2 == 6
test3 = tv3 == 100000
alltest = test1 && test2 && test3
