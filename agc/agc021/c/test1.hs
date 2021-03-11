n = 2^22

foo x = [1..n-x+x] 
-- foo x = [1..n] 

func = sum [(i-mean) * (i-mean) | i <- foo2]
  where foo2 = foo 2
        foo3 = foo 3
        foo4 = foo 4
        mean = (sum foo4) `div` (length foo3)

func2 = sum [(i-mean) * (i-mean) | i <- [1..n]]
  where mean = (sum [1..n]) `div` (length [1..n])

func3 = sum [(i-mean) * (i-mean) | i <- foo]
  where mean = (sum foo) `div` (length foo)
        foo = [1..n]

main = do
  putStrLn $ show $ func3

  
