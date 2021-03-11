import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad

type Cand = (Int, Int) -- (start, skip)
-- a candidate set is either empty (skip == 0)
-- or singleton (skip == n)
-- or { start + i * skip | i = 0, 1, ..., i0 } where skip|n

type VChar = VU.Vector Char
type Ring = [Int]

icmp :: Int -> Int -> Int -> Int
icmp n x y = ((y + n) `mod` n) * n + ((x + n) `mod` n)

idiv :: Int -> Int -> (Int, Int)
idiv n i = (i `mod` n, i `div` n)

solve :: Int -> [String] -> Int
solve n css =
  if skip == 0 then 0 else n * (n `div` skip)
  where
    vc = buildV n css
    (_, skip) = foldr (nextCand n vc) (0,1) allRings
    allRings = map (mkRing n) [0..n-1]

mkRing :: Int -> Int -> Ring
mkRing n i = map (\k -> icmp n (0+k) (i-k)) [0..n-1]

nextCand :: Int -> VChar -> Ring -> Cand -> Cand
nextCand n vc ring cand@(start,skip)
  | skip == 0 = (0,0)
  | otherwise = nextCand1 n vc ring cand

nextCand1 :: Int -> VChar -> Ring -> Cand -> Cand
nextCand1 n vc ring (start,skip) =
  case allGoods of []         -> (0,0)
                   [k]        -> (k,n)
                   (k0:k1:_)  -> (k0,k1-k0)
  where allGoods = [fk p | p <- [0 .. n`div`skip - 1], good n vc ring (fk p)]
          where fk p = start + skip * p

good :: Int -> VChar -> Ring -> Int -> Bool
good n vc ring k = flip all ring $ \i ->
  let (x, y) = idiv n i
      j      = icmp n (y+k) (x-k)
  in vc VU.! i == vc VU.! j

buildV :: Int -> [String] -> VChar
buildV n css =
  VU.create $ do
  v <- VUM.new (n*n)
  forM (zip [0..] (concat css)) $ \(i, c) -> do
    VUM.write v i c
  return v

main = do
  conts <- getContents
  let sn : css = lines conts
      n = read sn
  putStrLn $ show $ solve n css

