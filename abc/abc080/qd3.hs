import Data.List

data RecItem = RecItem {
    riStart :: Int
  , riEnd :: Int
  , riChannel :: Int
  } deriving (Show)

data EventType = ETStart | ETEnd
                           deriving (Eq, Ord)

data Event = Event {
    evTime :: Int
  , evType :: EventType
} deriving (Eq, Ord)

calc :: [RecItem] -> Int -> Int
calc ris numC =
  countPara $ sort $ concat [eventList ris c | c <- [1 .. numC]]

eventList :: [RecItem] -> Int -> [Event]
eventList ris c = 
  concat [[Event s ETStart, Event e ETEnd] |
          RecItem s e _ <- paste $ sortOn riStart $ filter ffilt ris]
  where 
    ffilt (RecItem s e c') = c == c'
    paste = paste2 []
    paste2 acc [] = reverse acc
    paste2 [] (ri : ris) = paste2 [ri] ris
    paste2 acc@((RecItem sA eA c) : risA) (riB@(RecItem sB eB _) : ris)
      | eA == sB  = paste2 ((RecItem sA eB c) : risA) ris
      | otherwise = paste2 (riB : acc) ris

--    paste = foldr gen []
--    gen ri [] = [ri]
--    gen ri1@(RecItem s1 e1 _) ris2@((RecItem s2 e2 c) : ris)
--      | e1 == s2  = RecItem s1 e2 c : ris
--      | otherwise = ri1 : ris2

countPara :: [Event] -> Int
countPara evs = f 0 0 evs
  where f cur vMax [] = vMax
        f cur vMax ((Event t ETStart) : evs) = f (cur + 1) vMax' evs
          where vMax' = if cur == vMax then vMax + 1 else vMax
        f cur vMax ((Event t ETEnd)   : evs) = f (cur - 1) vMax evs

main :: IO ()
main = do
  x <- getLine
  let [numRI, numC] = [read w | w <- words x]
  ris <- readData numRI
  putStrLn $ show $ calc ris numC

readData :: Int -> IO [RecItem]
readData n = do
  ris <- f n []
  return $ reverse ris
  where
    f :: Int -> [RecItem] -> IO [RecItem]
    f n acc | n == 0 = return acc
            | otherwise = do
                    x <- getLine
                    let [s, e, c] = [read w | w <- words x]
                    f (n - 1) (RecItem s e c : acc)
