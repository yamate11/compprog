{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}

import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST

func1 :: Int -> Int
func1 n = runST $ do
  vec <- VUM.replicate (n+1) (-1)
  let myFib = xFib (memo xFib vec)
  myFib n

xFib mf 0 = return 1
xFib mf 1 = return 1
xFib mf n = do
  y <- mf (n-1)
  z <- mf (n-2)
  return (y+z)

memo func vec n = do
  x <- VUM.read vec n
  if x >= 0 then return x
    else do
      y <- func (memo xFib vec) n
      VUM.write vec n y
      return y

func2 :: Int -> Int
func2 n = runST $ do
  vec <- VUM.replicate (n+1) (-1)
  run vec where
    run vec = myFib2 n where
      myFib2 0 = return 1
      myFib2 1 = return 1
      myFib2 n = do
        x <- VUM.read vec n
        if (x >= 0) then return x
          else do
          y <- myFib2 (n-1)
          z <- myFib2 (n-2)
          VUM.write vec n (y+z)
          return (y+z)
      
func3 :: Int -> Int
func3 n = runST $ do
  vec <- VUM.replicate (n+1) (-1)
  run vec where
    run vec = myFib3 n where
      myFib3 = memoize doMyFib3 vec id id id
      doMyFib3 0 = return 1
      doMyFib3 1 = return 1
      doMyFib3 n = do
        y <- myFib3 (n-1)
        z <- myFib3 (n-2)
        return (y+z)

main = do
  putStrLn (show (func3 1000000))

mem_undef :: (Ord vt, Num vt) => vt -> Bool
mem_undef = (< 0)

memoize :: (VUM.Unbox vt, Num vt, Ord vt) =>
           (a -> ST s b) -> (VUM.MVector s vt) ->
           (a -> Int) -> (b -> vt) -> (vt -> b) ->
           (a -> ST s b)
memoize f v encA encB decB x = do
  let idx = encA x
  z <- VUM.read v idx
  if not (mem_undef z) then return (decB z) else do
    w <- f x
    VUM.write v idx (encB w)
    return w
