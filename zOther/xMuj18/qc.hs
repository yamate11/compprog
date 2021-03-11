import qualified Data.ByteString.Lazy.Char8 as B
import Data.List
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU

solve :: Int -> Int -> [B.ByteString] -> Int
solve n m bss = V.sum $ V.zipWith4 gather east south west north
  where
    vec :: V.Vector (VU.Vector Char)
    vec = V.fromList [VU.fromList (B.unpack bs) | bs <- bss]
    west :: V.Vector (VU.Vector Int)
    west = V.map (VU.postscanl' step 0) vec
    east :: V.Vector (VU.Vector Int)
    east = V.map (VU.postscanr' (flip step) 0) vec
    north :: V.Vector (VU.Vector Int)
    north = V.postscanl' (VU.zipWith step) (VU.replicate m 0) vec
    south :: V.Vector (VU.Vector Int)
    south = V.postscanr' (VU.zipWith (flip step)) (VU.replicate m 0) vec

gather :: VU.Vector Int -> VU.Vector Int -> VU.Vector Int -> VU.Vector Int
       -> Int
gather e s w n = VU.sum $ VU.zipWith4 f e s w n
  where
    f 0 _ _ _ = 0
    f e s w n = (e-1)*(n-1) + (s-1)*(e-1) + (w-1)*(s-1) + (n-1)*(w-1)

step n '.' = n + 1
step n '#' = 0

tmain :: B.ByteString -> Int
tmain cont =
  let sn:sm:ss = B.words cont
      bsReadAInt = fst . fromJust . B.readInt
  in solve (bsReadAInt sn) (bsReadAInt sm) ss

main :: IO ()
main = putStrLn . show . tmain =<< B.getContents


dc1 = B.pack "\
\3 3\n\
\..#\n\
\...\n\
\#.#\n\
\"

dc2 = B.pack "\
\2 5\n\
\.#.#.\n\
\..#..\n\
\"

dc3 = B.pack "\
\6 8\n\
\#......#\n\
\##....##\n\
\#.#..#.#\n\
\#..##..#\n\
\#......#\n\
\#......#\n\
\"

test1 = tmain dc1 == 9
test2 = tmain dc2 == 2
test3 = tmain dc3 == 182
alltest = test1 && test2 && test3
