import Data.List
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.Map as M

solve s gx gy = any reach (permutations [[1,0], [-1,0], [0,1], [0,-1]])
  where
  reach perm = any (== [gx,gy]) (scanl move [0,0] s)
    where
    move pt c = zipWith (+) pt (mp M.! c) 
    mp = M.fromDistinctAscList (zip "WXYZ" perm)

bsReadInt = fst . fromJust . B.readInt

main = do
  cont <- B.getContents
  let [s, w1, w2] = B.words cont
      b = solve (B.unpack s) (bsReadInt w1) (bsReadInt w2)
  putStrLn (if b then "Yes" else "No")

t1 = solve "WWYWYWWW" 3 0 == True
t2 = solve "YYYYW" (-1) (-3) == False
t3 = solve "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" 50 0 == True
t4 = solve "WWWWXXXYYZ" 2 2 == True
t5 = solve "WWWWXXXYYZ" 2 (-2) == True
t6 = solve "WWWWXXXYYZ" (-2) 2 == True
t7 = solve "WWWWXXXYYZ" (-2) (-2) == True
t8 = solve "WWWWYYYXXZ" 2 2 == True
t9 = solve "WWWWZZZXXY" 2 2 == True
t10 = solve "YYYYWWWZZX" 2 2 == True

atest = [t1,t2,t3,t4,t5,t6,t7,t8,t9,t10]
alltest = and atest

