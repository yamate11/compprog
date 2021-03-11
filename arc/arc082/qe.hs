import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe
import qualified Data.Map as M
import qualified Data.Vector.Unboxed as V

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

valM = 998244353
primes = [2, 3, 5, 7, 11, 13]

prFact :: Int -> [Int]
prFact n = map fst $ tail $ scanl (\(_, y) p -> divppow p y) (1,n) primes 

divppow :: Int -> Int -> (Int, Int)
divppow p y = f p 0 y
  where
    f p acc y | y `mod` p == 0 = f p (acc + 1) (y `div` p)
              | otherwise      = (acc, y)

modAdd  x y = (x + y) `mod` valM
modMult x y = (x * y) `mod` valM

modFacted :: [Int] -> Int
modFacted pows = (foldl' modMult 1 $ zipWith modPow primes pows) `mod` valM

modPow :: Int -> Int -> Int
modPow p r = (iterate (modMult p) 1) !! r

combiSeq valN = scanr op [0,0,0,0,0,0] [4..valN]
  where op n pows = let powA = prFact n
                        powB = prFact (valN - n + 1)
                    in zipWith3 (\x a b -> x + a - b) pows powA powB

numPol valN = (sum $ map modFacted $ combiSeq valN) `mod` valM
              

type MyMap = M.Map (Int, Int) (Maybe Int)
type Vline = V.Vector (Int, Int)

solve :: Int -> [[Int]] -> Int
solve 1 _ = 0
solve 2 _ = 0
solve valN pts = (numPol valN - sumPenalties + valM) `mod` valM
  where
    vline :: Vline
    vline = V.fromList $ map (\[x,y] -> (x,y)) pts

    lmap :: MyMap
    lmap = foldr op M.empty [0 .. valN - 1]

    op :: Int -> MyMap -> MyMap
    op i lm = foldr op2 (foldr op1 lm zjk) zj
      where
        zj = [i+1 .. valN-1]
        zjk = [(j,k) | j <- [i+1 .. valN-1], k <- [j+1 .. valN-1]]

        op1 :: (Int,Int) -> MyMap -> MyMap
        op1 (j,k) lm =
          if onALine i j k
          then M.insert (i,k) Nothing
                 (M.insert (i,j) Nothing
                 (M.adjust (fmap (+ 1)) (j,k) lm))
          else lm

        op2 :: Int -> MyMap -> MyMap
        op2 j lm = M.alter (maybe (Just (Just 0)) Just) (i,j) lm

    onALine i j k = let (xi, yi) = vline V.! i
                        (xj, yj) = vline V.! j
                        (xk, yk) = vline V.! k
                        (x1, y1) = (xi - xk, yi - yk)
                        (x2, y2) = (xj - xk, yj - yk)
                    in x1 * y2 == x2 * y1

    sumPenalties = f 0 llist penalties'
      where llist@(n0 : _) = sort $ catMaybes $ map snd $ M.toList lmap
            penalties' = drop n0 penalties
            f acc ls@(n:_) ps@(p:_) =
              let (ls1, ls2) = span (== n) ls
                  nextAcc = acc + (length ls1) * p
              in case ls2 of
              []    -> nextAcc
              m : _ -> f nextAcc ls2 nextPs
                where nextPs = drop (m - n) ps

penalties :: [Int]
penalties = scanl modAdd 0 $ map penaltyEach [1..]

penaltyEach :: Int -> Int
penaltyEach n = (sum $ zipWith modMult [n, n-1 .. 1] p2s) `mod` valM
  where p2s = iterate (\x -> modMult 2 x) 1 





main :: IO ()
main = do
  conts <- B.getContents
  let [n] : iss = map bsReadInts (B.lines conts)
      answer = solve n iss
  putStrLn (show answer)
