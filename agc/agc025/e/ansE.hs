{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}

{- This code was written after reading the editorial. -}

import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Primitive
import Data.List

solve n m abs uvs = ans where
  (root, parent, children) = buildTree n abs
  (mark, path, cstr) = runST $ action n m uvs root parent children
  rows = zipWith f (VU.toList path) (VU.toList cstr)
    where f (u,v) (_,b) = if b then [u,v] else [v,u]
  ans = unlines $ map (unwords . map show) $ [m] : rows

buildTree :: Int -> [(Int,Int)] -> (Int, VU.Vector Int, V.Vector [Int])
buildTree n abs = runST btAct
  where
  btAct :: ST s (Int, VU.Vector Int, V.Vector [Int])
  btAct = do
    nbr <- VM.replicate (n+1) []
    forM_ abs $ \(a,b) -> do
      VM.modify nbr (a:) b
      VM.modify nbr (b:) a
    parent <- VUM.new (n+1)
    subAct nbr parent

    where
    subAct nbr parent = do
      sub 1 Nothing
      f_parent <- VU.unsafeFreeze parent
      f_nbr <- V.unsafeFreeze nbr
      return (1, f_parent, f_nbr)
      where
        sub i parent = do
          js <- VM.read nbr i
          let js' = [j | j <- js, Just j == parent]
          VM.write nbr i js'
          forM_ js' $ \j -> sub j (Just i)

action :: forall s. Int -> Int -> [[Int]] -> Int
          -> VU.Vector Int -> V.Vector [Int]
          -> ST s (Int, VU.Vector (Int,Int), VU.Vector (Int,Bool))
action n m uvs root parent children = do

  numCld <- VUM.new (n+1)
  forM [1..n] $ \i -> VUM.write numCld i (length (children V.! i))
  path <- VUM.new m
  ndPath <- VM.replicate (n+1) []
  ndPathPair <- VM.replicate (n+1) []
  forM (zip [0..m-1] uvs) $ \(i, [u,v]) -> do
    VUM.write path i (u,v)
    VM.modify ndPath ((i,True):) u
    VM.modify ndPath ((i,False):) v
  cstr <- VUM.replicate m (-1, False)
  act_body n m numCld path ndPath ndPathPair cstr root parent
  
act_body :: forall s. Int -> Int -> VUM.MVector s Int
         -> VUM.MVector s (Int,Int) -> VM.MVector s [(Int,Bool)]
         -> VM.MVector s [((Int,Bool),(Int,Bool))] -> VUM.MVector s (Int,Bool)
         -> Int -> VU.Vector Int
         -> ST s (Int, VU.Vector (Int,Bool))
act_body n m numCld path ndPath ndPathPair cstr root parent = do
  leaf <- filterM (liftM (== 0) . VUM.read numCld) [1..n]
  mark <- sum <$> (forM leaf $ opLeaf 0 [] [])

  forM_ [0..m-1] $ \i -> do
    (ref, b1) <- VUM.read cstr i
    if ref < 0 then VUM.write cstr i (-1, True)
      else do
      (_, b2) <- VUM.read cstr ref
      VUM.write cstr i (-1, b1 `equiv` b2)
      
  f_path <- VU.unsafeFreeze path
  f_cstr <- VU.unsafeFreeze cstr
  return (mark, f_path, f_cstr)

  where
    opLeaf cnt pairs rests i0 = do
      rests0 <- VM.read ndPath i0
      pairs0 <- VM.read ndPathPair i0
      let (pairs', rests') = merge pairs rests pairs0 rests0
      (pairs'', rests'') <-
        if null pairs' && length2 rests' == 2
        then do
          let j1:j2:js = rests'
          regCstr j1 j2
          return ([(j1,j2)], rests')
        else return (pairs', rests')
      liftM3 ite ((== 0) <$> VUM.read numCld i0)
        (let thisCnt | not (null pairs'') = 2
                     | not (null rests'') = 1
                     | otherwise = 0
         in opLeaf (cnt+thisCnt) pairs'' rests'' (parent VU.! i0))
        $ do
          VUM.modify numCld (+ (-1)) i0
          VM.write ndPath i0 rests''
          VM.write ndPathPair i0 pairs''
          return cnt

    regCstr :: (Int, Bool) -> (Int, Bool) -> ST s ()
    regCstr (j1,b1) (j2,b2) = do
      (top1, b1') <- getTop j1 b1
      (top2, b2') <- getTop j2 b2
      let b0 = b1' `equiv` b2'
      if top1 == top2
        then if not b0 then return ()
             else error "internal error"
        else do
        let (topA, topB) = (min top1 top2, max top1 top2)
        VUM.write cstr topB (topA, b0)
      where
        getTop j b = do
          (j', b') <- VUM.read cstr j
          if j' < 0 then return (j, b)
          else getTop j' (b `equiv` b')

ite c t e = if c then t else e

equiv b1 b2 = (b1 && b2) || ((not b1) && (not b2))

merge pairs1 rests1 pairs2 rests2 = (pairsC ++ pairsD, restsC ++ restsD)
  where
    mem2 = mirror $ (concatMap (\(x,y) -> [x,y]) pairs2) ++ rests2
    (matchedA, restA) = partition (flip elem mem2) rests1
    pairsB = map f pairs1
      where
        f (x,y) | x_in && y_in = ([], [], [x,y])
                | x_in         = ([], [y], [x])
                | y_in         = ([], [x], [y])
                | otherwise    = ([(x,y)], [], [])
          where x_in = elem x mem2
                y_in = elem y mem2
    pairsC = concatMap (\(x,_,_) -> x) pairsB
    restsC = concatMap (\(_,x,_) -> x) pairsB
    matchedC = concatMap (\(_,_,x) -> x) pairsB
    matched = mirror $ matchedA ++ matchedC
    restsD = filter (\x -> not (elem x matched)) rests2
    pairsD = filter (\(x,y) -> not (elem x matched) && not (elem y matched))
                    pairs2
      
mirror mems = map (\(i,b) -> (i,not b)) mems

length2 [] = 0
length2 [_] = 1
length2 _ = 2

