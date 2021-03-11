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

prime :: Int
prime = 10 ^ 9 + 7

solve :: Int -> Int -> [String] -> Int
solve h w ass = theFunc (1,1)
  where
  vA = VU.fromListN (h*w) (concat ass)

  enc (i,j) = (i-1) * w + (j-1)
  dec z = (p+1, q+1)
    where (p,q) = divMod z w

  theFunc = func_from_memo $ memovec enc dec mf [(h,w),(1,1)]

  mf rd (i,j)
    | i == h && j == w = return 1
    | otherwise = f <$> (sub (i+1) j) <*> (sub i (j+1))
    where
    f x1 x2 = (sum [x1, x2]) `mod` prime
    sub i j | i > h                      = return 0
            | j > w                      = return 0
            | vA VU.! (enc (i,j)) == '#' = return 0
            | otherwise                  = rd (i,j)

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


memovec :: forall a d. (VU.Unbox a, Show a, Show d) =>
           (d -> Int) -> (Int -> d) ->
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> (VU.Vector a, VU.Vector Bool, d -> Int)
memovec encode decode mf ds = (vecV, vecF, encode)
  where
    (vecV, vecF) = mv_enc mf' (map encode ds)

    mf' f' i = mf (f' . encode) (decode i)

    mv_enc :: (forall m. Monad m => (Int -> m a) -> Int -> m a)
           -> [Int] -> (VU.Vector a, VU.Vector Bool)
    mv_enc mf xs = runST $ do
      let size = (maximum xs + 1)
      v      <- VUM.new size
      flags  <- VUM.replicate size False
      forM_ xs $ \x -> calc v flags x
      v'     <- VU.unsafeFreeze v
      flags' <- VU.unsafeFreeze flags
      return (v', flags')

      where

        calc :: forall s. VUM.MVector s a -> VUM.MVector s Bool
                          -> Int -> ST s a
        calc v flags x = VUM.read flags x >>= ite231 (VUM.read v x) else_e
          where
            else_e = do
              val <- mf (calc v flags) x
              VUM.write v x val
              VUM.write flags x True
              return val

func_from_memo :: VU.Unbox a =>
                  (VU.Vector a, VU.Vector Bool, d->Int) -> d -> a
func_from_memo (vecV, vecF, enc) d
  | vecF VU.! x = vecV VU.! x
  | otherwise   = undefined
  where x = enc d

ite231 :: a -> a -> Bool -> a
ite231 then_part else_part cond = if cond then then_part else else_part

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
