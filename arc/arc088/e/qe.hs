import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Char
import qualified Data.Map.Strict as M
import Data.Sequence hiding (length, splitAt, zip, scanl)
import Data.Bits
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Data.Foldable

data CntSet = CSleaf Bool | CSnode Int CntSet CntSet
                            deriving(Show)

csCount :: CntSet -> Int
csCount (CSleaf b) = if b then 1 else 0
csCount (CSnode n _ _) = n

csJoin :: CntSet -> CntSet -> CntSet
csJoin (CSleaf False) (CSleaf False) = CSleaf False
csJoin cst1 cst2 = CSnode (csCount cst1 + csCount cst2) cst1 cst2

csCaseCalc :: (Bool -> Int -> Int -> a) ->
              (CntSet -> a) ->
              (Bool -> a -> a -> a) ->
              CntSet -> Int -> Int -> a
csCaseCalc fLeaf _ _ (CSleaf b) depth idx = fLeaf b depth idx
csCaseCalc fLeaf fDummy fNode (CSnode _ cst1 cst2) depth idx = 
  if testBit idx (depth - 1)
  then fNode True  (fDummy cst1) (g cst2)
  else fNode False (g cst1) (fDummy cst2)
  where g cst' = csCaseCalc fLeaf fDummy fNode
                            cst' (depth - 1) (clearBit idx (depth - 1))

csCaseCons :: (Bool -> Int -> Int -> CntSet) ->
              CntSet -> Int -> Int -> CntSet
csCaseCons fLeaf = csCaseCalc fLeaf id (\_ -> csJoin)

fLeafAdd :: Bool -> Int -> Int -> CntSet
fLeafAdd _ 0 _ = CSleaf True
fLeafAdd _ d i = csAdd (CSnode 0 (CSleaf False) (CSleaf False)) d i

csAdd :: CntSet -> Int -> Int -> CntSet
csAdd = csCaseCons fLeafAdd

csDelete :: CntSet -> Int -> Int -> CntSet
csDelete = csCaseCons (\_ _ _ -> CSleaf False)

csTest :: CntSet -> Int -> Int -> Bool
csTest = csCaseCalc (\b _ _ -> b) (\_ -> False) (\_ -> (||))

-- csLessCount cst d i Returns the number of elements less than i
fNodeLessCount :: Bool -> Int -> Int -> Int
fNodeLessCount True  c1 c2 = c1 + c2
fNodeLessCount False c1 _  = c1

csLessCount :: CntSet -> Int -> Int -> Int
csLessCount = csCaseCalc (\_ _ _ -> 0) csCount fNodeLessCount

-- fuse csCaseCalc
csFuseCaseCalc :: (Bool -> Int -> Int -> a, Bool -> Int -> Int -> b) ->
                  (CntSet -> a, CntSet -> b) ->
                  (Bool -> a -> a -> a, Bool -> b -> b -> b) ->
                  CntSet -> Int -> Int -> (a, b)
csFuseCaseCalc (fLeaf1, fLeaf2) (fDummy1, fDummy2) (fNode1, fNode2)
  = csCaseCalc fLeaf fDummy fNode
  where fLeaf b d i = (fLeaf1 b d i, fLeaf2 b d i)
        fDummy cst = (fDummy1 cst, fDummy2 cst)
        fNode t (a1, b1) (a2, b2) = (fNode1 t a1 a2, fNode2 t b1 b2)

-- add and less-count
csAddLessCount :: CntSet -> Int -> Int -> (CntSet, Int)
csAddLessCount =
  csFuseCaseCalc (fLeafAdd,     \_ _ _ -> 0)
                 (id,           csCount)
                 (\_ -> csJoin, fNodeLessCount)

type MyMap = M.Map Char (Seq Int)

myAct :: [Char] -> ST s Int
myAct s = do
  let num = length s
      logNum = ceiling $ logBase 2 $ fromIntegral num
      imapInit = foldr f M.empty (zip [0..] s)
        where f (i, c) m = M.alter f' c m
                where f' Nothing   = Just $ i <| empty
                      f' (Just is) = Just $ i <| is
  vec <- VM.new num
  forM_ (zip [0..] s) $ \(i, c) -> VM.write vec i c
  (result, _, _, _, _, _) <-
    foldM actBody (0, vec, CSleaf False, logNum, imapInit, False)
                  [num-1, num-2 .. 0]
  return result

type MyAB s = (Int, VM.MVector s Char, CntSet, Int, MyMap, Bool)
actBody :: MyAB s -> Int -> ST s (MyAB s)
actBody ab@(-1, _, _, _, _, _) _ = return ab
actBody (acc, vec, cst, logNum, imap, exOdd) i = do
  c <- VM.read vec i
  if c == 'X' then return (acc, vec, cst, logNum, imap, exOdd)
    else do
    VM.write vec i 'X'
    let is :> _ = viewr (imap M.! c)   -- the last element must be i
    case viewl is of    
      j :< body -> do
        VM.write vec j 'X'
        let (cst', count) = csAddLessCount cst logNum j
            newAcc = acc + (j - count) + (if exOdd then 1 else 0)
            newImap = M.update (const (Just body)) c imap
        return (newAcc, vec, cst', logNum, newImap, exOdd)
      _ -> if exOdd then return (-1, vec, cst, logNum, imap, exOdd)
           else return (acc, vec, cst, logNum, imap, True)

solve :: [Char] -> Int
solve s = runST (myAct s)
      
main :: IO ()
main = do
  cont <- getContents
  putStrLn $ show $ solve (takeWhile isLower cont)

