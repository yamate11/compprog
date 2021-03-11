import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM
import Data.List

solve :: Int -> [Int] -> Int
solve n vs 
  | ok1 /= ek1            = (m - on1) + (m - en1)
  | on1 + en2 < on2 + en1 = (m - on2) + (m - en1)
  | otherwise             = (m - on1) + (m - en2)
  
  where
    m = n `div` 2

    divide [] = ([], [])
    divide (o:e:vs) = let (os, es) = divide vs in (o:os, e:es)

    (os0, es0) = divide vs

    getTwo xs = case sortOn ((* (-1)) . snd) $ IM.toList $ count xs of
      [(k1, n1)] -> (k1, n1, 0, 0)
      (k1, n1) : (k2, n2) : _ -> (k1, n1, k2, n2)

    (ok1, on1, ok2, on2) = getTwo os0
    (ek1, en1, ek2, en2) = getTwo es0


    

count xs = foldr f IM.empty xs
  where f x im = case IM.lookup x im of
          Nothing -> IM.insert x 1 im
          Just t -> IM.adjust (+ 1) x im


bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main = do
  conts <- B.getContents
  let n:vs = bsReadInts conts
  putStrLn $ show $ solve n vs
