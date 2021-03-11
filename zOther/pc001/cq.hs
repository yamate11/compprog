{-# LANGUAGE MultiWayIf #-}
import System.IO
import Debug.Trace

-- traceQ label a
--   Traces the value of a with label.
traceQ :: (Show a) => String -> a -> a
traceQ label a = trace (label ++ ": " ++ show a) a
-- traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a


main = do
  hSetBuffering stdout NoBuffering
  sn <- getLine
  let n = read sn
  s <- getStatus 0
  doIt 0 s n

doIt :: Int -> String -> Int -> IO ()
doIt _ "Vacant" _ = return ()
doIt idx gend size = do
  s <- getStatus (idx + newSize)
  if | s == "Vacant" -> return ()
     | s == hypGender gend (idx + newSize) ->
         doIt (idx + newSize) s (size - newSize)
     | otherwise -> 
         doIt idx gend newSize
  where
    newSize = size `div` 2

getStatus :: Int -> IO String
getStatus k = do
  putStrLn (show k)
  return . head . words =<< getLine

hypGender :: String -> Int -> String
hypGender g w | w `mod` 2 == 0 = g
              | w `mod` 2 == 1 = opp g
  where
    opp "Male" = "Female"
    opp "Female" = "Male"
