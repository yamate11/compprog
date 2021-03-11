-- This was written after reading someone else's answer.

import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
import Data.List

solve :: (Int,Int,Int,[(Int,Int,Int)]) -> Int
solve (bigN,bigW,bigC,wvcs) = answer
  where
    wvcss = groupBy (\(_,_,c) (_,_,c') -> c==c')
                $ sortOn (\(_,_,c) -> c) wvcs
    m = length wvcss
    bigC' = bigC + 1
    bigW' = bigW + 1
    enc (c,w) = c * bigW' + w
    answer = runST $ do
      dp <- VUM.replicate (bigC'*bigW') 0
      forM_ (zip (cycle [True,False]) wvcss) $ \(b, wvcs) -> do
        dpt <- VUM.new (bigC'*bigW')
        VUM.unsafeCopy dpt dp
        forM_ wvcs $ \(w0,v0,_) -> do
          forM_ [0 .. bigC-1] $ \c -> do
            forM_ [bigW, bigW-1 .. w0] $ \w -> do
              v1 <- VUM.read dpt (enc (c,w-w0))
              v2 <- VUM.read dpt (enc (c,w))
              when (v2 < v1+v0) $ VUM.write dpt (enc (c,w)) (v1+v0)
        forM_ [bigC, bigC-1 .. 1] $ \c -> do
          forM_ [0 .. bigW] $ \w -> do
            v1 <- VUM.read dp (enc (c,w))
            v2 <- VUM.read dpt (enc (c-1,w))
            when (v1 < v2) $ VUM.write dp (enc (c,w)) v2
      VUM.read dp (enc (bigC,bigW))

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

mkTuple (n:w:c:xyzs) = (n, w, c, sub xyzs)
  where sub [] = []
        sub (x:y:z:xs) = (x,y,z) : sub xs

main = putStrLn . show . solve . mkTuple . bsReadInts =<< B.getContents

