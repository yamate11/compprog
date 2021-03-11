{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE AllowAmbiguousTypes #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.Primitive
import Control.Monad.ST
import Control.Monad

type VUM2Vec m a = (VUM.MVector (PrimState m) a, Int)
type VU2Vec a = (VU.Vector a, Int)

vum2new :: (PrimMonad m, VUM.Unbox a) => (Int,Int) -> m (VUM2Vec m a)
vum2new (p,q) = do
  arr <- VUM.new (p*q)
  return (arr, p)

vum2replicate :: (PrimMonad m, VUM.Unbox a)
              => (Int,Int) -> a -> m (VUM2Vec m a)
vum2replicate (p,q) a = do
  arr <- VUM.replicate (p*q) a
  return (arr, p)

vum2read :: (PrimMonad m, VUM.Unbox a)
         => VUM2Vec m a -> (Int,Int) -> m a
vum2read (arr,p) (x,y) = VUM.read arr (x+p*y)

vum2write :: (PrimMonad m, VUM.Unbox a)
          => VUM2Vec m a -> (Int,Int) -> a -> m ()
vum2write (arr,p) (x,y) a = VUM.write arr (x+p*y) a

vu2create :: forall a. VU.Unbox a
          => (forall s. ST s (VUM2Vec (ST s) a)) -> VU2Vec a
vu2create act = runST $ do
  (marr,p) <- act
  arr <- VU.unsafeFreeze marr
  return (arr, p)

vu2lookup :: VU.Unbox a => VU2Vec a -> (Int,Int) -> a
vu2lookup (arr,p) (x,y) = arr VU.! (x+p*y)

-- -------------------------------------------------------------

(vYet, vCur, vEnd, vLoop) = (-1, 0, 1, 2)

solve :: Int -> Int -> Int
solve m n = length [(x,y) | x <- [1..m], y <- [1..n],
                            vu2lookup arr2 (x,y) == vLoop]
  where
    arr2 = vu2create (action m n)

action :: Int -> Int -> (forall s. ST s (VUM2Vec (ST s) Int))
action m n = do
  arr2 <- vum2replicate (1000,1000) vYet
  forM_ [0..999] $ \x -> vum2write arr2 (x,0) vEnd
  forM_ [0..999] $ \y -> vum2write arr2 (0,y) vEnd
  forM_ [(x,y) | x <- [1..m], y <- [1..n]] $ \(x,y) -> subact arr2 (x,y)
  return arr2
  where
    subact arr2 (x,y) = do
      v <- vum2read arr2 (x,y)
      if v /= vYet then return v else do
        vum2write arr2 (x,y) vCur
        v' <- subact arr2 (nextXY (x,y))
        let newV = dec v'
        vum2write arr2 (x,y) newV
        return newV

nextXY = (\(x,y) -> (x-y,y)) . psort . (\(x,y) -> (x,rev y)) . psort

psort (x,y) = if x >= y then (x,y) else (y,x)

rev x = rev' 0 x
  where rev' acc 0 = acc
        rev' acc x = rev' (10*acc + q) p
          where (p,q) = divMod x 10

dec v | v == vEnd  = vEnd
      | v == vCur  = vLoop
      | v == vLoop = vLoop


main = do
  cont <- getContents
  let [m, n] = map read (words cont)
  putStrLn $ show $ solve m n

test1 = solve 13 13 == 1
test2 = solve 20 30 == 28
test3 = solve 314 159 == 1915

