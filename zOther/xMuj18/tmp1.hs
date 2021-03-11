import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.ST
import Debug.Trace

-- (all_different_v n xs) is True if all elements of list xs,
-- whose values are in [0..n-1], are different, False otherwise.
all_different_v :: Int -> [Int] -> Bool
all_different_v n xs = runST $ VUM.replicate n False >>= act xs

act :: [Int] -> VUM.MVector s Bool -> ST s Bool
act xs seen_v
  | trace ("act " ++ show xs) False = undefined
-- The x-th element of Boolean vector seen_v is True if x has already 
-- appeared in xs.
act []     seen_v = return True
act (x:xs) seen_v = foo seen_v >> VUM.read seen_v x >>= act1 xs seen_v
  where act1 xs seen_v True = return False
        act1 xs seen_v False = do
          VUM.write seen_v x True
          act xs seen_v

foo :: VUM.MVector s Bool -> ST s ()
foo seen_v = do
  bs <- mapM (VUM.read seen_v) [0..((VUM.length seen_v)-1)]
  b0 <- VUM.read seen_v (trace ("seen_v " ++ show bs) 0)
  return ()

all_different_l :: Int -> [Int] -> Bool
all_different_l n xs = sub xs (take n (repeat False))

sub :: [Int] -> [Bool] -> Bool
sub xs seen_l
  | trace ("sub " ++ show xs ++ " " ++ show seen_l) False = undefined
sub []     seen_l = True
sub (x:xs) seen_l | seen_l !! x = False
                  | otherwise = sub xs (pre ++ (True : (tail post)))
  where (pre, post) = splitAt x seen_l
        
