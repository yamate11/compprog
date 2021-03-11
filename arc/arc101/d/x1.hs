import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Data.List

n :: Int
n = 100000
as :: [Int]
as = [(i*i) `mod` 10000 | i <- [1..n]]
vec_a = VU.fromList as

mmsort1 :: VU.Vector Int -> Int -> Int -> [Int]
mmsort1 _ _ 0 = []
mmsort1 v i 1 = [v VU.! i]
mmsort1 v i m = 
  let k1 = m `div` 2
      bs' = mmsort1 v i k1
      cs' = mmsort1 v k1 (m-k1)
  in msort1 k1 bs' (m-k1) cs'

msort1 :: Int -> [Int] -> Int -> [Int] -> [Int]
msort1 0 [] k bs = bs
msort1 k as 0 [] = as
msort1 ka (a:as) kb (b:bs)
  | a <= b    = a : msort1 (ka-1) as kb (b:bs)
  | otherwise = b : msort1 ka (a:as) (kb-1) bs

vsort1 :: VU.Vector Int -> Int -> Int -> VU.Vector Int
vsort1 _ _ 0 = VU.fromList []
vsort1 v i 1 = VU.fromList [v VU.! i]
vsort1 v i m =
  let k1 = m `div` 2
      v1 = vsort1 v i k1
      v2 = vsort1 v k1 (m-k1)
  in vmerge1 k1 v1 (m-k1) v2

vmerge1 :: Int -> VU.Vector Int -> Int -> VU.Vector Int -> VU.Vector Int
vmerge1 n1 v1 n2 v2 = VU.unfoldrN (n1+n2) f (0,0)
  where
    f :: (Int,Int) -> Maybe (Int, (Int,Int))
    f (i1,i2)
      | i1 == n1 && i2 == n2 = Nothing
      | i1 == n1 = c2
      | i2 == n2 = c1
      | a1 <= a2 = c1
      | otherwise = c2
      where c1 = Just (a1, (i1+1,i2))
            c2 = Just (a2, (i1,i2+1))
            a1 = v1 VU.! i1
            a2 = v2 VU.! i2

vmerge1' :: Int -> VU.Vector Int -> Int -> VU.Vector Int -> VU.Vector Int
vmerge1' n1 v1 n2 v2 = VU.create $ do
  v_res <- VUM.new (n1+n2)
  sub v_res 0 0
  return v_res
  where
    sub v_res i1 i2
      | i1 == n1 && i2 == n2 = return ()
      | i1 == n1 = go2
      | i2 == n2 = go1
      | a1 <= a2 = go1
      | otherwise = go2
      where
        go1 = go (v1 VU.! i1) (i1+1) i2
        go2 = go (v2 VU.! i2) i1 (i2+1)
        a1 = v1 VU.! i1
        a2 = v2 VU.! i2
        go a i1' i2'= do
          VUM.write v_res (i1+i2) a
          sub v_res i1' i2'

main = do
  -- let s = VU.sum (VU.fromList (sort as))
  -- let s = VU.sum (VU.fromList as)
  let s = VU.sum $ vsort1 vec_a 0 n
  -- let s = VU.sum vec_a
  putStrLn $ show $ s
  
