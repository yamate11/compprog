import qualified Data.Vector.Unboxed.Mutable as VM
import Control.Monad
import Control.Monad.ST
import Control.Monad.Except

-- Sample Usage of ExceptT Monad Transformer
--     with ST monad

type MyMonad s = ExceptT String (ST s)

act :: Int -> MyMonad s Int
act n = do
  vec <- VM.new 100
  when (n >= 100) (throwError "index out of range")
  VM.write vec n n
  return n

main :: IO ()
main = do
  let st_act :: ST s (Either String Int)
      st_act = runExceptT (act 1000)
      x :: Either String Int
      x = runST st_act
      f :: Either String Int -> String
      f (Left msg) = msg
      f (Right val) = show val
  putStrLn (f x)
  
