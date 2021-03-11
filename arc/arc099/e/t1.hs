import Data.Functor.Identity
import Control.Monad.Trans.Class
import Control.Monad.Trans.Maybe
import Control.Monad.Reader

type Env = (Int, String)

type Act a = MaybeT (Reader Env) a

runAct :: Act a -> Env -> Maybe a
runAct act env = runReader (runMaybeT act) env

stopAct :: Act a
stopAct = MaybeT (return Nothing)
-- MaybeT :: m (Maybe a) -> MaybeT m a

act1 :: Int -> Act Int
act1 x = do
  (e, _) <- ask
  if x < e then stopAct
    else return (x + e)

act2 :: Int -> Act Int
act2 x = do
  if x >= 100 then stopAct
    else return 0

act3 :: Int -> Act Int
act3 x = do
  y1 <- act1 x
  y2 <- act2 x
  return (y1 + y2)

main = do
  case runAct (act3 200) (10, "Hello") of
    Nothing -> putStrLn "Nothing"
    Just x -> putStrLn ("Int ... " ++ show x)

{-
  case runAct (10, "Hello") act1 of
    Nothing -> putStrLn "Nothing"
    Just x -> putStrLn ("Int ... " ++ show x)
-}
  
