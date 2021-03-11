
-- Logarithm functions in Haskell is defined in class Floating.
--   log :: Floating a => a -> a
--   logBase :: Floating a => a -> a -> a
x :: Double
x = 10.0
y :: Double
y = 20.0
log_of_x_with_base_y = logBase y x

-- You need fromIntegral to apply it to integer.
n :: Int
n = 10
k :: Int
k = 2
log_2_10 = logBase (fromIntegral k) (fromIntegral n)
-- Literals are OK:
log_2_10' = logBase 2 10

-- E.g., the number of digits of integer n written with base k
--   Experiments show that the performance does not very much differ
--   from manually defined integer operation.
num_digits :: Int -> Int -> Int
num_digits k n = ceiling (logBase (fromIntegral k) ((fromIntegral n) + 0.5))

-- E.g., the power operation for integers
power_int :: Int -> Int -> Int
power_int x y = round ((fromIntegral x) ** (fromIntegral y))
