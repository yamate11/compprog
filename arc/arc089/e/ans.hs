{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
trace _ = id

data Plane = Plane {p_rx::Int, p_ry::Int, p_z0::Int}
           deriving (Eq, Ord, Show)

solve :: Int -> Int -> [[Int]] ->
         Maybe (Int, Int, [(Int, Int, String)], Int, Int)
solve a b d | possible = Just build
            | otherwise = Nothing
  where
    vd = VU.fromListN (a*b) (concat d)
    enc x y = (x-1) * b + (y-1)
    valyx x y | trace ("valyx" ++ show (x,y)) False = undefined
    valyx x y | x <= 0 || y <= 0 = 0
              | otherwise      = vd VU.! (enc x y)
    tri' = [ptPlane x y | x <- [1..a], y <- [1..b]]
    ptPlane x y = [Plane rx ry z0
                  | rx <- cands_rx, ry <- cands_ry,
                    let z0 = calc_z rx ry, checkConvex rx ry z0]
      where
      calc_z rx ry = valyx x y - rx*x - ry*y
      cands_rx
        | x == a    = [0]
        | otherwise = [valyx (x+1) y - valyx x y .. valyx x y - valyx (x-1) y]
      cands_ry
        | y == b    = [0]
        | otherwise = [valyx x (y+1) - valyx x y .. valyx x y - valyx x (y-1)]
    xyPair = [(x,y) | x <- [1..a], y <- [1..b]]
    checkConvex rx ry z0
      = all (\(x,y) -> rx*x + ry*y + z0 >= valyx x y) xyPair

    possible = all (not . null) tri'

    tri = trace ("tri " ++ show tri0) tri0
    tri0 = nub $ map head tri'

    yMax = maximum $ map p_ry tri
    safeMax [] = 0
    safeMax xs = maximum xs
    lxMax = [safeMax $ map p_rx $ filter ((== ry) . p_ry) tri
            | ry <- [0..yMax]]
    board = [(u+1,v+1,c) | (u,v,c) <- boardM]
    boardM = [connY y | y <- [0..yMax-1]]
             ++ [connX y x | y <- [0..yMax], x <- [0 .. (lxMax !! y) - 1]]
             ++ [connP p | p <- tri]
    connY y = (bEncY y, bEncY (y+1), "Y")
    connX y x = (bEncX y x, bEncX y (x+1), "X")
    connP (Plane rx ry z0) = (bEncX ry rx, bEncT, show z0)
    bEncY y = y
    bEncX y 0 = bEncY y
    bEncX y x = (yMax+1) + (accXMax !! y) + (x-1)
    bEncT = (yMax+1) + (accXMax !! (yMax+1)) 
    accXMax = scanl' (+) 0 lxMax
    build = (bEncT + 1, length board, board, 1, bEncT + 1)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Maybe (Int, Int, [(Int, Int, String)], Int, Int)
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_a,bs_b]:remLines1 = remLines0
      a = readBInt bs_a
      b = readBInt bs_b
      d = map (map readBInt) remLines1
  in solve a b d

outAnswer :: Maybe (Int, Int, [(Int, Int, String)], Int, Int) -> IO ()
outAnswer Nothing               = putStrLn "Impossible"
outAnswer (Just (n,m,uvcs,s,t)) = do
  putStrLn "Possible"
  putStrLn $ unwords $ map show [n,m]
  putStr $ unlines $ map (\(u,v,s) -> unwords [show u, show v, s]) uvcs
  putStrLn $ unwords $ map show [s,t]

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "2 3\n1 2 2\n1 2 3\n"
inp2 = "1 3\n100 50 1\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2

