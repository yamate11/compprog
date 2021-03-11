import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import System.Environment
import Data.List
import Data.Bits

foo :: Int -> Int
foo n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    forM_ (powerset k) $ \i -> do
      x <- VUM.read vec i
      y <- VUM.read vec (i `xor` k)
      VUM.modify vec (max (x+y)) k
  VUM.read vec n

fooZ :: Int -> Int
fooZ n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    forM_ [0..k] $ \i -> do
      x <- VUM.read vec i
      y <- VUM.read vec (i `xor` k)
      VUM.modify vec (max (x+y)) k
  VUM.read vec n

fooY :: Int -> Int
fooY n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    forM_ (range k) $ \i -> do
      x <- VUM.read vec i
      y <- VUM.read vec (i `xor` k)
      VUM.modify vec (max (x+y)) k
  VUM.read vec n

fooX :: Int -> Int
fooX n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    forM_ [k,k-1..0] $ \i -> do
      x <- VUM.read vec i
      y <- VUM.read vec (i `xor` k)
      VUM.modify vec (max (x+y)) k
  VUM.read vec n

bar :: Int -> Int
bar n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    let act2 i = do
          x <- VUM.read vec i
          y <- VUM.read vec (i `xor` k)
          VUM.modify vec (max (x+y)) k
          unless (i == 0) (act2 (k .&. (i-1)))
    act2 k
  VUM.read vec n

barZ :: Int -> Int
barZ n = runST $ do
  let nps = 2 ^ n
  vec <- VUM.replicate (nps+1) 1
  forM_ [0..nps-1] $ \k -> do
    let act2 i = do
          x <- VUM.read vec i
          y <- VUM.read vec (i `xor` k)
          VUM.modify vec (max (x+y)) k
          unless (i == 0) (act2 (i-1))
    act2 k
  VUM.read vec n



range :: Int -> [Int]
range n = unfoldr f (n+1)
  where f 0 = Nothing
        f x = let t = x-1 in Just (t, t)

powerset :: (Bits a, Num a) => a -> [a]
powerset a = a : unfoldr f a
  where f 0 = Nothing
        f x = let t = a .&. (x-1) in Just (t, t)

main = do
  [tps, ns] <- getArgs
  let n = read ns
      tp = (read tps) :: Int
  when (tp == 1) (putStrLn $ show $ foo n)
  when (tp == 2) (putStrLn $ show $ bar n)
  when (tp == 3) (putStrLn $ show $ fooZ n)
  when (tp == 4) (putStrLn $ show $ barZ n)
  when (tp == 5) (putStrLn $ show $ fooY n)
  when (tp == 6) (putStrLn $ show $ fooX n)
  
  
