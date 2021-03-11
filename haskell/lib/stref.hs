import Control.Monad
import Control.Monad.ST
import qualified Data.Vector.Unboxed.Mutable as VM
import Data.STRef

limit = 100

-- func xs calculates sublist of xs consisting of square numbers
func :: [Int] -> [Int]
func xs = runST (act xs)

-- You can use:
--     newSTRef
--     readSTRef
--     writeSTRef
--     modifySTRef
act :: [Int] -> ST s [Int]
act xs = do
  vec <- buildVec
  results <- newSTRef []
  forM_ xs $ \x ->
    if x < limit then do
      b <- VM.read vec x
      when b $ do
        xs <- readSTRef results 
        writeSTRef results (x:xs)
        -- or equivalently, modifySTRef results (x:)
    else return ()
  xs <- readSTRef results
  return (reverse xs)

-- judging square numbers
buildVec :: ST s (VM.MVector s Bool)
buildVec = do
  vec <- VM.replicate (limit*limit) False
  forM_ [0 .. limit-1] $ \i -> VM.write vec (i*i) True
  return vec
  
