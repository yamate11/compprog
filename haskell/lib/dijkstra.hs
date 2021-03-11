{-# LANGUAGE ScopedTypeVariables #-}
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM
import qualified Data.Vector as VB
import qualified Data.Vector.Mutable as VBM
import Control.Monad
import Control.Monad.ST
import Data.STRef
import Data.Maybe
import qualified Data.IntMap.Strict as IM
import Data.List
import System.Random
import System.Environment
import qualified Data.ByteString.Lazy.Char8 as B

-- Priority Queue, optimised for Dijkstra Algorithm
type PQueue s = ( STRef s Int               -- cur index in heap
                , VM.MVector s (Int, Int)   -- heap
                , VM.MVector s Int          -- record
                )
-- The heap is represented by a vector with 1-based index.
-- A value of heap (loc, dist), meaning that the distance of location
--     loc should be updated with dist.
-- If (record ! loc == (-1)), then, (loc, _) does not appear in heap.
-- If (record ! loc == i), then, heap ! i == (loc, _)    (i > 0)

-- max index should take large enough.
-- Dynamic modification may be possible, but a bit cumbersome as
-- VM.grow returns a new vector.

pqInit :: Int -> ST s (PQueue s)
pqInit n = do
  ci <- newSTRef 1
  heap <- VM.new (n + 1)
  rcd <- VM.replicate n (-1)
  return (ci, heap, rcd)

_pqWrite :: PQueue s -> Int -> Int -> Int -> ST s ()
_pqWrite (_,heap,rcd) i loc dist = do
  VM.write heap i (loc,dist)
  VM.write rcd loc i

pqPut :: PQueue s -> Int -> Int -> ST s ()
pqPut pq@(ci, heap, rcd) loc dist =
  VM.read rcd loc >>= getIdx >>= act
  where
    getIdx i
      | i > 0 = do
          (_,iDist) <- VM.read heap i
          if iDist <= dist then return Nothing else return (Just i)
      | i < 0 = do
          curIdx <- readSTRef ci
          writeSTRef ci (curIdx + 1)
          return (Just curIdx)
    act Nothing = return ()
    act (Just idx) = do
      _pqWrite pq idx loc dist
      popups pq idx

popups :: PQueue s -> Int -> ST s ()
popups _ 1 = return ()
popups pq@(_, heap, rcd) i = do
  let j = i `div` 2
  (li, di) <- VM.read heap i
  (lj, dj) <- VM.read heap j
  if dj <= di then return ()
    else do
    _pqWrite pq j li di
    _pqWrite pq i lj dj
    popups pq j

pqGet :: PQueue s -> ST s (Maybe (Int,Int))
pqGet (ci, heap, rcd) = do
  newIdx <- (+ (-1)) <$> readSTRef ci
  if newIdx == 0 then return Nothing
    else do
    writeSTRef ci newIdx
    (rLoc, rDist) <- VM.read heap 1
    VM.read heap newIdx >>= pushdowns (ci, heap, rcd) 1 newIdx
    VM.write rcd rLoc (-1)
    return (Just (rLoc, rDist))

pushdowns :: PQueue s -> Int -> Int -> (Int,Int) -> ST s ()
pushdowns (ci,heap,rcd) i newIdx (aLoc,aDist) = getProm >>= doProm
  where
    doProm Nothing = do
      VM.write heap i (aLoc,aDist)
      VM.write rcd aLoc i
    doProm (Just (j,loc,dist)) = do
      VM.write heap i (loc,dist)
      VM.write rcd loc i
      pushdowns (ci,heap,rcd) j newIdx (aLoc,aDist)
    getProm = do
      let (j,k) = (2*i, 2*i+1)
      if j >= newIdx then return Nothing
        else do
        (jLoc,jDist) <- VM.read heap j
        if k == newIdx then
          if aDist <= jDist then return Nothing
                            else return (Just (j,jLoc,jDist))
          else do
          (kLoc,kDist) <- VM.read heap k
          if aDist <= jDist && aDist <= kDist then return Nothing
            else if jDist <= kDist then return (Just (j,jLoc,jDist))
            else                        return (Just (k,kLoc,kDist))

bigN :: Int
bigN = 1000*1000*1000 + 7

-- When d = dijkstra n graph goal, d[i] is the distance between i and goal,
-- where (i,j,p) \in graph means that there is a path between i and j
-- with length p, and n is the number of vertices.
dijkstra :: Int -> [(Int, Int, Int)] -> Int -> V.Vector Int
dijkstra n graph goal = V.create act
  where
  neighbour :: VB.Vector [(Int, Int)]
  neighbour = VB.create $ do
    nb <- VBM.replicate n []
    forM_ graph $ \(i,j,p) -> do
      VBM.modify nb ((j, p):) i
      VBM.modify nb ((i, p):) j
    return nb

  act = do
    distVec <- VM.replicate n bigN
    pq <- pqInit n
    pqPut pq goal 0
    act1 pq distVec

  act1 pq distVec = pqGet pq >>= act2 pq distVec

  act2 _  distVec Nothing           = return distVec
  act2 pq distVec (Just (loc,dist)) = do
    x <- VM.read distVec loc
    when (x <= dist) (error "internal error")
    VM.write distVec loc dist
    forM_ (neighbour VB.! loc) $ \(j, p) -> do
      curD <- VM.read distVec j
      when (dist + p < curD) (pqPut pq j (dist + p))
    act1 pq distVec
      
--- performance results
---   vertex 1e4 edges 1.2e4   0.07sec
---   vertex 1e4 edges 9e4     0.23sec
---   vertex 1e5 edges 1.2e5   0.28sec
---   vertex 1e5 edges 9e5     2.35sec


----------------------------------------------------------------------
-- for verification

dist_naive :: Int -> [(Int,Int,Int)] -> Int -> IM.IntMap Int
dist_naive n graph goal = updMap initMap
  where
  neighbour :: IM.IntMap [(Int, Int)]
  neighbour = foldl' op IM.empty graph
    where
    op im (i,j,p) = IM.alter (upd i p) j (IM.alter (upd j p) i im)
    upd i p Nothing = Just [(i, p)]
    upd i p (Just xs) = Just ((i, p) : xs)

  initMap :: IM.IntMap Int
  initMap = IM.adjust (const 0) goal $ foldl' op IM.empty [0 .. n-1]
    where
    op im i = IM.insert i bigN im

  updMap :: IM.IntMap Int -> IM.IntMap Int
  updMap im = let (b, im1) = updMap1 im
              in if b then updMap im1 else im1

  updMap1 :: IM.IntMap Int -> (Bool, IM.IntMap Int)
  updMap1 im = foldl' op (False, im) [0 .. n-1] 
    where
    op (b, im) i = foldl' (op2 (im IM.! i)) (b, im) (neighbour IM.! i)
      where
      op2 x (b, im) (j, p)
        | x + p < im IM.! j = (True, IM.adjust (const (x + p)) j im)
        | otherwise         = (b,    im)
      
maxP :: Int
maxP = 10000

genGraphPF :: RandomGen g => g -> Int -> Int -> [(Int, Int, Int)]
genGraphPF g k d =
  [(i,j,p) | i <- [0 .. k-2],
             (j,p) <- IM.toAscList (theMap IM.! i)]
  where
    initMap :: IM.IntMap (IM.IntMap Int)
    initMap = foldl' op IM.empty [0 .. k-2]
      where
        op im i = IM.insert i (IM.singleton (i+1) maxP) im

    theMap = fst $ head $ dropWhile (\(_, count) -> count < d) $
        scanl op (initMap, k-1) randList
      where
        op (im, count) (i, j, p) =
          case IM.lookup j oldSubIm of
          Nothing -> (newIm, count + 1)
          Just _  -> (im, count)
          where
            oldSubIm = im IM.! i
            newIm = IM.adjust (const newSubIm) i im
            newSubIm = IM.insert j p oldSubIm

    (g1, g2a) = split g
    (g2, g3) = split g2a
    li = randomRs (0, k-1) g1
    lj = randomRs (0, k-1) g2
    lp = randomRs (0, maxP) g3
    randList = mkRL li lj lp
    mkRL (i:li) (j:lj) (p:lp)
      | i < j = (i,j,p) : mkRL li lj lp
      | i > j = (j,i,p) : mkRL li lj lp
      | otherwise = mkRL li lj lp
      
genGraph :: Int -> Int -> IO ([(Int,Int,Int)])
genGraph k d = do
  sg <- getStdGen
  return (genGraphPF sg k d)

poutGraph :: Int -> Int -> IO ()
poutGraph k d = do
  graph <- genGraph k d
  putStrLn (show k)
  forM_ graph $ \(i,j,p) ->
    putStrLn (show i ++ " " ++ show j ++ " " ++ show p)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

readInput :: IO (Int, [(Int,Int,Int)])
readInput = do
  conts <- B.getContents
  let [n] : iss = map bsReadInts (B.lines conts)
  return (n, [(i,j,k) | [i,j,k] <- iss])

-- Usage
--   Run
--   ./dijkstra 1 0 0 < data
--   Make Data
--   ./dijkstra 2 k d > data
--        (k = the number of vertices, d = the number of edges)
main :: IO ()
main = do
  [mode, k, d] <- getArgs >>= return . map read
  if mode == 1 then do
    (n, graph) <- readInput
    let v = dijkstra n graph 0
    putStrLn (show (V.sum v))
    else if mode == 2 then
           poutGraph k d
         else
           error "Unknown mode"

----------------------------------------------------------------------
-- test programs

_pint :: PQueue s -> ST s String
_pint (ci,heap,_) = do
  curIdx <- readSTRef ci
  ls <- forM [1 .. (curIdx - 1)] $ \i -> do
    (l,d) <- VM.read heap i
    return (i,l,d)
  return (show ls)
         
_verify :: String -> PQueue s -> [(Int,Int)] -> ST s ()
_verify lab (ci,heap,rcd) lds = do
  curIdx <- readSTRef ci
  when (curIdx /= length lds + 1)
    (vErr ("Unmatch in length: curIdx = " ++ show curIdx))
  forM_ (zip [1..] lds) $ \(i,(l,d)) -> do
    (lx,dx) <- VM.read heap i
    when ((l,d) /= (lx,dx)) 
      (vErr ("Unmatch: i = " ++ show i ++ ", loc = " ++ show lx ++
             ", dist = " ++ show dx))
    idx <- VM.read rcd lx
    when (idx /= i)
      (vErr ("Unmatched location: " ++ show idx ++ " and " ++ show i))
  forM_ [0 .. (VM.length rcd) - 1] $ \loc -> do
    idx <- VM.read rcd loc
    when (idx > 0) $ do
      (lx, _) <- VM.read heap idx
      when (loc /= lx)
        (vErr ("Unmatched loc from rdc: " ++ show loc ++ " and " ++ show lx))
  where
    vErr msg = error (lab ++ ": " ++ msg)

test1 :: ()
test1 = runST $ do
  pq <- pqInit 10
  pqPut pq 0 5
  _verify "1-1" pq [(0,5)]
  (lA0,dA0) <- pqGet pq >>= return . fromJust
  unless (lA0 == 0 && dA0 == 5) (error ("1-1a"))
  _verify "1-2" pq []
  pqPut pq 0 5
  _verify "1-3" pq [(0,5)]
  pqPut pq 1 3
  _verify "1-4" pq [(1,3),(0,5)]
  (lA1,dA1) <- pqGet pq >>= return . fromJust
  unless (lA1 == 1 && dA1 == 3) (error ("1-4a"))
  _verify "1-5" pq [(0,5)]
  pqPut pq 2 6
  _verify "1-6" pq [(0,5),(2,6)]
  (lA,dA) <- pqGet pq >>= return . fromJust
  unless (lA == 0 && dA == 5) $ do
    msg <- _pint pq
    error ("1-6a" ++ msg)
  _verify "1-7" pq [(2,6)]
  (lB,dB) <- pqGet pq >>= return . fromJust
  unless (lB == 2 && dB == 6) (error "1-7a")
  _verify "1-8" pq []
  xD <- pqGet pq
  unless (xD == Nothing) (error "1-8a")
  _verify "1-9" pq []
  pqPut pq 3 7
  pqPut pq 1 4
  _verify "1-10" pq [(1,4),(3,7)]
  pqPut pq 3 2
  _verify "1-11" pq [(3,2),(1,4)]
  pqPut pq 2 7
  pqPut pq 4 9
  _verify "1-12" pq [(3,2),(1,4),(2,7),(4,9)]
  (l12,d12) <- pqGet pq >>= return . fromJust
  unless (l12 == 3 && d12 == 2) (error "1-12a")
  _verify "1-13" pq [(1,4),(4,9),(2,7)]
  (l13,d13) <- pqGet pq >>= return . fromJust
  unless (l13 == 1 && d13 == 4) (error "1-13a")
  _verify "1-14" pq [(2,7),(4,9)]
  pqGet pq
  pqGet pq
  pqPut pq 3 2
  pqPut pq 2 7
  pqPut pq 1 4
  pqPut pq 4 9
  _verify "1-15" pq [(3,2),(2,7),(1,4),(4,9)]
  (l15,d15) <- pqGet pq >>= return . fromJust
  unless (l15 == 3 && d15 == 2) (error "1-15a")
  _verify "1-16" pq [(1,4),(2,7),(4,9)]
  return ()
  
test2 :: IO ()
test2 = do
  let n = 1000
  graph <- genGraph n (ceiling ((fromIntegral n) * 1.3))
  let stdImpl = dist_naive n graph 0
  let impl = dijkstra n graph 0
  unless (foldr1 (&&) [stdImpl IM.! i == impl V.! i | i <- [0 .. n-1]])
    (error "not equal")
