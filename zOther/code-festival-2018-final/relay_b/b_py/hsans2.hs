import Data.List
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

solve s gx gy = any prop seq
  where
    gxA = abs gx
    gyA = abs gy
    prop cnt = or [(x,y) == (gxA,gyA) || (x,y) == (gyA,gxA)
                  | (x,y) <- map pabs cnt]
    seq = scanl f [(0,0), (0,0), (0,0)] s
      where
        f [(wx,yz), (wy,xz), (wz,xy)] 'W' = [(wx+1,yz), (wy+1,xz), (wz+1,xy)]
        f [(wx,yz), (wy,xz), (wz,xy)] 'X' = [(wx-1,yz), (wy,xz+1), (wz,xy+1)]
        f [(wx,yz), (wy,xz), (wz,xy)] 'Y' = [(wx,yz+1), (wy-1,xz), (wz,xy-1)]
        f [(wx,yz), (wy,xz), (wz,xy)] 'Z' = [(wx,yz-1), (wy,xz-1), (wz-1,xy)]

pabs (x, y) = (abs x, abs y)

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

