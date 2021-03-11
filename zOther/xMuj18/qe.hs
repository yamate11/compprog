{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE AllowAmbiguousTypes #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.Primitive
import Control.Monad.ST
import Control.Monad
import Data.List
import Debug.Trace

type VUM2Vec m a = (VUM.MVector (PrimState m) a, Int)
type VU2Vec a = (VU.Vector a, Int)

vum2new :: (PrimMonad m, VUM.Unbox a) => (Int,Int) -> m (VUM2Vec m a)
vum2new (p,q) = do
  arr <- VUM.new (p*q)
  return (arr, p)

vum2replicate :: (PrimMonad m, VUM.Unbox a)
              => (Int,Int) -> a -> m (VUM2Vec m a)
vum2replicate (p,q) a = do
  arr <- VUM.replicate (p*q) a
  return (arr, p)

vum2read :: (PrimMonad m, VUM.Unbox a)
         => VUM2Vec m a -> (Int,Int) -> m a
vum2read (arr,p) (x,y) = VUM.read arr (x+p*y)

vum2write :: (PrimMonad m, VUM.Unbox a)
          => VUM2Vec m a -> (Int,Int) -> a -> m ()
vum2write (arr,p) (x,y) a = VUM.write arr (x+p*y) a

vu2create :: forall a. VU.Unbox a
          => (forall s. ST s (VUM2Vec (ST s) a)) -> VU2Vec a
vu2create act = runST $ do
  (marr,p) <- act
  arr <- VU.unsafeFreeze marr
  return (arr, p)

vu2lookup :: VU.Unbox a => VU2Vec a -> (Int,Int) -> a
vu2lookup (arr,p) (x,y) = arr VU.! (x+p*y)

vu2fromList :: VU.Unbox a => Maybe Int -> [[a]] -> VU2Vec a
vu2fromList Nothing ass = vu2fromList (Just (length (head ass))) ass
vu2fromList (Just p) ass = (VU.fromList (concat ass), p)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> Int
tmain conts = 
  let line1 : line2 : line3_ = B.lines conts
      [n, m, k] = bsReadInts line1
      ds = B.unpack line2
      sss = map B.unpack line3_
  in solve n m k ds sss

main :: IO ()
main = putStrLn . show . tmain =<< B.getContents 

-------------------------------------------------------------------------------

type Cell = (Int,Int)

solve :: Int -> Int -> Int -> [Char] -> [[Char]] -> Int
solve n m k ds sss = runST (act m n k board dir nextDir (sx,sy))
  where
    board = vu2fromList (Just m) sss
    dir = VU.fromList ds
    nextDir = bldNextDir k ds
    (sx,sy) = findStart m n board

bldNextDir k ds = V.fromList $ take k $ scanr op [-1,-1,-1,-1] (ds ++ ds)
  where op d cur = zipWith f "RULD" cur
          where f c n | c == d    = 0
                      | n == -1   = -1
                      | otherwise = n+1

findStart m n board =
  head [(x,y) | x<-[0..m-1], y<-[0..n-1], vu2lookup board (x,y) == 'S']

act :: Int -> Int -> Int -> VU2Vec Char -> VU.Vector Char
    -> V.Vector [Int] -> Cell -> ST s Int
act m n k board dir nextDir (sx,sy) = do
  brdS <- vum2replicate (m,n) False
  front <- mapM (initFront brdS) (nbrCells (sx,sy))
  actBody 0 front brdS
  where

    actBody k front brdS
      | trace ("actBody k " ++ show k ++ " front " ++ show front) False = undefined
    actBody k front brdS = 
      case effK k front nextDir of
        Nothing -> return (-1)
        Just k0 -> actSub k0 front brdS

    actSub :: Int -> [[Cell]] -> VUM2Vec (ST s) Bool -> ST s Int
    actSub k front brdS = do
      let d = dir VU.! k
          fr = front !! (didx d)
      if hasGoal fr board then return k else do
        frdiff <- forM fr $ \c -> do
          iteMM (vum2read brdS c)
                (return [Nothing,Nothing,Nothing,Nothing])
                $ do
            vum2write brdS c True
            mapM (\c' -> iteM (open brdS c') (Just c') Nothing) (nbrCells c)
        showM brdS
        actBody (k+1) (newFront d front frdiff) brdS

    open brdS (x,y)
      | x >= 0 && x < m && y >= 0 && y < n && vu2lookup board (x,y) /= '#'
            = (not) <$> vum2read brdS (x,y)
      | otherwise = return False

    initFront brdS c = iteM (open brdS c) [c] []
     
    showM brdS = do
      css <- forM [0..n-1] $ \y -> 
        forM [0..m-1] $ \x -> do
          b <- vum2read brdS (x,y)
          return $ if b then '*' else '.'
      vum2read brdS (trace ("brdS " ++ show css) (0,0))
      return ()

effK k front nextDir | null ts = Nothing
                     | otherwise = Just (k + minimum ts)
  where
    ts = [t | (fr, t) <- zip front (nextDir V.! k), not (null fr), t >= 0]

didx 'R' = 0
didx 'U' = 1
didx 'L' = 2
didx 'D' = 3

hasGoal fr board = or $ map ((== 'G') . vu2lookup board) fr

newFront :: Char -> [[(Int,Int)]] ->[[Maybe (Int,Int)]] -> [[(Int,Int)]]
newFront d front frdiff = zipWith3 f [0..3] front (transpose frdiff)
  where f idx orig diff | didx d == idx  = diff'
                        | otherwise      = diff' ++ orig
          where diff' = catMaybes diff

nbrCells (x,y) = [(x+1,y),(x,y-1),(x-1,y),(x,y+1)]

{-
iteMM :: Monad m => m Bool -> m a -> m a -> m a
iteMM c et ee = do
  t <- c
  if t then et else ee
-}

iteMM :: Monad m => m Bool -> m a -> m a -> m a
iteMM = liftM3 (\c -> \et -> \ee -> if c then et else ee)

iteM :: Monad m => m Bool -> a -> a -> m a
iteM c et ee = iteMM c (return et) (return ee)

t1v = tmain $ B.pack inp1
t2v = tmain $ B.pack inp2
t3v = tmain $ B.pack inp3
test1 = t1v == 7
test2 = t2v == -1
test3 = t3v == 12
alltest = test1 && test2 && test3

inp1 = "\
\2 3 5\n\
\UDRRL\n\
\S..\n\
\.#G\n\
\"

inp2 = "\
\3 3 5\n\
\UDUDD\n\
\S..\n\
\...\n\
\.G.\n\
\"

inp3 = "\
\3 3 5\n\
\UDLRD\n\
\S..\n\
\.#.\n\
\..G\n\
\"
