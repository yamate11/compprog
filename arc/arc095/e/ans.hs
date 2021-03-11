{-# LANGUAGE ViewPatterns #-}
{-# LANGUAGE TupleSections #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import Data.List
import qualified Data.IntMap as IM
import qualified Data.IntSet as IS
import Control.Monad
-- import Debug.Trace

trace _ a = a

type MySet = IS.IntSet

msNull = IS.null
msToList = IS.toList
msFromList = IS.fromList
msSize = IS.size
msDelete = IS.delete
msIntersection = IS.intersection

solve :: Int -> Int -> [String] -> Bool
solve h w ss = search
  where

  lenss = length ss
  ssIdcs = [0 .. lenss-1]
  msUnivY = msFromList ssIdcs
  msUnivX = msFromList [0..w-1]
  enc i j = i * lenss + j

  search
    | lenss `mod` 2 == 0 = sch0 msUnivY allPossible
    | otherwise          = or [sch1 msUnivY i i allPossible | i <- ssIdcs]

  allPossible :: [MySet]
  allPossible = map (const msUnivX) ssIdcs

  sch0 r p = trace ("sch0 " ++ show (r,p,a)) a
    where a = sch0a r p

  sch0a :: MySet -> [MySet] -> Bool
  sch0a (msToList -> [])   _        = True
  sch0a r@(msToList -> i:is) p      = or [sch1 r i j p | j <- is]
    
  sch1 remain i j possible =
    trace ("sch1 " ++ show (remain, i, j, possible, a)) a
    where a = sch1a remain i j possible

  sch1a remain i j possible =
    case IM.lookup (enc i j) mpPable0 of
      Nothing -> False
      Just thisP -> case newPossible of
        Nothing -> False
        Just newP -> sch0 newRemain newP
        where newRemain = msDelete j (msDelete i remain)
              newPossible =
                trace ("newPossible " ++ show (i,j,thisP,possible,a)) a
                where a = newPossible0
              newPossible0 :: Maybe [MySet]
              newPossible0 = mapM f (zip thisP possible)
                where
                f (x,y) | msNull k  = Nothing
                        | otherwise = Just k 
                  where k = msIntersection x y
                
  mpPable0 = trace ("mpPable = " ++ show mpPable) mpPable

  mpPable :: IM.IntMap [MySet]
  mpPable = IM.fromList $
              catMaybes [(enc i j,) <$> pable (ss !! i) (ss !! j)
                        | i <- ssIdcs, j <- [i..lenss-1]]

pable :: String -> String -> Maybe [MySet]
pable s1 s2 = cor
  where
    len = length s1
    s12 = zip s1 s2
    s12i = zip s12 [0..]
    pairs :: [((Char,Char),MySet)]
    pairs = map f $ groupBy g $ sort s12i
      where f xs = (fst (head xs), msFromList (map snd xs))
            g (p, _) (q,_) = p == q
    (same, diff) = partition (\((c1,c2),_) -> c1 == c2) pairs

    diffCor :: Maybe [(Int, MySet)]
    diffCor = liftM concat $ mapM f diff
      where f ((c1,c2), lst) = do
              lst' <- lookup (c2,c1) diff
              if msSize lst == msSize lst'
                then Just [(i, lst') | i <- msToList lst]
                else Nothing

    (eSame, oSame) = partition (\(p,is) -> (msSize is) `mod` 2 == 0) same
    eSameCor = concatMap corOthers (map snd eSame)
    sameCor = mkSameCor (len `mod` 2) oSame eSameCor

    cor = f <$> sameCor <*> diffCor
      where f sc dc = map snd (sort (sc ++ dc))

mkSameCor :: Int -> [((Char,Char),MySet)] -> [(Int,MySet)]
             -> Maybe [(Int,MySet)]
mkSameCor 0 [] eSameCor  = Just eSameCor
mkSameCor 1 [(_,olist)] eSameCor =
  Just $ [(j, olist) | j <- msToList olist] ++ eSameCor
mkSameCor _ _ _ = Nothing

corOthers :: MySet -> [(Int, MySet)]
corOthers mset = map (\x -> (x, msDelete x mset)) (msToList mset)

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> String
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_h,bs_w]:remLines1 = remLines0
      h = readBInt bs_h
      w = readBInt bs_w
      ss = map (\[x] -> B.unpack x) remLines1
      t = solve h w ss
  in if t then "YES" else "NO"

outAnswer :: String -> IO ()
outAnswer = putStrLn

main :: IO ()
main = outAnswer . tmain =<< B.getContents


----------------------------------------------------------------------

inp1 = "2 3\narc\nrac\n"
inp2 = "3 7\natcoder\nregular\ncontest\n"
inp3 = "12 12\nbimonigaloaf\nfaurwlkbleht\ndexwimqxzxbb\nlxdgyoifcxid\nydxiliocfdgx\nnfoabgilamoi\nibxbdqmzxxwe\npqirylfrcrnf\nwtehfkllbura\nyfrnpflcrirq\nwvcclwgiubrk\nlkbrwgwuiccv\n"
tv1 = tmain $ B.pack inp1
tv2 = tmain $ B.pack inp2
tv3 = tmain $ B.pack inp3
test1 = tv1 == "YES"
test2 = tv2 == "NO"
test3 = tv3 == "YES"
inp4 = "4 4\nabdc\nxywz\ndcab\nwzxy\n"
inp5 = "4 4\nabdc\nyywz\ndcab\nwzxy\n"
tv4 = tmain $ B.pack inp4
tv5 = tmain $ B.pack inp5
test4 = tv4 == "YES"
test5 = tv5 == "NO"
inp6 = "4 5\nabbbc\nccbac\ncbbba\nccabc\n"
tv6 = tmain $ B.pack inp6
test6 = tv6 == "YES"
inp7 = "4 5\nabbbc\ncccac\ncbbbb\nccacc\n"
tv7 = tmain $ B.pack inp7
test7 = tv7 == "NO"
inp8 = "5 4\nbbaa\nbbab\nbbba\naaab\naaba\n"
tv8 = tmain $ B.pack inp8
test8 = tv8 == "YES"
inp9 = "5 4\nbbaa\nbbbb\nbbba\naaab\naaba\n"
tv9 = tmain $ B.pack inp9
test9 = tv9 == "NO"
alltest = test1 && test2 && test3 && test4 && test5 && test6 && test7 && test8 && test9

