import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.ST
import Control.Monad

solve :: Int -> Int -> [[Int]] -> [[Int]] -> Int
solve num_n num_c dss css = ans
  where
    vec_c = createUpd (+) (3*num_c)
            $ map f
            $ addIdx num_n num_n [0..num_n-1] [0..num_n-1] (concat css)
      where f (i,j,c) = (enc_c ((i+j) `mod` 3, c), 1)

    enc_c (m,c) = m * num_c + (c-1)

    vec_d = createUpd (+) (num_n * num_n)
            $ map (\(i,j,v) -> (enc_d (i,j), v))
              $ addIdx num_c num_c [1..num_c] [1..num_c] (concat dss)

    enc_d (c1,c2) = num_c * (c1-1) + (c2-1)

    cand = [(c1,c2,c3) | c1 <- [1..num_c], c2 <- [1..num_c], c3 <- [1..num_c],
                         c1 /= c2, c1 /= c3, c2 /= c3]
                          
    ans = minimum $ map f cand
      where
        f (c1,c2,c3) = g 0 c1 + g 1 c2 + g 2 c3
        g m c = VU.map h [1..num_c]
          where h c' = vec_c VU.! (enc_c (m,c'))) * (vec_d enc_d (c',c))

addIdx :: Int -> Int -> [Int] -> [Int] -> [a] -> [(Int,Int,a)]
addIdx m1 m2 idxs1 idxs2 =
  zip3 (concat $ map (take m2 . repeat) idxs1)
       (concat $ take m1 $ repeat idxs2)
{-
 e.g. addIdx 2 3 [4,5] [9,8,7] "abcdef"
    = [(4,9,'a'),(4,8,'b'),(4,7,'c'),(5,9,'d'),(5,8,'e'),(5,7,'f')
-}

createUpd :: (Int -> Int -> Int) -> Int -> [(Int,Int)] -> VU.Vector Int
createUpd upd size pvs = VU.create $ do
  -- upd value old_value == new_value
  -- pvs ... pair of (encoded_index, value)
  vec <- VUM.replicate size 0
  forM_ pvs $ \(p,v) -> VUM.modify vec (upd v) p
  return vec

{-- counting vector
  let vec = createUpd (+) size (map (\x -> (encode x, 1)))
  in vec VU.! (encode x)  ... this is the count for x

-- summing vector
  let vec = createUpd (+) size (map (\(x, val) -> (encode x, val)))
  in vec VU.! (encode x)  ... this is the sum of vals for x
--}

