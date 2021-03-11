import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

{-
  Vector for two dimension data
-}

{-
  addIdx: adds 2-dim index to data

  e.g. addIdx 2 3 [4,5] [9,8,7] "abcdef"
       = [(4,9,'a'),(4,8,'b'),(4,7,'c'),(5,9,'d'),(5,8,'e'),(5,7,'f')
-}
addIdx :: Int -> Int -> [Int] -> [Int] -> [a] -> [(Int,Int,a)]
addIdx m1 m2 idxs1 idxs2 =
  zip3 (concat $ map (take m2 . repeat) idxs1)
       (concat $ take m1 $ repeat idxs2)

{-
  createUpd: creates vector by specifying update operation
-}
createUpd :: (Int -> Int -> Int) -> Int -> [(Int,Int)] -> VU.Vector Int
createUpd upd size pvs = VU.create $ do
  -- upd value old_value == new_value
  -- pvs ... pair of (encoded_index, value)
  vec <- VUM.replicate size 0
  forM_ pvs $ \(p,v) -> VUM.modify vec (upd v) p
  return vec

{- Use Case: counting vector members
  let vec = createUpd (+) size (map (\x -> (encode x, 1)))
  in vec VU.! (encode x)  ... this is the count for x
-}
{- Use Case: adding vector members
  let vec = createUpd (+) size (map (\(x, val) -> (encode x, val)))
  in vec VU.! (encode x)  ... this is the sum of vals for x
-}

