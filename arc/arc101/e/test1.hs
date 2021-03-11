import qualified Data.Vector.Unboxed as VU

nMax = 1000

func f 0 = 1
func f 1 = 1
func f n = f (n-1) + f (n-2)

fib = func fib'

-- fib' n = lst !! n
fib' n = vec VU.! n

lst = map fib [0..nMax]

vec :: VU.Vector Int
vec = VU.fromListN (nMax+1) lst

main = do
  putStrLn $ show $ fib 10
