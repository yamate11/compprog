{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Control.Monad
import System.Environment
import Data.List

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

act :: Int -> [Int] -> IO Int

act 0 xs = return $ sum (map f9 xs)

act 1 xs = sum <$> mapM mf9 xs
  
act 2 xs = sumM (map mf9 xs)

f9 x = x+1
mf9 x = return (x+1)

sumM :: (Monad m, Num a) => [m a] -> m a
sumM = sub 0 
  where sub !acc []       = return acc
        sub !acc (mx:mxs) = do
          x <- mx
          sub (acc+x) mxs

main = do
  [arg1, arg2] <- getArgs
  let sel = read arg1 :: Int
      n = read arg2 :: Int
  s <- act sel [1..n]
  putStrLn $ show s
