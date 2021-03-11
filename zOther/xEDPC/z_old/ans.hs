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
import Data.STRef
-- import Debug.Trace
trace _ = id

solve :: Int -> Int -> [Int] -> Int
solve bN bC hs = results VU.! 1
  where

  vecH = VU.fromListN (bN+1) (0:hs)

  results = VU.create $ do
    val <- VUM.new (bN+1)
    lines <- queInit bN
    act val lines
    where
    act val lines = act' where
      act' = do
        forM_ [bN, bN-1 .. 1] $ \i -> do
          let hi = vecH VU.! i
          vi <- calcValue i hi
          VUM.write val i vi
          traceL "val" (i,vi) (return ())
          addLine i ((-2) * hi, hi*hi + vi)
        return val

      calcValue i hi | i == bN   = return 0
                     | otherwise = (+ (hi*hi + bC)) <$> query hi
        
      query hi = do
        len <- queLength lines
        (a,b) <- quePeekT lines 0
        sub len (a * hi + b)
        where
        sub 1 v = return v
        sub len v = do
          -- traceL "getEffLine len" len (return ())
          (a',b') <- quePeekT lines 1
          let v' = a' * hi + b'
          if v <= v' then return v else do
            queGetT lines
            sub (len-1) v'
            
      addLine i (a,b) = do
        traceL "inserting ..." i (return ())
        removeInEff (a,b)
        quePut lines (a,b)
        len <- queLength lines
        traceL "current length is " len (return ())

      removeInEff (a,b) = queLength lines >>= sub where
        sub 0 = return ()
        sub 1 = return ()
        sub len = do
          -- traceL "removeInEff len" len (return ())
          (a1,b1) <- quePeekB lines 0
          (a2,b2) <- quePeekB lines 1
          if checkEff (a2,b2) (a1,b1) (a,b) then return() else do
            queGetB lines
            sub (len-1)
        
checkEff :: (Int,Int) -> (Int,Int) -> (Int,Int) -> Bool
checkEff (a2,b2) (a1,b1) (a0,b0) =
  let adiff10 = fromIntegral (a1 - a0) :: Integer
      adiff21 = fromIntegral (a2 - a1) :: Integer
      bdiff10 = fromIntegral (b1 - b0) :: Integer
      bdiff21 = fromIntegral (b2 - b1) :: Integer
  in adiff10 * bdiff21 < adiff21 * bdiff10

----------------------------------------------------------------------

data Queue s a = Queue {
  queVec :: VUM.MVector s a,
  queSize :: Int,
  queTop :: STRef s Int,
  queBot :: STRef s Int
}

actionWithValue :: ST s a -> (a -> ST s b) -> ST s a
{-# INLINE actionWithValue #-}
actionWithValue act1 act2 = do
  a <- act1
  act2 a
  return a

modSTRef :: STRef s a -> (a -> a) -> ST s a
{-# INLINE modSTRef #-}
modSTRef ref f = actionWithValue (readSTRef ref) (writeSTRef ref . f)

queInit :: VUM.Unbox a => Int -> ST s (Queue s a)
{-# INLINE queInit #-}
queInit n = do
  vec <- VUM.new n
  qt <- newSTRef 0
  qb <- newSTRef 0
  return $ Queue { queVec = vec, queSize = n, queTop = qt, queBot = qb }

quePut :: (VUM.Unbox a) => Queue s a -> a -> ST s ()
{-# INLINE quePut #-}
quePut q a = modSTRef (queBot q) (+ 1) >>= flip (VUM.write (queVec q)) a

queGetT :: (VUM.Unbox a) => Queue s a -> ST s a
{-# INLINE queGetT #-}
queGetT q = modSTRef (queTop q) (+ 1) >>= VUM.read (queVec q)

queGetB :: (VUM.Unbox a) => Queue s a -> ST s a
{-# INLINE queGetB #-}
queGetB q = modSTRef (queBot q) (+ (-1)) >>= VUM.read (queVec q) . (+ (-1))
quePeekT :: (VUM.Unbox a) => Queue s a -> Int -> ST s a
{-# INLINE quePeekT #-}
quePeekT q i = readSTRef (queTop q) >>= VUM.read (queVec q) . (+ i)

quePeekB :: (VUM.Unbox a) => Queue s a -> Int -> ST s a
{-# INLINE quePeekB #-}
quePeekB q i = readSTRef (queBot q) >>= VUM.read (queVec q) . (+ (-i-1))

queLength :: Queue s a -> ST s Int
{-# INLINE queLength #-}
queLength q = (-) <$> readSTRef (queBot q) <*> readSTRef (queTop q)
  

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bC]:remLines1 = remLines0
      bN = readBInt bs_bN
      bC = readBInt bs_bC
      line2:remLines2 = remLines1
      hs = map readBInt line2
  in solve bN bC hs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "5 6\n1 2 3 4 5\n"
inp2 = "2 1000000000000\n500000 1000000\n"
inp3 = "8 5\n1 3 4 5 10 11 12 13\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == 20
test2 = tv2 == 1250000000000
test3 = tv3 == 62
alltest = test1 && test2 && test3

