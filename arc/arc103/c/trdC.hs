import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST

solve n vs = n - (getUsable $ map feat $ divide vs)

divide [] = [[], []]
divide [e] = [[e], []]
divide (e:o:xs) = [e:es, o:os]
  where [es, os] = divide xs

feat xs = runST $ do
  v <- VUM.replicate (10^5 + 1) 0
  (k, n, _, n') <- foldM (f v) (0, 0, 0, 0) xs
  return (k, n, n')
  where
    f v (k, n, k', n') x = do
      VUM.modify v (+ 1) x
      retVal <$> VUM.read v x
        where retVal w | w <= n'   = (k, n, k', n')
                       | w <= n    = (k, n, x , w )
                       | x == k    = (x, w, k', n')
                       | otherwise = (x, w, k , n )

getUsable [(kA, fA, sA), (kB, fB, sB)]
  | kA /= kB  = fA + fB
  | otherwise = max (fA + sB) (fB + sA)

bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  n:vs <- bsReadInts <$> B.getContents
  putStrLn $ show $ solve n vs
