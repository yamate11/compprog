{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
{-# LANGUAGE GADTs #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntSet as IS
-- import qualified Data.Vector as V
-- import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.ST
import Debug.Trace
-- trace _ = id

solve :: Int -> Int -> [(Int,Int,Int)] -> Int
solve bN bM lras = runST theAction where
  vLRA = VU.fromListN bM lras
  
  theAction :: ST s Int
  theAction = do
    vec <- VUM.new (4*bN)
    topIntv <- VUM.replicate (4*bN) 0
    bodyIntv <- VUM.new (100*bM)
    VUM.write bodyIntv 0 ((-1)::Int, 1::Int)
    removedIntv <- VUM.replicate bM False
    actSolve vec topIntv bodyIntv removedIntv
    where
    actSolve vec topIntv bodyIntv removedIntv = act
      where
  
      act = do
        sInit
        forM_ [0..bM-1] $ \intv -> do
          let (l,r,a) = vLRA VU.! intv
          sAdd True a intv (l-1) r
        traceNodes
        lpAct 0 0
      
      lpAct !ans !vSum = do
        (m, d) <- sRemove
        traceL "in lpAct" (ans,vSum,m,d) (return ())
        traceNodes
        if not d then return ans else do
          let nextSum = vSum + m
          lpAct (max ans nextSum) nextSum
  
      sInit = sub 0 0 bN where
        sub node l r = do
          VUM.write vec node (0, 0, False)
          when (l + 1 < r) $ do
            let mid = (l + r) `div` 2
            sub (2*node + 1) l mid
            sub (2*node + 2) mid r

      sAdd flag a intIdx left right = sub 0 0 bN where
        sub node l r = op >> sgNodeInfo node where
          op | left <= l && r <= right = do
                 let f (vSum,m,_) = (vSum+a, m, True)
                 VUM.modify vec f node
                 when flag $ do
                   (_, ib) <- VUM.read bodyIntv 0
                   VUM.write bodyIntv 0 (-1, ib+1)
                   p <- VUM.read topIntv node
                   VUM.write topIntv node ib
                   VUM.write bodyIntv ib (intIdx, p)
             | r <= left || right <= l = return ()
             | otherwise               = do
                 let mid = (l + r) `div` 2
                 (lm, _) <- sub (2*node + 1) l mid
                 (rm, _) <- sub (2*node + 2) mid r
                 let m = max lm rm
                 VUM.modify vec (\(s,_,_) -> (s, m, True)) node
          
      sRemove = sub minBound 0 0 bN where
        sub val node l r = do
          (vSum, vMax, d) <- VUM.read vec node
          if not d || vSum + vMax < val then return (vMax, d) else do
              p <- VUM.read topIntv node
              unless (p == 0) $ VUM.write topIntv node 0
              opsub p
              (newMax, newD) <- subsub vMax
              VUM.write vec node (0, newMax, newD)
              return (newMax, newD)
          where
          subsub vMax
            | l+1 == r = return (0, False)
            | otherwise = do
                let mid = (l + r) `div` 2
                (lm, ld) <- sub vMax (2*node + 1) l mid
                (rm, rd) <- sub vMax (2*node + 2) mid r
                return $ newPair (lm, ld) (rm, rd)

          newPair (lm, True) (rm, True) = (max lm rm, True)
          newPair (_, False) (_, False) = (0, False)
          newPair (lm, True) (_, False) = (lm, True)
          newPair (_, False) (rm, True) = (rm, True)

          opsub 0 = return ()
          opsub p = do
            (intv, q) <- VUM.read bodyIntv p
            b <- VUM.read removedIntv intv
            unless b $ do
              VUM.write removedIntv intv True
              let (l,r,a) = vLRA VU.! intv
              sAdd False (-a) intv (l-1) r
              return ()
            opsub q

      sgNodeInfo node = do
        (s,m,d) <- VUM.read vec node
        return $ (s + m, d)

      traceNodes = do
        forM_ [0..bN*4-1] $ \node -> do
          (s,m,d) <- VUM.read vec node
          traceL "node" (node, (s,m,d)) (return ())

{-
mfInit SgtIn rc vec node l r = do
  VUM.write vec node (0, 0, l)
  when (l+1 < r) rc
mfInit _ _ _ _ _ _ = error "internal error"
    
mfAdd :: Bool -> Int ->
         VM.MVector s [Int] -> Int ->
         SgtFT -> ST s ((Int,Int),(Int,Int)) ->
             VUM.MVector s (Int,Int,Int) -> Int -> Int -> Int -> ST s (Int,Int)
mfAdd flag a recIntv i ft rc vec node l r = sub ft >> sgNodeInfo vec node where
  sub SgtIn = do
    VUM.modify vec (\(vSum,p,q) -> (vSum + a,p,q)) node
    -- when flag (VM.modify recIntv (i:) node)
  sub SgtOut = return ()
  sub SgtOther = do
    (m, ma) <- maxWithArg <$> rc
    VUM.modify vec (\(vSum,_,_) -> (vSum, m, ma)) node
  
mfMax :: SgtFT -> ST s ((Int,Int),(Int,Int)) ->
         VUM.MVector s (Int,Int,Int) -> Int -> Int -> Int ->
         ST s (Int,Int)
mfMax SgtIn rc vec node l r = sgNodeInfo vec node
mfMax SgtOut rc vec node l r = return (minBound :: Int, -1)
mfMax SgtOther rc vec node l r = do
  (m, ma) <- maxWithArg <$> rc
  (vSum,_,_) <- VUM.read vec node
  return (vSum + m, ma)

sgNodeInfo :: VUM.MVector s (Int,Int,Int) -> Int -> ST s (Int,Int)
sgNodeInfo vec node = (\(s,m,a) -> (s+m,a)) <$> VUM.read vec node
maxWithArg ((m1,ma1), (m2,ma2)) = if m1 >= m2 then (m1,ma1) else (m2,ma2)

-- segment tree function type
data SgtFT = SgtIn | SgtOut | SgtOther deriving(Show)

sgtAct :: forall s a b. (VUM.Unbox a) =>
          (SgtFT -> ST s (b,b) ->
             VUM.MVector s a -> Int -> Int -> Int -> ST s b) ->
          VUM.MVector s a ->
          Int ->
          Int ->
          Int ->
          ST s b
sgtAct mf vec n left right = sub 0 0 n where
  sub :: Int -> Int -> Int -> ST s b
  sub node l r =
    mf (sgtft left right l r) (sgtChildAct sub node l r) vec node l r

sgtAct_ :: (VUM.Unbox a) =>
           (SgtFT -> ST s () ->
              VUM.MVector s a -> Int -> Int -> Int -> ST s ()) ->
           VUM.MVector s a ->
           Int ->
           Int ->
           Int ->
           ST s ()
sgtAct_ mf vec n left right = sub 0 0 n where
  sub node l r =
    mf (sgtft left right l r) (sgtChildAct_ sub node l r) vec node l r

sgtChildAct rc' node l r =
  let mid = (l + r) `div` 2
  in (,) <$> rc' (2*node + 1) l mid <*> rc' (2*node + 2) mid r

sgtChildAct_ rc' node l r = sgtChildAct rc' node l r >> return ()

sgtft left right l r
  | left <= l && r <= right = SgtIn
  | r <= left || right <= l = SgtOut
  | otherwise               = SgtOther
-}

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN,bs_bM]:remLines1 = remLines0
      bN = readBInt bs_bN
      bM = readBInt bs_bM
      lras = map (\[x1,x2,x3] -> (readBInt x1,readBInt x2,readBInt x3)) remLines1
  in solve bN bM lras

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "5 3\n1 3 10\n2 4 -10\n3 5 10\n"
inp2 = "3 4\n1 3 100\n1 1 -10\n2 2 -20\n3 3 -30\n"
inp3 = "1 1\n1 1 -10\n"
inp4 = "1 5\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n1 1 1000000000\n"
inp5 = "6 8\n5 5 3\n1 1 10\n1 6 -8\n3 6 5\n3 4 9\n5 5 -2\n1 3 -6\n4 6 -7\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test1 = tv1 == 20
test2 = tv2 == 90
test3 = tv3 == 0
test4 = tv4 == 5000000000
test5 = tv5 == 10
alltest = test1 && test2 && test3 && test4 && test5

