import qualified Data.Vector as V
import Data.List
import Data.Maybe
import qualified Data.ByteString.Lazy.Char8 as B

data RecItem = RecItem {
    riStart :: Int
  , riEnd :: Int
  , riChannel :: Int
  } deriving (Show)

data EventType = ETStart | ETEnd deriving (Eq, Ord)

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
    paste ris = foldr bin [] ris
    bin ri [] = [ri]
    bin ri1 (ri2:ris)
      | riEnd ri1 == riStart ri2 = RecItem (riStart ri1) (riEnd ri2) (riChannel ri2) : ris
      | otherwise                = ri1 : ri2 : ris

countPara :: [Event] -> Int
countPara evs = f 0 0 evs
  where f cur vMax [] = vMax
        f cur vMax ((Event t ETStart) : evs) = f (cur + 1) vMax' evs
          where vMax' = if cur == vMax then vMax + 1 else vMax
        f cur vMax ((Event t ETEnd)   : evs) = f (cur - 1) vMax evs

myReadInt :: B.ByteString -> Int
myReadInt = fst . fromJust . B.readInt

line2RecItem :: B.ByteString -> RecItem
line2RecItem aLine = let [s, e, c] = map myReadInt (B.words aLine)
                     in RecItem s e c

main :: IO ()
main = do
  all <- B.getContents
  let (h:rest) = B.lines all
      [_, numC] = [myReadInt w | w <- B.words h]
      ris = map line2RecItem rest
  putStrLn $ show $ calc ris numC

