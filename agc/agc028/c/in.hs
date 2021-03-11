{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Control.Monad.State
import Data.List

main1 = do
  conts <- B.getContents
  let wstr = B.words conts
      str_n : tmp1 = wstr
      n = oneInt str_n
      str_m : tmp2 = tmp1
      m = oneInt str_m
      (str_p, tmp3) = splitAt n tmp2
      ps = map oneInt str_p
      xys = tuples2 $ map oneInt tmp3
  putStrLn $ show $ solve1 n m ps xys

main1a = do
  conts <- B.getContents
  let n:m:tmp = map oneInt (B.words conts)
      (ps, tmp2) = splitAt n tmp
      xys = tuples2 tmp2
  putStrLn $ show $ solve1 n m ps xys

oneInt = fst . fromJust . B.readInt

tuples2 :: [Int] -> [(Int,Int)]
tuples2 [] = []
tuples2 (x:y:xs) = (x,y) : tuples2 xs


ite :: Bool -> a -> a -> a
ite c t e = if c then t else e

-- ReadInput
type RIState = [B.ByteString]
type RI = State RIState

riEOF :: RI Bool
riEOF = null <$> get

rInt :: RI Int
rInt = state (\(b:bs) -> (fst (fromJust (B.readInt b)), bs))

rString :: RI String
rString = state (\(b:bs) -> (B.unpack b, bs))

rList :: RI a -> RI [a]
rList rp = do
  b <- riEOF
  if b then return [] else do
    x <- rp
    xs <- rList rp
    return (x:xs)

rListWL :: Int -> RI a -> RI [a]
rListWL !n rp =
  if n == 0 then return [] else do
      x <- rp
      xs <- rListWL (n-1) rp
      return (x:xs)

rInt2 :: RI (Int,Int)
rInt2 = do
  x <- rInt
  y <- rInt
  return (x,y)

rInt3 :: RI (Int,Int,Int)
rInt3 = (,,) <$> rInt <*> rInt <*> rInt

runRI :: RI a -> B.ByteString -> a
runRI rp cont =
  let (x, rem) = runState rp (B.words cont)
  in if null rem then x else error "remaining input"

solve2 :: (Int,Int,[(Int,Int)]) -> Int
solve2 (n,m,xys) = error ""

main2 = putStrLn . show . solve2 . runRI rp2 =<< B.getContents

rp2 = (,,) <$> rInt <*> rInt <*> rList rInt2

solve1 :: Int -> Int -> [Int] -> [(Int,Int)] -> Int
solve1 n m ps xys = test1 n m ps xys

solve3 :: (Int,Int,[Int],[(Int,Int)]) -> Int
solve3 (n,m,ps,xys) = test1 n m ps xys

main3 = putStrLn . show . solve3 . runRI rp3 =<< B.getContents

rp3 = do
  n <- rInt
  m <- rInt
  ps <- rListWL n rInt
  xys <- rList rInt2
  return (n,m,ps,xys)

fff x y = (x + y) `mod` 2

test1 :: Int -> Int -> [Int] -> [(Int,Int)] -> Int
test1 n m ps xys =
  let vp = foldl' fff 0 ps
      vxy = foldl' fff 0 $ map (\(x,y) -> fff x y) xys
  in vp + vxy

main = main1

