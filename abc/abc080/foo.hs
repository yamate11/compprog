import Data.List

x :: [Int]
x = [0 .. 50000000]

func1 :: [a] -> Int
func1 xs = foldr (\x y -> y + 1) 0 xs

func2 :: [a] -> Int
func2 xs = foldl (\x y -> x + 1) 0 xs

func3 :: [a] -> Int
func3 xs = foldl' (\x y -> x + 1) 0 xs


n = 100000000

main :: IO ()
main = do
  putStrLn $ show $ func3 [1 .. n]
  
