{-
This answer was written after referring to the editorial.
-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe

bsReadInts = map (fst . fromJust . B.readInt) . B.words

solve :: Int -> [Int] -> String
solve n as = if solve2 (zip [1..] as) then "Yes" else "No"

solve2 nas = all isGood $ unfoldr getPart nas

getPart :: [(Int,Int)] -> Maybe (([(Int,Int)], Int), [(Int,Int)])
getPart = f . dropWhile (uncurry (==)) 
  where
    f [] = Nothing
    f (na:nas) = Just ((na : nas1, len), nas2)
      where
        (nas1, nas2) = splitAt (2*len) nas
        len = length $ takeWhile prop $ binzip nas

prop ((n0,a0), (n1,a1)) = n0 == a0 && n1 /= a1

binzip = unfoldr f
  where f (x:y:p) = Just ((x,y), p)
        f _       = Nothing

isGood ([_], _) = False
isGood (nas, len) = ordpres left && ordpres right && all rangeOK nas
  where
    left =  [a | (n,a) <- nas, n < a]
    right = [a | (n,a) <- nas, n > a]
    rangeOK (_,a) = xmin <= a && a <= xmax
    xmin = snd (nas !! 1) - 1
    xmax = xmin + 2 * len

ordpres x = all (uncurry (<)) $ zip x (tail x)

main = do
  cont <- B.getContents
  let n : as = bsReadInts cont
  putStrLn $ solve n as

test1 = solve 5 [5,2,1,4,3] == "Yes"
test2 = solve 4 [3,2,4,1] == "No"
test3 = solve 7 [3,2,1,6,5,4,7] == "Yes"
test4 = solve 6 [5,3,4,1,2,6] == "No"
test5 = solve 6 [3,2,6,1,5,4] == "No"

alltest = test1 && test2 && test3 && test4 && test5



