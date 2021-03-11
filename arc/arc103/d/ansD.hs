-- This file was written after reading the editorial.

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

solve :: Int -> [[Int]] -> (Int, [Int], [String])
solve n xys
  | check rem rest = solve0 rem n xys
  | otherwise = (-1, [], [])
  where
    [x0,y0] : rest = xys
    rem = (x0 + y0) `mod` 2

check :: Int -> [[Int]] -> Bool  
check rem xys = all (\[x,y] -> (x+y) `mod` 2 == rem) xys

solve0 :: Int -> Int -> [[Int]] -> (Int, [Int], [String])
solve0 rem n xys
  | rem == 1 = solve1 n xys
  | rem == 0 = (m+1, 1 : ds, map ('R' :) ws)
  where
    (m, ds, ws) = solve1 n $ map (\[x,y] -> [x-1,y]) $ xys

solve1 :: Int -> [[Int]] -> (Int, [Int], [String])
solve1 n xys = (m0+1, ds, ws)
  where
    uvs = map (\[x,y] -> (x-y, x+y)) xys
    m0 :: Int
    m0 = debug_m uvs
    ds = [2^i | i <- [m0,m0-1..0]]
    ws = [mkDir u v | (u, v) <- uvs]
    mkDir :: Int -> Int -> String
    mkDir u v = map f (zip seq_u seq_v)
      where seq_u = mkSeq u
            seq_v = mkSeq v
            f :: (Int,Int) -> Char
            f (  1 ,   1 ) = 'R'
            f (  1 , (-1)) = 'D'
            f ((-1),   1 ) = 'U'
            f ((-1), (-1)) = 'L'
    mkSeq :: Int -> [Int]
    mkSeq x = unfoldList f x ds
      where f x d | x > 0     = ( 1, x - d)
                  | otherwise = (-1, x + d)

unfoldList :: (s -> a -> (b,s)) -> s -> [a] -> [b]
unfoldList f s as = unfoldr g (s,as)
  where g (_, [])   = Nothing
        g (s, a:as) = Just (b, (s',as))
          where (b, s') = f s a

debug_m :: [(Int,Int)] -> Int
debug_m uvs = ceiling (logBase (fromIntegral 2) (fromIntegral uvmax))
  where uvmax = maximum [max (abs u) (abs v) | (u,v) <- uvs]

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = do
  conts <- B.getContents
  let [n] : xys = map bsReadInts (B.lines conts)
      (m, ds, ws) = solve n xys
  if m < 0 then putStrLn "-1"
    else do
    putStrLn $ show m
    putStrLn $ unwords $ map show ds
    putStr $ unlines ws  
