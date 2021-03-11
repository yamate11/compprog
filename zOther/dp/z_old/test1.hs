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
import Debug.Trace
-- trace _ = id

action = do
  queue <- queInit 100
  quePut queue (100::Int)
  quePut queue 50
  x <- quePeekT queue 0
  traceL "2" x (return ())
  x <- quePeekT queue 1
  traceL "4" x (return ())
  x <- queGetT queue
  traceL "1" x (return ())
  quePut queue 30
  x <- queGetB queue
  traceL "3" x (return ())
  x <- queGetB queue
  traceL "7" x (return ())

  

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



