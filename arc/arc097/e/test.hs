

tr :: (Int -> Int) -> (Int -> Int)
tr f 0 = 1
tr f 1 = 1
tr f x = f (x-1) + f (x-2)

trM :: (Int -> m Int) -> (Int -> m Int)
tr f 0 = return 1
tr f 1 = return 1
tr f x = do
  y1 <- f (x-1)
  y2 <- f (x-2)
  return y1 + y2

tr f x = liftM2 (+) (f (x-1)) (f (x-2))


[write 0 1]
[write 1 1]
[g 0 1]
[g 1 2]
[g 2 3]

g .. 
