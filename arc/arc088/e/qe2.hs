import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Data.Bits
import qualified Data.Map.Strict as M
import Data.Sequence hiding (length, splitAt, zip, scanl, replicate)
import Data.Char
import Debug.Trace

traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

lsbAdd :: Int -> Int
lsbAdd k = k + (k .&. (-k))

lsbOff :: Int -> Int
lsbOff k = k .&. complement (k .&. (-k))

bitSum :: VM.MVector s Int -> Int -> ST s Int
bitSum vec n = 
  foldM g 0 $ takeWhile (> 0) $ iterate lsbOff n
  where g sum i = (+ sum) <$> (VM.read vec (i - 1))

bitUpd :: Int -> VM.MVector s Int -> Int -> Int -> ST s ()
bitUpd nMax vec n diff = forM_ indices act
  where indices = takeWhile (<= nMax) (iterate lsbAdd (n + 1))
        act k = VM.modify vec (+ diff) (k - 1)

type MyMap = M.Map Char (Seq Int)

myAct :: [Char] -> ST s Int
myAct s = do
  let num = length s
      size = bit $ ceiling $ logBase 2 $ fromIntegral num
      imapInit = foldr f M.empty (zip [0..] s)
        where f (i, c) m = M.alter f' c m
                where f' Nothing   = Just $ i <| empty
                      f' (Just is) = Just $ i <| is
  vec <- VM.new num
  forM_ (zip [0..] s) $ \(i, c) -> VM.write vec i c
  bit <- VM.replicate size 0
  (result, _, _, _, _, _) <-
    foldM actBody (0, vec, bit, (traceQ "size" size), imapInit, False)
                  [num-1, num-2 .. 0]
  return result

type MyAB s = (Int, VM.MVector s Char, VM.MVector s Int, Int, MyMap, Bool)
actBody :: MyAB s -> Int -> ST s (MyAB s)
actBody ab@(-1, _, _, _, _, _) _ = return ab
actBody (acc, vec, bit, size, imap, exOdd) i = do
  c <- VM.read vec i
  if (traceQ "c" c) == 'X' then return (acc, vec, bit, size, imap, exOdd)
    else do
    VM.write vec i 'X'
    let is :> _ = viewr (imap M.! c)   -- the last element must be i
    case viewl is of    
      j :< body -> do
        VM.write vec j 'X'
        count <- bitSum bit (traceQ "j" j)
        bitUpd size bit j 1
        let newAcc = acc + (j - (traceQ "count" count)) + (if exOdd then 1 else 0)
            newImap = M.update (const (Just body)) c imap
        return ((traceQ "newAcc" newAcc), vec, bit, size, newImap, exOdd)
      _ -> if exOdd then return (-1, vec, bit, size, imap, exOdd)
           else return (acc, vec, bit, size, imap, True)

solve :: [Char] -> Int
solve s = runST (myAct s)
      
main :: IO ()
main = do
  cont <- getContents
  putStrLn $ show $ solve (takeWhile isLower cont)
