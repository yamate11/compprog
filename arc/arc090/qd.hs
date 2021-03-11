import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Except

type ExcST s = ExceptT () (ST s)

solve :: [[Int]] -> String
solve ([valN,_]:lrds) =
  case runST $ runExceptT $ act valN lrds of
    Left _  -> "No"
    Right _ -> "Yes"

act :: Int -> [[Int]] -> ExcST s ()
act valN lrds = do
  vec <- VM.new (valN+1)
  forM_ [1 .. valN] $ \i -> VM.write vec i (i, 0)
  mapM_ (step vec) lrds

step :: VM.MVector s (Int, Int) -> [Int] -> ExcST s ()
step vec [l,r,d] = do
  (grpL, coordL) <- reGroup vec l
  (grpR, coordR) <- reGroup vec r
  if grpL == grpR
    then unless (coordL + d == coordR) (throwError ())
    else VM.write vec grpR (grpL, coordL + d - coordR)

reGroup :: VM.MVector s (Int, Int) -> Int -> ExcST s (Int, Int)
reGroup vec x = VM.read vec x >>= sub
  where sub (grp, coord) 
          | x == grp  = return (grp, coord)
          | otherwise = do
              (newGrp, newCoord) <- reGroup vec grp
              let newXVal = (newGrp, newCoord + coord)
              VM.write vec x newXVal
              return newXVal

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

main :: IO ()
main = putStrLn . solve . map bsReadInts . B.lines =<< B.getContents
