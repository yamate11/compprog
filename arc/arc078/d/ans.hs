{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE RankNTypes #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace
-- trace _ = id

solve :: Int -> [(Int,Int)] -> String
solve bN lstAB | fNodes > sNodes = "Fennec"
               | otherwise       = "Snuke"
  where
  tree = rootedTree lstAB 1 (bN+1)
  path = rtPath tree 1 (bN+1) bN 1
  top = path VU.! (((VU.length path) - 2) `div` 2)
  sNodes = countNodes top
  fNodes = bN - sNodes
  countNodes i = 1 + sum (map countNodes (rtChildren tree i))

-------------------------------------------------------------------------------
-- Rooted Tree

type RTree = Int -> (Int, [Int])

{-
 If we set
    let tree = rootedTree xys root vSize
 then
    tree :: Int -> (Int, [Int])
    tree i = (parent of i, children of i)
 Note that:
   - vSize should be maxIndex+1
   - node indices should be nonnegative
   - (-1) is set as the "parent of root"
-}

rootedTree :: [(Int,Int)] -> Int -> Int -> RTree
rootedTree xys root vSize i = v V.! i where
  v = V.create $ ((,) <$> VM.replicate vSize [] <*> VM.new vSize) >>= act
  act (vec,vecRC) = do
    forM_ xys $ \(x,y) -> do
      VM.modify vec (x:) y
      VM.modify vec (y:) x
    rootChildren <- VM.read vec root
    setRC (-1) root
    return vecRC
    where
    setRC parent idx = do
      cs <- filter (/= parent) <$> VM.read vec idx
      VM.write vecRC idx (parent, cs)
      mapM_ (setRC idx) cs

rtParent :: RTree -> Int -> Int
rtParent tree node = fst (tree node)

rtChildren :: RTree -> Int -> [Int]
rtChildren tree node = snd (tree node)

-- (rtPath tree root x y) is the path from x to y
rtPath :: RTree -> Int -> Int -> Int -> Int -> VU.Vector Int
rtPath tree root vSize x y = VU.create $ do
  vecX <- VUM.new vSize
  vecY <- VUM.new vSize
  nx <- pathRoot 0 x vecX
  ny <- pathRoot 0 y vecY
  (mx, my) <- branch vecX vecY (nx,ny)
  forM_ [1..my] $ \i -> VUM.read vecY (my-i) >>= VUM.write vecX (mx+i)
  return $ VUM.unsafeSlice 0 (mx+my+1) vecX
  where
    pathRoot i x vec = do
      VUM.write vec i x
      if x == root then return i else pathRoot (i+1) (rtParent tree x) vec
    branch vecX vecY (nx,ny) | nx < 0 || ny < 0 = return (nx+1, ny+1)
    branch vecX vecY (nx,ny) = do
      p <- VUM.read vecX nx
      q <- VUM.read vecY ny
      if p == q then branch vecX vecY (nx-1, ny-1) else return (nx+1, ny+1)
    

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_bN]:remLines1 = remLines0
      bN = readBInt bs_bN
      lstAB = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve bN lstAB

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


-------------------------------------------------------------------------------

inp1 = "7\n3 6\n1 2\n3 1\n7 4\n5 7\n1 4\n"
inp2 = "4\n1 4\n4 2\n2 3\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
test1 = tv1 == "Fennec"
test2 = tv2 == "Snuke"
alltest = test1 && test2

