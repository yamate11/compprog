import System.Environment
import qualified Data.IntMap as IM
import Control.Monad.State

fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

right :: (Int -> Int) -> Int -> Int
right _ 0 = 1
right _ 1 = 1
right f n = f (n-1) + f (n-2)

naive_fib = right naive_fib

memo_fib n = evalState (state (body n)) IM.empty
  where
    body :: Int -> IM.IntMap Int -> (Int, IM.IntMap Int)
    body n im = case IM.lookup n im of
      Just x  -> (x, im)
      Nothing -> let y = right memo_fib n in (y, IM.insert n y im)

main = do
  a1:_ <- getArgs
  putStrLn $ show $ fib $ read a1
  
