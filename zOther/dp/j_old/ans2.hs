{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

type T3Int = (Int,Int,Int)

solve :: Int -> [Int] -> Double
solve bN as = theFunc initSt
  where

  enc (x1,x2,x3) = x1 + x2 * (bN+1) + x3 * (bN+1)*(bN+1)
  dec z = (x1,x2,x3)
    where (z', x1) = divMod z (bN+1)
          (x3, x2) = divMod z' (bN+1)

  initSt = foldl' opIS (0,0,0) as

  opIS (!x1,!x2,!x3) 1 = (x1+1, x2, x3)
  opIS (!x1,!x2,!x3) 2 = (x1, x2+1, x3)
  opIS (!x1,!x2,!x3) 3 = (x1, x2, x3+1)

  theFunc = func_from_distr theDistr
  theDistr = distr (bN+1)*(bN+1)*(bN+1) enc 0 [] df target order

  target (x,y,z) = op1 ++ op2 ++ op3
    where op1 | x+y+z < bN = [(x+1,y,z)]
              | otherwise = []
          op2 | x > 0 = [(x-1,y+1,z)]
              | otherwise = []
          op3 | y > 0 = [(x,y-1,z+1)]
              | otherwise = []

    mf :: forall m. Monad m => (T3Int -> m Double) -> T3Int -> m Double
    mf rd (0,0,0) = return 0
    mf rd (x,y,z) = do
      ex <- getE (x-1) y     z
      ey <- getE (x+1) (y-1) z
      ez <- getE x     (y+1) (z-1)
      let idmul i d = (fromIntegral i) * d
          rem = fromIntegral (x + y + z)
          comp = (fromIntegral bN) - rem
          rv = (idmul x ex + idmul y ey + idmul z ez + comp) / rem
      -- trace ("mf " ++ show (x,y,z,rv)) (return ())
      return rv
      where
  
      getE :: Int -> Int -> Int -> m Double
      getE x y z | x >= 0 && y >= 0 && z >= 0 = (+ 1) <$> rd (x,y,z)
                 | otherwise                  = return 0

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Double
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_n]:remLines1 = remLines0
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
  in solve n as

outAnswer :: Double -> IO ()
outAnswer x = putStrLn (show x)

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

distr :: (VU.Unbox a, Show a, Show d) =>
         Int ->                        -- vector size
         (d -> Int) ->                 -- encoding function
         a ->                          -- init vals in vector
         [(d,a)] ->                    -- special init vals
         (d -> d -> a -> a -> a) ->    -- df (source, target, source value,
                                       --     target current value)
         (d -> [d]) ->                 -- targets from source
         [d] ->                        -- source order
         (VU.Vector a, d -> Int)       -- the vector and encoding func
distr vSize encode initg inits df target order = runST $ do
  vec <- VUM.replicate vSize initg
  forM_ inits $ \(d,a) -> VUM.write vec (encode d) a
  forM_ order $ \d -> do
    let x = encode d
    ax <- VUM.read vec x
    forM_ (target d) $ \t -> do
      let y = encode t
      VUM.modify vec (df d t ax) y
  vec' <- VU.unsafeFreeze vec
  return (vec', encode)

func_from_distr :: VU.Unbox a => (VU.Vector a, d->Int) -> d -> a
func_from_distr (vec, encode) d = vec VU.! (encode d)


{-
n = 30 :: Int
theDistr = distr (n+2) id 0 [(0,1)] df targets [0..n-1]
  where df _ _ = (+)
        targets i = [i+1,i+2]
fib :: Int -> Int
fib = func_from_distr theDistr
-}

-------------------------------------------------------------------------------

inp1 = "3\n1 1 1\n"
inp2 = "1\n3\n"
inp3 = "2\n1 2\n"
inp4 = "10\n1 3 2 3 3 2 3 2 1 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = near tv1 5.5
test2 = near tv2 3
test3 = near tv3 4.5
test4 = near tv4 54.48064457488221
alltest = test1 && test2 && test3 && test4
near x y = abs (x-y) < 10 ** (-9)
