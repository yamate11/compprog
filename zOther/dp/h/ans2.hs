{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

prime :: Int
prime = 10 ^ 9 + 7

solve :: Int -> Int -> [String] -> Int
solve h w ass = theFunc (1,1)
  where
  enc (i,j) = (i-1) * w + (j-1)

  vA = VU.fromListN (h*w) (concat ass)

  theDistr = distr (h*w) enc 0 [((h,w), 1)] df targets order
  df _ _ x y | z < prime = z
             | otherwise = z - prime
    where z = x+y
  targets (i,j) = catMaybes [sub (i-1,j), sub (i,j-1)]
    where sub (i,j) | i < 1 = Nothing
                    | j < 1 = Nothing
                    | vA VU.! (enc (i,j)) == '#' = Nothing
                    | otherwise = Just (i,j)
  order = [(i,k-i) | k <- [h+w,h+w-1..2],
                     i <- [max 1 (k-w) .. min h (k-1)]]

  theFunc :: (Int, Int) -> Int
  theFunc = func_from_distr theDistr

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_h,bs_w]:remLines1 = remLines0
      h = readBInt bs_h
      w = readBInt bs_w
      ass = map (\[x] -> B.unpack x) remLines1
  in solve h w ass

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

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

inp1 = "3 4\n...#\n.#..\n....\n"
inp2 = "5 2\n..\n#.\n..\n.#\n..\n"
inp3 = "5 5\n..#..\n.....\n#...#\n.....\n..#..\n"
inp4 = "20 20\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n....................\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == 3
test2 = tv2 == 0
test3 = tv3 == 24
test4 = tv4 == 345263555
alltest = test1 && test2 && test3 && test4
