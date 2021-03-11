{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Primitive
-- import Debug.Trace
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import Control.Monad
-- import Control.Monad.ST
import Debug.Trace

solve :: String -> String -> String
-- solve s t = getS (len_s, len_t) ""
solve s t = show $ theFunc (len_s, len_t)
  where

  vs = VU.fromList s
  vt = VU.fromList t
  len_s = VU.length vs
  len_t = VU.length vt

  enc :: (Int, Int) -> Int
  enc (is, it) = is * (len_t+1) + it

  dec = flip divMod (len_t+1)

  mf rd (0,_) = return 0
  mf rd (_,0) = return 0
  mf rd (p,q)
    | vs VU.! (p-1) == vt VU.! (q-1) = do
        y <- rd (p-1, q-1)
        return $ y+1
    | otherwise = do
        y1 <- rd (p-1, q)
        y2 <- rd (p, q-1)
        if y1 > y2 then return y1 else return y2

  theMemo = memovec enc dec mf [(len_s, len_t)]

  theFunc :: (Int,Int) -> Int
  theFunc = func_from_memo theMemo

{-
  getRevS (0, _) = ""
  getRevS (_, 0) = ""
  getRevS (p, q)
    | cs == ct = cs : getRevS (p-1, q-1)
    | theFunc (p, q) == theFunc (p-1, q) = getRevS (p-1, q)
    | otherwise = getRevS (p, q-1)
    where cs = vs VU.! (p-1)
          ct = vt VU.! (q-1)
-}
  getS (0, _) acc = acc
  getS (_, 0) acc = acc
  getS (p, q) acc
    | cs == ct = getS (p-1, q-1) (cs:acc)
    | theFunc (p, q) == theFunc (p, q-1) = getS (p, q-1) acc
    | otherwise = getS (p-1, q) acc
    where cs = vs VU.! (p-1)
          ct = vt VU.! (q-1)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_s]:remLines1 = remLines0
      s = B.unpack bs_s
      [bs_t]:remLines2 = remLines1
      t = B.unpack bs_t
  in solve s t

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1 = "axyb\nabyxb\n"
inp2 = "aa\nxayaz\n"
inp3 = "a\nz\n"
inp4 = "abracadabra\navadakedavra\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1 = tv1 == "axb" || tv1 == "ayb"
test2 = tv2 == "aa"
test3 = tv3 == ""
test4 = tv4 == "aaadara"
alltest = test1 && test2 && test3 && test4

----------------------------------------------------------------------

memovec :: forall a d. (Show a, Show d) =>
           (d -> Int) -> (Int -> d) ->
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> (V.Vector a, VU.Vector Bool, d -> Int)
memovec encode decode mf ds = (vecV, vecF, encode)
  where
    (vecV, vecF) = mv_enc mf' (map encode ds)

    mf' :: Monad m => (Int -> m a) -> Int -> m a
    mf' f' i = mf (f' . encode) (decode i)

    mv_enc :: (forall m. Monad m => (Int -> m a) -> Int -> m a)
           -> [Int] -> (V.Vector a, VU.Vector Bool)
    mv_enc mf xs = runST $ do
      let size = (maximum xs + 1)
      v      <- VM.new size
      flags  <- VUM.replicate size False
      forM_ xs $ \x -> calc v flags x
      v'     <- V.unsafeFreeze v
      flags' <- VU.unsafeFreeze flags
      return (v', flags')

      where

        calc :: forall s. VM.MVector s a -> VUM.MVector s Bool -> Int -> ST s a
        calc v flags x = VUM.read flags x >>= ite231 (VM.read v x) else_e
          where
            else_e = do
              val <- mf (calc v flags) x
              VM.write v x val
              VUM.write flags x True
              return val

func_from_memo :: (V.Vector a, VU.Vector Bool, d->Int) -> d -> a
func_from_memo (vecV, vecF, enc) d
  | vecF VU.! x = vecV V.! x
  | otherwise   = undefined
  where x = enc d

ite231 :: a -> a -> Bool -> a
ite231 then_part else_part cond = if cond then then_part else else_part
