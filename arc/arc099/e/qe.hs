import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
import qualified Data.IntSet as IS
import qualified Data.IntMap as IM
import Debug.Trace
import Control.Monad.Trans.Maybe
import Control.Monad.Reader

bsReadInts :: B.ByteString -> [Int]
bsReadInts = map (fst . fromJust . B.readInt) . B.words

type MyMap = IM.IntMap IS.IntSet
type Env = (Int, MyMap)
type Act a = MaybeT (Reader Env) a

runAct :: Act a -> Env -> Maybe a
runAct act env = runReader (runMaybeT act) env

stopAct :: Act a
stopAct = MaybeT (return Nothing)

mkDisRel :: Int -> [[Int]] -> MyMap
mkDisRel n abs = foldr op init abs
  where
    initSet x = IS.delete x (IS.fromList [1..n])
    init = IM.fromList [(x,initSet x) | x <- [1..n]]
    op [a,b] =   IM.adjust (IS.delete a) b
               . IM.adjust (IS.delete b) a

mkOEList :: Act [Int]
mkOEList = do
  (n, _) <- ask
  mkOELSub (IS.fromList [1..n]) []

mkOELSub :: IS.IntSet -> [Int] -> Act [Int]
mkOELSub yet acc
  | IS.null yet = return acc
  | otherwise = do
      let k:_ = IS.toList yet
      (comp, done) <- mkOneComp k
      mkOELSub (IS.difference yet done) (comp:acc)
    
mkOneComp :: Int -> Act (Int, IS.IntSet)
mkOneComp k = do
  (this, that) <- mkOneCompSub [k] IS.empty IS.empty 
  return (abs(IS.size(this) - IS.size(that)), IS.union this that)

mkOneCompSub :: [Int] -> IS.IntSet -> IS.IntSet -> Act (IS.IntSet, IS.IntSet)
-- mkOneCompSub disRek ks this that
--   | trace ("mkOneCompSub " ++ show ks ++ " " ++ show this ++ show that) False = undefined
mkOneCompSub [] this that = return (this, that)
mkOneCompSub (k:ks) this that
  | IS.member k that = stopAct
  | IS.member k this = mkOneCompSub ks this that
  | otherwise        = do
      (_, disRel) <- ask
      (that', this') <- mkOneCompSub (IS.toList (disRel IM.! k))
                                     that (IS.insert k this) 
      mkOneCompSub ks this' that'

findMinimum :: [Int] -> Int
findMinimum is = IS.findMin $ IS.filter (>= 0) $ foldr op (IS.singleton 0) is
  where
    op i iset = IS.union (IS.map (+   i)  iset)
                         (IS.map (+ (-i)) iset)

countEdges :: Act Int
countEdges = do
  oddEvenList <- mkOEList
  let diff = findMinimum oddEvenList
      x = (n + diff) `div` 2
      y = n - x
  return (x*(x-1) `div` 2 + y*(y-1) `div` 2)

solve :: Int -> Int -> [[Int]] -> Int
solve n m abs =
  let disRel = mkDisRel n abs
      numE = runAct countEdges (n, disRel)
  in maybe (-1) id numE

main = do
  conts <- B.getContents
  let [n, m] : abs = map bsReadInts (B.lines conts)
      answer = solve n m abs
  putStrLn (show answer)



-- answers: 4, -1, 3, 21
test1 = solve 5 5 [[1,2],[1,3],[3,4],[3,5],[4,5]]
test2 = solve 5 1 [[1,2]]
test3 = solve 4 3 [[1,2],[1,3],[2,3]]
test4 = solve 10 39 [[7,2],[7,1],[5,6],[5,8],[9,10],[2,8],[8,7],[3,10],[10,1],[8,10],[2,3],[7,4],[3,9],[4,10],[3,4],[6,1],[6,7],[9,5],[9,7],[6,9],[9,4],[4,6],[7,5],[8,3],[2,5],[9,2],[10,7],[8,6],[8,9],[7,3],[5,3],[4,5],[6,3],[2,10],[5,10],[4,2],[6,2],[8,4],[10,6]]
