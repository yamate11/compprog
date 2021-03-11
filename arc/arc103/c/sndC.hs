import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM
import Data.List

solve n vs = n - (getUsable $ map feat $ divide vs)

divide [] = [[], []]
divide [e] = [[e], []]
divide (e:o:xs) = [e:es, o:os]
  where [es, os] = divide xs

feat xs = case sortOn (negate . snd) $ IM.toList $ count xs of
  [(k, n)]             -> (k, n, 0)
  (k, n) : (_, n') : _ -> (k, n, n')

count = foldr (flip (IM.insertWith (+)) 1) IM.empty

getUsable [(kA, fA, sA), (kB, fB, sB)]
  | kA /= kB  = fA + fB
  | otherwise = max (fA + sB) (fB + sA)

bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  n:vs <- bsReadInts <$> B.getContents
  putStrLn $ show $ solve n vs
