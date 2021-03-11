{-# LANGUAGE GeneralizedNewtypeDeriving #-}

newtype MyX = MyX Int
  deriving (Eq, Num, Show)

x0 :: MyX
x0 = MyX 3

s0 :: String
s0 = show x0

n0 :: Int
n0 = 5

x1 :: MyX
x1 = fromIntegral n0

foo :: MyX -> MyX -> MyX
foo x y = x + y

main = do
  putStrLn (show (foo (fromIntegral n0) 4))
  
