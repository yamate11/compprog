import Control.Monad

g :: Int -> IO Bool
g x = do
  putStrLn $ "g " ++ show x
  return $ x >= 10

f1 :: Int -> Int -> IO Bool
f1 x1 x2 = do
  b1 <- g x1
  b2 <- g x2
  return $ b1 && b2

f2 :: Int -> Int -> IO Bool
f2 x1 x2 = (&&) <$> g x1 <*> g x2

f3 :: Int -> Int -> IO Bool
f3 x1 x2 = liftM2 (&&) (g x1) (g x2)

f4 :: Int -> Int -> IO Bool
f4 x1 x2 = (g x1) &&& (g x2)

ite3 :: a -> a -> Bool -> a
ite3 t e c = if c then t else e

(&&&) :: Monad m => m Bool -> m Bool -> m Bool
ma &&& mb = ma >>= ite3 mb (return False)

andM :: Monad m => [m Bool] -> m Bool
andM = foldr (&&&) (return True)

(|||) :: Monad m => m Bool -> m Bool -> m Bool
ma ||| mb = ma >>= ite3 (return True) mb

orM :: Monad m => [m Bool] -> m Bool
orM = foldr (|||) (return False)

allM :: Monad m => (a -> m Bool) -> [a] -> m Bool
allM act = andM . map act

anyM :: Monad m => (a -> m Bool) -> [a] -> m Bool
anyM act = orM . map act
  
main = do
  putStrLn "1"
  putStrLn . show =<< f1 5 10
  putStrLn "2"
  putStrLn . show =<< f2 5 10
  putStrLn "3"
  putStrLn . show =<< f3 5 10
  putStrLn "4"
  putStrLn . show =<< f4 5 10
  putStrLn "5"
  putStrLn . show =<< allM g [11, 10, 9, 8]
  putStrLn "6"
  putStrLn . show =<< anyM g [8, 9, 10, 11]
  
