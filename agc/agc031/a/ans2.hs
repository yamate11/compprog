import qualified Data.Map.Strict as M

solve :: Int -> String -> Int
solve n s = 
  let
    initMap = M.fromDistinctAscList [(c,1) | c <- ['a'..'z']]
    theMap = foldr (M.adjust (+ 1)) initMap s
  in (M.foldl' mMul 1 theMap) `mSub` 1

mPrime :: Int
mPrime = 10^9 + 7

mSub :: Int -> Int -> Int
mSub x y = let w = x - y in if w >= 0 then w else w + mPrime

mMul :: Int -> Int -> Int
mMul x y = (x * y) `mod` mPrime

main = do
  cont <- getContents
  let [strN, s] = words cont
  putStrLn $ show $ solve (read strN) s

