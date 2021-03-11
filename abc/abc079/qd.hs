import qualified Data.Map.Strict as M
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Debug.Trace

qTrace :: (Show a) => String -> a -> a
-- qTrace lab a = trace (lab ++ ": " ++ show a) a
qTrace _ a = a

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

type CMap = M.Map (Int, Int) Int

setMat :: [[Int]] -> CMap
setMat css =
  M.fromList $ concat (zipWith g [0..9] (map f css))
  where f cs = zip [0..9] cs
        g j zz = map (\(i, v) -> ((j, i), v)) zz

countAs :: [[Int]] -> M.Map Int Int
countAs ass = foldr f aInit [j | j <- concat ass, j >= 0]
  where f i mmap = M.alter g i mmap
        g Nothing = Just 1
        g (Just k) = Just (k + 1)
        aInit = M.fromList $ zip [0..9] (repeat 0)

modCmap :: CMap -> CMap
modCmap cmap = mcSub [(i,j) | i <- [0..9], j <- [0..9], i /= j] cmap

mcSub :: [(Int, Int)] -> CMap -> CMap
mcSub [] cmap = cmap
mcSub (p : tbc) cmap = mcSub ([q | q <- added, notElem q tbc] ++ tbc) newCmap
  where (added, newCmap) = mcSub2 p cmap

mcSub2 :: (Int, Int) -> CMap -> ([(Int, Int)], CMap)
mcSub2 (i,j) cmap = (map fst ps, foldr h cmap ps)
  where
    f k | i == k = []
        | j == k = []
        | otherwise = g i j k ++ g k i j
    g a b c | dist_abc < dist_ac = [((a,c), dist_abc)]
            | otherwise          = []
      where dist_abc = (cmap M.! (a,b)) + (cmap M.! (b,c))
            dist_ac  =  cmap M.! (a,c)
    ps = concatMap f [0..9]
    h ((a,b), dist) = M.adjust (const dist) (a,b)

solve :: CMap -> M.Map Int Int -> Int
solve cmap amap =
  let cmapMod = modCmap (qTrace "cmap" cmap)
  in sum $ map (\i -> (amap M.! i) * (cmapMod M.! (i, 1))) [0..9]

main :: IO ()
main = do
  conts <- B.getContents
  let [valH, valW] : iss = map bsReadInts (B.lines conts)
      (css, ass) = splitAt 10 iss
      cmat = setMat css
      xA = countAs ass
      answer = solve cmat xA
  putStrLn (show answer)

