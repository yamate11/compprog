import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Data.Bits

lsbAdd :: Int -> Int
lsbAdd k = k + (k .&. (-k))

lsbOff :: Int -> Int
lsbOff k = k .&. complement (k .&. (-k))

bitSum :: VM.MVector s Int -> Int -> ST s Int
bitSum vec n = 
  foldM g 0 $ takeWhile (> 0) $ iterate lsbOff n
  where g sum i = (+ sum) <$> (VM.read vec i)

bitUpd :: Int -> VM.MVector s Int -> Int -> Int -> ST s ()
bitUpd nMax vec n diff =
  forM_ (takeWhile (< nMax) (iterate lsbAdd n)) (VM.modify vec (+ diff))
