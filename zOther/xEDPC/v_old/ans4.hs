{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int)] -> [Int]
solve bN bM xys = tail $ VU.toList ansVec
  where

  children = rootedTree xys 1 (bN+1)

  mAdd x y = let w = x + y in if w < bM then w else w - bM
  mMul x y = (x * y) `mod` bM
  mInv x = let (_, a, _) = eGCD x bM in if a < 0 then a + bM else a
  mPow x y = foldl' mMul 1 (zipWith f (unfoldr bin_f y) (binpow x))
    where
      f 0 _ = 1
      f 1 t = t
      bin_f 0 = Nothing
      bin_f y = let (yd, ym) = y `divMod` 2 in Just (ym, yd)
      binpow x = iterate (\t -> mMul t t) x


  efBM = map fst (prfac bM)
  lenEfBM = length efBM

  efFrom x | z == 0    = efZero
           | otherwise = mapAccumL mkDiv z efBM
    where z = x `mod` bM

  efZero = (1, map snd (prfac bM))

  efOne = efFrom 1
  
  efMul (t1,e1) (t2,e2) = (t1 `mMul` t2, zipWith (+) e1 e2)

  efVal (t,e) = foldl' mMul t (zipWith mPow efBM e)
  

  efIncr ef = efFrom (1 + efVal ef)

  efDiv ef1 ef2 = efMul ef1 (efInverse ef2)

  efInverse (t,e) = (mInv t, map (* (-1)) e)

  -- mf rc node | traceL "mf in" (node) False = undefined
  -- mf rc node = traceLM "mf out" (node,) (mfZ rc node)
  mf rc node
    | null (children node) = return efOne
    | otherwise = lzFold' efMul efOne [efIncr <$> rc x | x <- children node]

  theMemo = memovec id (bN+1) mf [1]
  theFunc = func_memo id theMemo

  ansVec = VU.create $ do
    vec <- VUM.new (bN+1)
    subAct vec 1 efOne
    return vec
    where
    -- subAct vec node ef | traceL "subAct In" (node,ef) False = undefined
    subAct vec node ef = do
      let thisEf = (theFunc node) `efMul` ef
      VUM.write vec node (efVal thisEf)
      forM_ (children node) $ \child -> 
        subAct vec child
               (efIncr (thisEf `efMul` efInverse (efIncr (theFunc child))))

mkDiv x p = sub 0 x
  where
    -- sub !acc x | traceL "mkDiv sub in" (acc,x,p) False = undefined
    sub !acc x | r == 0 = sub (acc+1) q
               | otherwise = (x, acc)
      where (q,r) = divMod x p

-------------------------------------------------------------------------------

eGCD :: Int -> Int -> (Int,Int,Int)
eGCD 0 b = (b, 0, 1)
eGCD a b = let (g, s, t) = eGCD (b `mod` a) a
           in (g, t - (b `div` a) * s, s)


lzFold' :: (Show b,Monad m) => (b -> a -> b) -> b -> [m a] -> m b
lzFold' op b0 = sub b0 where
  -- sub !acc mas | traceL "lzFold' sub in" acc False = undefined
  sub !acc [] = return acc
  sub !acc (ma:mas) = ma >>= (\a -> sub (op acc a) mas)

rootedTree :: [(Int,Int)] -> Int -> Int ->
              Int -> [Int]
rootedTree xys root maxIdxPlusOne i = v V.! i where
  v = V.create (VM.replicate maxIdxPlusOne [] >>= vecAct)
  vecAct vec = do
    forM_ xys $ \(x,y) -> do
      VM.modify vec (x:) y
      VM.modify vec (y:) x
    VM.read vec root >>= mapM_ (removeParent root)
    return vec
    where
    removeParent parent idx = do
      cs <- filter (/= parent) <$> VM.read vec idx
      VM.write vec idx cs
      mapM_ (removeParent idx) cs

memovec :: forall a d. (Show a, Show d) =>
           (d -> Int) -> Int -> 
           (forall m. Monad m => (d -> m a) -> d -> m a) ->
           [d] -> V.Vector a
memovec encode size mf ds = V.create $ do
  vec <- VM.new size
  flags <- VUM.replicate size False
  mapM_ (calc vec flags) ds
  return vec
  where
    calc vec flags d = do
      fv <- VUM.read flags (encode d)
      if fv then VM.read vec (encode d)
        else do
        val <- mf (calc vec flags) d
        VM.write vec   (encode d) val
        VUM.write flags (encode d) True
        return val

func_memo :: (d->Int) -> V.Vector a -> d -> a
func_memo encode vecV d = vecV V.! (encode d)

sieve :: [Int]
sieve = 2 : sieve_sub [2] [3..]

sieve_sub :: [Int] -> [Int] -> [Int]
sieve_sub (n:yet) cand =
  let
    (cnfmd, rem) = span (< n*n) cand
    newcand = filter (\i -> i `mod` n /= 0) rem
  in cnfmd ++ sieve_sub (yet ++ cnfmd) newcand

prfac :: Int -> [(Int,Int)]
prfac n = filter ((>= 1) . snd) $ unfoldr f (sieve, n)
  where
    f (_, 1) = Nothing
    f (p:ps, k) | p*p > k   = Just ((k, 1), ([], 1))
                | otherwise = Just ((p, pow), (ps, div k p_pow))
      where (pow, p_pow) = divmany k p
    divmany k p = sub 0 1 k
      where sub pow p_pow x | m == 0    = sub (pow+1) (p_pow*p) d
                            | otherwise = (pow, p_pow)
              where (d,m) = divMod x p

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> [Int]
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      xys = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN bM xys

outAnswer :: [Int] -> IO ()
outAnswer xs = putStr $ unlines $ map show xs

main :: IO ()
main = outAnswer . tmain =<< B.getContents

-------------------------------------------------------------------------------

inp1a = "3 97\n1 2\n2 3\n"
inp1 = "3 100\n1 2\n2 3\n"
inp2 = "4 100\n1 2\n1 3\n1 4\n"
inp3 = "1 100\n"
inp4 = "10 2\n8 5\n10 8\n6 5\n1 5\n4 8\n2 10\n3 6\n9 2\n1 7\n"
tv1a = tmain $ B.pack inp1a
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
test1a = tv1a == [3,4,3]
test1 = tv1 == [3,4,3]
test2 = tv2 == [8,5,5,5]
test3 = tv3 == [1]
test4 = tv4 == [0,0,1,1,1,0,1,0,1,1]
alltest = test1a && test1 && test2 && test3 && test4
