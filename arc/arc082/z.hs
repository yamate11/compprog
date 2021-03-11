fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n-1)

z = (fact 200) `div` (fact 100) * (fact 100)
