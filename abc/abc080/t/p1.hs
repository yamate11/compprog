import System.Environment
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List

type IFold = (Int -> Int -> Int) -> Int -> [Int] -> Int

rStr :: IFold -> IO Int
rStr f = 
  getContents >>=
  return . f (+) 0 . map read . lines

rBS :: IFold -> IO Int
rBS f =
  B.getContents >>=
  return . f (+) 0 . map (fst . fromJust. B.readInt) . B.lines

body :: [Int] -> IO Int
body (1:_) = rStr foldr
body (2:_) = rStr foldl'
body (3:_) = rBS foldr
body (4:_) = rBS foldl'
body _ = error "Usage: p1 arg, where arg is either 1, 2, 3 or 4" >> return 0

main :: IO ()
main =  getArgs >>= body . map read >>= putStrLn . show
    
