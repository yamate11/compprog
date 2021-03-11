{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE OverloadedStrings #-}

import Text.Parsec hiding (State)
import Text.Parsec.String
import Text.Printf
import Data.Maybe
import Data.List
import Control.Monad
import System.Environment

{-

Usage: mkskel input_spec [output_spec]

-- Example
        mkskel "<m,n> (xs listH)" String
        mkskel "<m,n,k> (xys listV (Int,String) @k-1@) (zss listV [Int])" Int

output_spec is a type name.  Int and String are completely OK.
For other types such as [[Int]], you need to modify function
outAnswer manually.  When omitted, Int is assumed.

-- input_spec is defined as follows:

<A,B,C>           a line that consists of "component"s A, B and C
A                 same as <A>

-- component is defined as follows:

n                 an Int
(n Int)           same as above
(s String)        a String
(n listH)         a list of Integers until EOL
(n listH Int)     same as above
(s listH String)  a list of Strings until EOL
(n listV)         a list of Integers until EOF
(n listV T)       a list of Ts until EOF
    where T = Int, String, (Int,String) etc, [Int] etc.
(n listV T m)     a list of Ts with length m
(n listV T @exp@) a list of Ts with length exp


Examples:
  in each example, upper part is an input specification in the
  question page, and string after '==>' is the input_spec that
  should be given to this program.

----------------------------------------
n m s
u
v
* s is String

==> <n,m,(s String)> u v
----------------------------------------
n m
a_1 a_2 ... a_n
b_1     c_1     d_1
...
b_{m-1} c_{m-1} d_{m-1}
x
* c's are Strings

==> 
<n,m> (as listH) (bcds listV (Int,String,Int) @m-1@) x
or
<(n Int), (m Int)> (as listH Int n) (bcds listV (Int,String,Int) @m-1@) <x>
----------------------------------------
n m
a_1_1 a_1_2 ... a_1_m
a_2_1 a_2_2 ... a_2_m
...
a_n_1 a_n_2 ... a_n_m

==> <n,m> (ass listV [Int])
----------------------------------------

-}

data Comp = Comp String CCat
  deriving (Show)
data CCat = CCB CTBasic
          | CList CDir CType String
  deriving (Show)
data CDir = CHoriz | CVert
  deriving (Show)
data CType = CTB CTBasic | CTTuple [CTBasic] | CTList CTBasic
  deriving (Show)
data CTBasic = CTInt | CTString
  deriving (Show)

ccb :: Comp -> Maybe CTBasic
ccb (Comp _ (CCB x)) = Just x
ccb _ = Nothing

varName (Comp n _) = n

spec :: Parser [[Comp]]
spec = many1 comps
comps = charGS '<' *> sepBy1 comp (charGS ',') <* charGS '>'
  <|> singleton <$> comp
comp = (charGS '(' >> Comp <$> pVarName <*> category <* charGS ')')
  <|> (Comp <$> pVarName <*> return (CCB CTInt))
category = (CCB <$> bType)
  <|> (string "list" >> f <$> oneOf "HV" <* spaces <*> vTypeLen)
  where f :: Char -> (CType, String) -> CCat
        f c (t,s) = CList (dname c) t s
        dname 'H' = CHoriz
        dname 'V' = CVert
vTypeLen =
  ((,) <$> vType <*> (vLen <|> return "")) <|> return (CTB CTInt, "")
vType = CTB <$> bType
  <|> (charGS '(' >> CTTuple <$> sepBy2 bType (charGS ',') <* charGS ')')
  <|> (charGS '[' >> CTList <$> bType <* charGS ']')
vLen = charGS '@' *> many1 (noneOf "@") <* charGS '@' <|> pVarName

bType = (stringGS "Int" >> return CTInt)
  <|> (stringGS "String" >> return CTString)
pVarName = (:) <$> lower <*> many letter <* spaces

charGS :: Char -> Parser Char
charGS x = char x <* spaces
stringGS x = string x <* spaces
-- sepBy2 a b = sepBy1 a b
{-
sepBy2 a b = do
  x <- a
  b
  ys <- sepBy1 a b
  return (x:ys)
-}

sepBy2 a b = (:) <$> a <*> (b *> sepBy1 a b)

singleton x = [x]

myparse :: String -> Either ParseError [[Comp]]
myparse = parse (spaces *> spec <* eof) ""

type Gen a = Either String a

gencode :: String -> [[Comp]] -> Gen [String]
gencode outtype compss = do
  outs <- gencodeSub compss
  return $
    part1 ++ 
    ["solve :: " ++ intercalate " -> " (htypes compss) ++
          " -> " ++ outtype,
      swa ++ " = error \"notyet\""] ++
    part2 outtype ++ map ("      " ++) outs ++ ["  in " ++ swa, ""] ++
    genOutAnswer outtype ++ part3
  where 
    swa = "solve " ++ (intercalate " " (concatMap (map varName) compss))

    htypes compss = concatMap (map f) compss
      where f (Comp _ (CCB tp)) = g tp
            f (Comp _ (CList _ (CTB tp) _)) = "[" ++ g tp ++ "]"
            f (Comp _ (CList _ (CTTuple tps) _)) =
              "[(" ++ intercalate "," (map g tps) ++ ")]"
            f (Comp _ (CList _ (CTList tp) _)) = "[[" ++ g tp ++ "]]"
            g CTInt = "Int"
            g CTString = "String"

gencodeSub :: [[Comp]] -> Gen [String]
gencodeSub compss = concat <$> (zipWithM f [1..] compss)
  where
    f i [comp] = gencodeLine i [comp]
    f i comps = case filter (not . isJust . ccb) comps of
      _:_:_ -> Left $ printf "listH and listV should be an only element of a line, but [%s] are defined in a line." (intercalate "," (map varName comps))
      _ -> gencodeLine i comps

gencodeLine :: Int -> [Comp] -> Gen [String]

gencodeLine i comps@(Comp _ (CCB _) : _) =
  return $ extALine i ("[" ++ ccblist ++ "]") : map subccb comps
  where
    ccblist = intercalate "," (map (("bs_" ++) . varName) comps)
    subccb (Comp vn (CCB tp)) = printf "%s = %s bs_%s" vn (cvtccb tp) vn

gencodeLine i [Comp vname (CList CHoriz ct len)] 
  | len /= "" = Left $ printf "Length of listH '%s' should be empty." vname
  | otherwise = case ct of
      CTB tp -> return $ [extALine i pat,
                          printf "%s = map %s %s" vname (cvtccb tp) pat]
      _ -> Left $ printf "Type of listH '%s' should be Int or String." vname
  where pat = "line" ++ show i

gencodeLine i [Comp vname (CList CVert ct len)] = return lines
  where
    lines
      | len /= "" = [printf "(lines%d, remLines%d) = splitAt (%s) remLines%d"
                            i i len (i-1),
                     printf "%s = map (%s) lines%d" vname cvtline i]
      | otherwise = [printf "%s = map (%s) remLines%d" vname cvtline (i-1)]
    cvtline = case ct of
      CTB tp -> printf "\\[x] -> %s x" (cvtccb tp)
      CTTuple tps -> printf "\\[%s] -> (%s)"
                        (intercalate "," names)
                        (intercalate "," (zipWith f (map cvtccb tps) names))
        where
          names = map (("x" ++) . show) [1 .. (length tps)] 
          f op nm = op ++ " " ++ nm
      CTList tp -> "map " ++ cvtccb tp

cvtccb :: CTBasic -> String
cvtccb CTInt = "readBInt"
cvtccb CTString = "B.unpack"

extALine i pat = printf "%s:remLines%d = remLines%d" pat i (i-1)

testgen :: String -> String -> IO ()
testgen s outtype =
  case myparse s of
    Left e -> error (show e)
    Right p -> case gencode outtype p of
                 Left e' -> error e'
                 Right ss -> mapM_ putStrLn ss

main = do
  args <- getArgs
  case args of
    [arg1] -> testgen arg1 "Int"
    [arg1, arg2] -> testgen arg1 arg2
    _ -> error "Usage: mkskel input_spec [output_spec]\n  For details, refer to comments."

part1 :: [String]
part1 = [
  "{-# LANGUAGE BangPatterns #-}",
  "{-# LANGUAGE ScopedTypeVariables #-}",
  "{-# LANGUAGE TupleSections #-}",
  "{-# LANGUAGE RankNTypes #-}",
  "import qualified Data.ByteString.Lazy.Char8 as B",
  "import Data.Maybe",
  "-- import Data.List",
  "-- import qualified Data.Vector.Unboxed as VU",
  "-- import qualified Data.Vector.Unboxed.Mutable as VUM",
  "-- import Control.Monad",
  "-- import Control.Monad.ST",
  "-- import Debug.Trace",
  "-- trace _ = id",
  ""
  ]
part2 :: String -> [String]
part2 s_outtype = [
  "",
  "readBInt :: B.ByteString -> Int",
  "readBInt = fst . fromJust . B.readInt",
  "",
  "tmain :: B.ByteString -> " ++ s_outtype,
  "tmain cont =",
  "  let remLines0 = map B.words (B.lines cont)"
  ]
part3 :: [String]
part3 = [
  "",
  "main :: IO ()",
  "main = outAnswer . tmain =<< B.getContents",
  ""
  ]
genOutAnswer :: String -> [String]
genOutAnswer outtype
  | outtype == "Int" = oaDecl outtype : ["outAnswer = putStrLn . show"]
  | outtype == "String" = oaDecl outtype : ["outAnswer = putStrLn"]
  | otherwise = oaDecl outtype :
                ["outAnswer x = error \"outAnswer: not implemented.\""]
oaDecl outtype = "outAnswer :: " ++ outtype ++ " -> IO ()"


{- sample output

{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [Int] -> [String] -> [(Int,String,Int)] -> [[Int]] -> Int
solve m n as bs cs ds = error ""

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_m,bs_n]:remLines1 = remLines0
      m = readBInt bs_m
      n = readBInt bs_n
      line2:remLines2 = remLines1
      as = map readBInt line2
      (lines3, remLines3) = splitAt (n) remLines2
      bs = map (\[x] -> B.unpack x) lines3
      (lines4, remLines4) = splitAt (n-1) remLines3
      cs = map (\[x1,x2,x3] -> (readBInt x1,B.unpack x2,readBInt x3)) lines4
      ds = map (map readBInt) remLines4
  in solve m n as bs cs ds

main :: IO ()
main = putStrLn . show . tmain =<< B.getContents

-}
        
