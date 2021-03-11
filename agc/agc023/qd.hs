import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntMap as IM

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

type XP = (Int, Int)

solve :: Int -> Int -> [XP] -> Int
solve n s xps =
  error ""
  where
    (xx0, initRight) = span ((< s) . head) xps
    initLeft = reverse xx0

naive :: Int -> [XP] -> [XP] -> ([Int], [Int])
naive t [] right = ([], map (\(x,_) -> x-t) right)
naive t left [] = (map (\(x,_) -> t-x) left)
naive t left@((xl,pl):leftT) right@((xr,pr):rightT) =
  let (leftL, rightL) = naive xl leftT right
      (leftR, rightR) = naive xr left rightT
      evLeft  = hop (t-xl) (0:leftL, rightL)
      evRight = hop (xr-t) (leftR, 0:rightR)
  in if winLeft evLeft evRight left right then evLeft else evRight
  where
    hop tt (left, right) = (map (+ tt) left, map (+ tt) right)
    winLeft (l0,r0) (l1,r1) xpL xpR = score l0 l1 xpL + score r0 r1 xpR >= 0
    score ts0 ts1 xps

  


main :: IO ()
main = do
  conts <- B.getContents
  let [n, s] : xps = map bsReadInts (B.lines conts)
  putStrLn $ show $ solve n s (map (\[a,b] -> (a,b)) xps)
