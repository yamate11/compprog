import qualified Data.Vector.Unboxed as VU
import System.Environment

foo :: Int -> VU.Vector Int
foo 0 = VU.fromList []
foo n = VU.cons n (foo (n-1))

bar :: Int -> [Int]
bar 0 = []
bar n = n : bar (n-1)

main = do
  [n] <- getArgs
  putStrLn $ show $ (foo (read n)) VU.! 10
  
