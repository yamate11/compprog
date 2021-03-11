import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Control.Monad
import Control.Monad.ST
import qualified Data.IntSet as I

solve0 n m s abs = if solve n m s abs then "Yes" else "No"

solve :: Int -> Int -> String -> [[Int]] -> Bool
solve n m s abs = runST $ do
  label <- VUM.new (n+1)
  forM (zip [1..] s) $ \(i,c) -> do
    VUM.write label i c

  nbrA <- VM.replicate (n+1) I.empty
  nbrB <- VM.replicate (n+1) I.empty
  forM abs $ \[x,y] -> do
    labX <- VUM.read label x
    labY <- VUM.read label y
    if labX == 'A' then VM.modify nbrA (I.insert x) y
                   else VM.modify nbrB (I.insert x) y
    if labY == 'A' then VM.modify nbrA (I.insert y) x
                   else VM.modify nbrB (I.insert y) x
  repRemove nbrA nbrB label
  remained <- forM [1..n] $ \i -> do
    i_nbrA <- VM.read nbrA i
    return (not (I.null i_nbrA))
  return (or remained)

  where
    repRemove nbrA nbrB label = do
      lst_chgd <- forM [1..n] $ \i -> do
        i_nbrA <- VM.read nbrA i
        i_nbrB <- VM.read nbrB i
        if ((I.null i_nbrA) `xor` (I.null i_nbrB)) then do
          remove i i_nbrA i_nbrB
          return True
          else return False
      if or lst_chgd then repRemove nbrA nbrB label
        else return ()

      where
        remove i i_nbrA i_nbrB = do
          VM.write nbrA i I.empty
          VM.write nbrB i I.empty
          let i_nbr = if I.null i_nbrA then i_nbrB else i_nbrA
          lab <- VUM.read label i
          let nbr = if lab == 'A' then nbrA else nbrB
          forM_ (I.toList i_nbr) $ \j -> do
            VM.modify nbr (I.delete i) j
            j_nbrA <- VM.read nbrA j
            j_nbrB <- VM.read nbrB j
            if ((I.null j_nbrA) `xor` (I.null j_nbrB)) then do
              remove j j_nbrA j_nbrB
              else return ()

xor b1 b2 = (b1 && not b2) || ((not b1) && b2)

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

tmain :: B.ByteString -> String
tmain cont =
  let line1 : line2 : lines = B.lines cont
      [n,m] = bsReadInts line1
      [s] = B.words line2
      abs = map bsReadInts lines
  in solve0 n m (B.unpack s) abs

main = putStrLn . tmain =<< B.getContents

inp1 = "\
\2 3\n\
\AB\n\
\1 1\n\
\1 2\n\
\2 2\n\
\"

inp2 = "\
\4 3\n\
\ABAB\n\
\1 2\n\
\2 3\n\
\3 1\n\
\"

inp3 = "\
\13 23\n\
\ABAAAABBBBAAB\n\
\7 1\n\
\10 6\n\
\1 11\n\
\2 10\n\
\2 8\n\
\2 11\n\
\11 12\n\
\8 3\n\
\7 12\n\
\11 2\n\
\13 13\n\
\11 9\n\
\4 1\n\
\9 7\n\
\9 6\n\
\8 13\n\
\8 6\n\
\4 10\n\
\8 7\n\
\4 3\n\
\2 1\n\
\8 12\n\
\6 9\n\
\"

inp4 = "\
\13 17\n\
\BBABBBAABABBA\n\
\7 1\n\
\7 9\n\
\11 12\n\
\3 9\n\
\11 9\n\
\2 1\n\
\11 5\n\
\12 11\n\
\10 8\n\
\1 11\n\
\1 8\n\
\7 7\n\
\9 10\n\
\8 8\n\
\8 12\n\
\6 2\n\
\13 11\n\
\"

tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
tv4 = tmain $ B.pack inp4

test1 = tv1 == "Yes"
test2 = tv2 == "No"
test3 = tv3 == "Yes"
test4 = tv4 == "No"

alltest = test1 && test2 && test3 && test4
