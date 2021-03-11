import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.Vector.Mutable as VM
import Control.Monad
import Control.Monad.ST

data MyTree = MTleaf | MTnode Int [(Int, MyTree)]

mkTree :: Int -> [(Int, Int)] -> MyTree
mkTree numVert edges = runST act
  where
    act :: ST s MyTree
    act = do
      vecN <- VM.replicate (numVert + 1) []
      forM_ edges $ \(i, j) -> do
        VM.modify vecN (i :) j
        VM.modify vecN (j :) i
      (len, t) <- act1 1 Nothing vecN
      if (len == 0) then return t
        else return $ MTnode 1 [(len, t)]

    act1 :: Int -> Maybe Int -> VM.MVector s [Int] -> ST s (Int, MyTree)
    act1 i mk vecN = do
      cs' <- VM.read vecN i
      let cs = case mk of Nothing -> cs'
                          Just k -> [c | c <- cs', c /= k]
          numChildren = length cs
      case cs of
        [] -> return (0, MTleaf)
        [c] -> do
          (len, t) <- act1 c (Just i) vecN
          return (len + 1, t)
        _ -> do
          its <- forM cs $ \c -> act1 c (Just i) vecN
          return $ (0, MTnode numChildren (map (\(d, t) -> (d + 1, t)) its))
      
numPaths :: MyTree -> Int
numPaths MTleaf = 0
numPaths (MTnode n its) =
  sum (map numPaths children) + ((n + 1) `div` 2)
     - length [t | t <- children, acceptPath t]
  where 
    children = map snd its
    acceptPath MTleaf = False
    acceptPath (MTnode n _) | n `mod` 2 == 0 = False
    acceptPath (MTnode n _) | otherwise      = True

{-
  mkCands thr t = (newThr 
  
-}
mkCands :: Int -> MyTree -> (Int, [(Int, Int)])
mkCands thr t = 

solve :: Int -> [(Int, Int)] -> (Int, Int)
solve numVert edges = error ""
  where
    tree = mkTree numVert edges
    valA = numPaths tree
    (th, cands) = mkCands th tree
  
