import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM

-- Rooted Tree

type RTree = Int -> (Int, [Int])

{-
 If we set
    let tree = rootedTree xys root vSize
 then
    tree :: Int -> (Int, [Int])
    tree i = (parent of i, children of i)
 Note that:
   - vSize should be maxIndex+1
   - node indices should be nonnegative
   - (-1) is set as the "parent of root"
-}

rootedTree :: [(Int,Int)] -> Int -> Int -> RTree
rootedTree xys root vSize i = v V.! i where
  v = V.create $ ((,) <$> VM.replicate vSize [] <*> VM.new vSize) >>= act
  act (vec,vecRC) = do
    forM_ xys $ \(x,y) -> do
      VM.modify vec (x:) y
      VM.modify vec (y:) x
    rootChildren <- VM.read vec root
    setRC (-1) root
    return vecRC
    where
    setRC parent idx = do
      cs <- filter (/= parent) <$> VM.read vec idx
      VM.write vecRC idx (parent, cs)
      mapM_ (setRC idx) cs

rtParent :: RTree -> Int -> Int
rtParent tree node = fst (tree node)

rtChildren :: RTree -> Int -> [Int]
rtChildren tree node = snd (tree node)

-- (rtPath tree root x y) is the path from x to y
rtPath :: RTree -> Int -> Int -> Int -> [Int]
rtPath tree root x y = combine root (pathRoot x) (pathRoot y)
  where
    pathRoot x = sub x []
      where sub x xs | x == root = xs
                     | otherwise = sub (rtParent tree x) (x:xs)
    combine c (x:xs) (y:ys) | x == y = combine x xs ys
    combine c xs ys = reverse xs ++ (c : ys)


