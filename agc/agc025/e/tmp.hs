import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Primitive
import Data.List


ite c t e = if c then t else e

act3 :: ST s Int
act3 = do
  ite (1 == 0) ( do
      x <- return 4
      return x
    ) ( do
      y <- return 10
      return y
    )


action1 :: ST s Int
action1 = do
  vec1 <- VUM.replicate 100 0
  vec2 <- VUM.replicate 100 1
  vec3 <- VUM.replicate 1000 0

  act2 vec1 vec2 vec3

  x <- VUM.read vec1 0
  y <- VUM.read vec2 0
  z <- VUM.read vec3 0
  return (x+y+z)

  where
    act2 v1 v2 v3 = do
      VUM.write v1 5 3
      act2 v1 v2 v3

actionA :: ST s Int
actionA = do
  vec1 <- VUM.replicate 100 0
  vec2 <- VUM.replicate 100 1
  vec3 <- VUM.replicate 1000 0

  actionB vec1 vec2 vec3

actionB v1 v2 v3 = do

  act2

  x <- VUM.read v1 0
  y <- VUM.read v2 0
  z <- VUM.read v3 0
  return (x+y+z)

  where
    act2 = do
      VUM.write v1 5 3
      act2 
