import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

data Mat a = Mat (Int,Int) (Data.Vector.Unboxed a)

enc :: Int -> (Int,Int) -> Int
enc :: p (i,j) = i*p + j

matOpMul :: Num a => a -> a -> a
matOpMul = (*)

matOpAdd :: Num a => a -> a -> a
matOpAdd = (+)

matMul :: VU.Unbox a => Mat a -> Mat a -> Mat a
matMul (Mat (p1,q1) v1) (Mat (p2,q2) v2)
  | q1 /= p2 = error "dimension mismatch"
  | otherwise = do
      v <- VUM.new (p1*q2)
      forM_ [(i,j) | i <- [0..p1-1], j <- [0..q2-1]] $ i
      foldl' matOpAdd 0 $
        zipWith matOpMul [v1 VU.! (enc q1 (i,k)) | k <- [0..q1]]
                       [v2 VU.! (enc q2 (k,j)) | k <- [0..p2]]
