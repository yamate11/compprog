{-# LANGUAGE ViewPatterns, MultiWayIf, ScopedTypeVariables #-}

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Sequence as S
import Control.Monad
import Control.Monad.ST
import Data.STRef

import Debug.Trace

-- traceQ label a
--   Traces the value of a with label.
traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

data Nbr = Nbr { idx :: Int
               , dist :: Int
               } deriving (Show)

data Point = Point { nbr :: [Nbr]
                   , toS :: [Int]
                   , toT :: [Int]
                   , nWayS :: Int
                   , nWayT :: Int
                   , distT :: Int
                   } deriving (Show)

bigP :: Int
bigP = 1000000000 + 9

addMod :: Int -> Int -> Int
addMod x y = (x + y) `mod` bigP

subtMod :: Int -> Int -> Int
subtMod x y = (bigP + x - y) `mod` bigP

multMod :: Int -> Int -> Int
multMod x y = (x * y) `mod` bigP

solve :: [[Int]] -> Int
solve ([valN,valM]:[valS,valT]:uvds) = runST (act valN valS valT uvds)

act :: Int -> Int -> Int -> [[Int]] -> ST s Int
act valN valS valT uvds= do
  vec <- buildVec valN uvds
  shortPath vec valN valT
  pS <- VM.read vec valS
  let distST = distT (traceQ "pS" pS)
  revPath vec valS
  countWay vec valN valT (getterTS vec distST) (setterTS vec) accumTS
  numCollision <- countWay vec valN valS
                           (getterST vec) (setterST vec) (accumST vec distST)
  pT <- VM.read vec valT
  let numAll = (nWayT pT) `multMod` (nWayT (traceQ "pT" pT))
  return ((traceQ "numAll" numAll) `subtMod` (traceQ "numCollision" numCollision))
  where
    getterTS vec distST i = do
      p <- VM.read vec i
      return (toT p, toS p, nWayS p, 2 * (distT p) <= distST)
    setterTS vec i v =
      VM.modify vec (\p -> p{ nWayS = v }) i
    accumTS _ _ _ = return ()
    getterST vec i = do
      p <- VM.read vec i
      return (toS p, toT p, nWayT p, True)
    setterST vec i v =
      VM.modify vec (\p -> p{ nWayT = v }) i
    accumST vec distST ref i j 
      | i == j = do
          p <- VM.read vec i
          when (2 * (distT p) == distST) $ do
            let x = (nWayT p) `multMod` (nWayS (traceQ "pp" p))
            modifySTRef ref (addMod (x `multMod` x))
      | i /= j = do
          p <- VM.read vec i
          let dbgP = "acc p (" ++ show i ++ ") " ++ show p
          when (2 * (distT (traceZ dbgP p)) > distST) $ do
            q <- VM.read vec j
            let dbgQ = "acc q (" ++ show j ++ ") " ++ show q
            when (2 * (distT (traceZ dbgQ q)) < distST) $ do
              let x = (traceQ "acc s p" (nWayT p))
                         `multMod` (traceQ "acc t q" (nWayS q))
              modifySTRef ref (addMod x)

buildVec :: Int -> [[Int]] -> ST s (VM.MVector s Point)
buildVec valN uvds = do
  vec <- VM.replicate (valN+1) (Point [] [] [] 0 0 bigP)
  forM_ uvds $ \[u,v,d] -> do
    upd vec u v d
    upd vec v u d
  return vec
  where
    upd :: VM.MVector s Point -> Int -> Int -> Int -> ST s ()
    upd vec x y d = VM.modify vec f x
      where f p = p{ nbr = (Nbr y d) : nbr p }

shortPath :: VM.MVector s Point -> Int -> Int -> ST s ()
shortPath vec valN valT = do
  VM.modify vec (\p -> p{ distT = 0 }) valT
  waitV <- VM.replicate (valN+1) False
  seqWhileExistsST (body waitV) (S.singleton valT)
  where
    body waitV upd i = do
      p <- VM.read vec (traceQ "i_from_queue" i)
      VM.write waitV i False
      forM_ (nbr p) $ \(Nbr idx dist) -> do
        q <- VM.read vec (traceQ "sp_idx" idx)
        let candDistT = (distT p) + dist
        if | (traceQ "candDistT" candDistT) == (traceQ "distT q" (distT q)) -> 
               VM.write vec idx (q { toT = i : (toT q) })
           | candDistT < distT q -> do
               VM.write vec idx (q { toT = [i], distT = candDistT })
               b <- VM.read waitV idx
               unless b $ do
                 upd idx
                 VM.write waitV idx True
           | otherwise -> return ()

revPath :: VM.MVector s Point -> Int -> ST s ()
revPath vec valS =
  seqWhileExistsST body (S.singleton valS)
  where
    body upd i = do
      p <- VM.read vec i
      forM_ (toT p) $ \j -> do
        q <- VM.read vec j
        when (null (toS q)) (upd j)
        VM.write vec j (q{ toS = i : (toS q) })

countWay :: VM.MVector s Point -> Int -> Int
            -> (Int -> ST s ([Int], [Int], Int, Bool))
            -> (Int -> Int -> ST s ())
            -> ((STRef s Int) -> Int -> Int -> ST s ())
            -> ST s Int
countWay vec valN start getter setter accum = do
  acc <- newSTRef 0
  rem <- VM.new (valN+1)
  forM_ [1 .. valN] $ \i -> do
    (back, fwd, num, inDom) <- getter i
    VM.write rem i (length back)
  setter (traceZ ("init setter " ++ show start ++ " 1") start) 1
  seqWhileExistsST (body acc rem) (S.singleton start)
  readSTRef acc
  where
    body acc rem upd i = do
      accum acc i i
      (back, fwd, num, inDom) <- getter (traceQ "cw i" i)
      forM_ (traceQ "fwd" fwd) $ \j -> do
        (jBack, jFwd, jNum, jInDom) <- getter j
        when (jInDom) $ do
          let xx = jNum `addMod` num
          let msg = "cw setter " ++ show j ++ " " ++ show xx
          setter (traceZ msg j) xx
          r <- VM.read rem j
          VM.write rem j (r - 1)
          when (r - 1 == 0) (upd j)
          accum acc i j

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

flow = putStrLn . show . solve . map bsReadInts . B.lines

main :: IO ()
main = flow =<< B.getContents



---------------------------------
data1 = "4 4\n1 3\n1 2 1\n2 3 1\n3 4 1\n4 1 1\n"
data2 = "3 3\n1 3\n1 2 1\n2 3 1\n3 1 2\n"
data3 = "3 3\n1 3\n1 2 1\n2 3 1\n3 1 2\n"
data4 = "8 13\n4 2\n7 3 9\n6 2 3\n1 6 4\n7 6 9\n3 8 9\n1 2 2\n2 8 12\n8 6 9\n2 5 5\n4 2 18\n5 3 7\n5 1 515371567\n4 8 6\n"
test1 = flow $ B.pack data1
test2 = flow $ B.pack data2
test3 = flow $ B.pack data3
test4 = flow $ B.pack data4


---------------------------------

{-
The pattern written here is for a loop while some list
or sequence or whatever has some elements, in the ST monad.

Type a is the type of contents
Type b is the type of collection of a, such as [a] or Seq a

whileExistsST extract add body initCol :: ST s ()
  extract :: b -> Maybe (a, b)
    If elements exist, Just (head, tail) returns
    otherwise, Nothing returns
  add :: a -> b -> b
    add an element to the collection
  body upd elem :: ST s ()
    upd :: a -> ST s ()
    elem :: a
    body is the function that the user should supply, implementing
    the procedure.  Doing so, the user can use upd :: a -> ST s (),
    which is the action to add an element to the collection in
    the ST monad.  elem is the element to be handled in body.
  initCol :: b
    initial collection
-}

whileExistsST :: forall a b s. (b -> Maybe (a, b))
              -> (a -> b -> b)
              -> ((a -> ST s ()) -> a -> ST s ())
              -> b
              -> ST s ()
whileExistsST extract add body initCol =
  newSTRef initCol >>= f
  where
  f :: (STRef s b) -> ST s ()
  f refCol = do
    col <- readSTRef refCol
    case extract col of
      Nothing       -> return ()
      Just (a, rem) -> do
        writeSTRef refCol rem
        body update a
        f refCol
      where update a = modifySTRef refCol (add a)

{-
  seqWhileExistsST is for a FIFO sequence.
-}
seqWhileExistsST :: ((a -> ST s ()) -> a -> ST s ())
                 -> S.Seq a
                 -> ST s ()
seqWhileExistsST = whileExistsST extract (\a seq -> seq S.|> a)
  where
    extract (S.viewl -> S.EmptyL)  = Nothing
    extract (S.viewl -> x S.:< xs) = Just (x, xs)

{-
  seqWhileExistsST is for a list, i.e., a stack
-}
listWhileExistsST :: ((a -> ST s ()) -> a -> ST s ())
                  -> [a]
                  -> ST s ()
listWhileExistsST = whileExistsST extract (\a as -> a : as)
  where
    extract [] = Nothing
    extract (a:as) = Just (a, as)

