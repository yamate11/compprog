import Data.List
import Data.Tuple
import Data.Bits
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace

solve :: Int -> String
solve n = unlines $ map (unwords . map show) $ solve0 n

solve0 :: Int -> [[Int]]
solve0 n = take n $ tail $ unfoldr f $ VU.toList getTable
  where f [] = Nothing
        f xs = Just (take n (tail lst1), lst2)
          where (lst1, lst2) = splitAt 512 xs

prime9 = [2,3,4,5,7,9,11,13,17]
irr9 = concat $ zipWith (\p q -> [p,q]) ls1 (reverse ls2)
  where (ls1, rest) = splitAt 256 $ foldr op [2..] prime9
          where op p rem = filter (\x -> x `mod` p /= 0) rem
        ls2 = take 256 rest

bitPs :: Int -> Int
bitPs i = product $ zipWith (hat i) [0..8] prime9 
  where
    hat :: Int -> Int -> Int -> Int
    hat i j x | testBit i j = x
              | otherwise   = 1

enc :: (Int,Int) -> Int
enc (y,x) = y*512+x

dec :: Int -> (Int,Int)
dec i = divMod i 512

getTable :: VU.Vector Int
getTable = VU.create $ do
  table <- VUM.new (512*512)
  t_irr9 <- VUM.new 512
  forM_ (zip [0..] irr9) $ \(i,x) -> VUM.write t_irr9 i x
  forM_ [0..511] $ \u -> do
    forM_ [0..255] $ \v -> do
      let v' = 2*v + (if u `mod` 2 == 0 then 0 else 1)
      c <- VUM.read t_irr9 ((u + v') `div` 2)
      VUM.write table (enc (u,v')) (c * (bitPs u))
  forM_ [1..509] $ \s -> do
    used <- VUM.replicate 512 0
    forM_ (get_ijs s) $ \(i,j) -> do
      c1 <- VUM.read t_irr9 s
      c2 <- VUM.read t_irr9 (s+1)
      let t1 = (i-1) .|. i .|. (i+1)
      d <- VUM.read used t1
      VUM.write used t1 (d+1)
      VUM.write table (enc (i,j)) (c1*c2*(d+1)*(bitPs t1) + 1)
  return table

-- (i,j) \in get_ijs s <-> i+j = 2s+1, 1 <= i,j <= 510
get_ijs :: Int -> [(Int,Int)]
get_ijs s = zipWith (,) is js
  where (is,js) | s <= 255 = ([1..2*s], [2*s,2*s-1..1])
                | otherwise = ([2*s-509..510], [510,509..2*s-509])

tmain :: String -> String
tmain cont =
  let [n] = map read $ words cont
  in solve n

main = putStr . tmain =<< getContents

-- main = putStrLn . show . tmain =<< B.getContents


