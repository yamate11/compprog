import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM

rootedTree :: [(Int,Int)] -> Int -> Int -> V.Vector [Int]
rootedTree xys root maxIdxPlusOne =
  V.create (VM.replicate maxIdxPlusOne [] >>= vecAct)
  where
  vecAct vec = do
    forM_ xys $ \(x,y) -> do
      VM.modify vec (x:) y
      VM.modify vec (y:) x
    VM.read vec >>= mapM_ (removeParent root)
    return vec
    where
    removeParent parent idx = do
      cs <- filter (/= parent) <$> VM.read vec idx
      VM.write vec idx cs
      mapM_ (removeParent vec idx) cs
  

