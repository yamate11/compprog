-- import qualified Data.Vector.Mutable as VM
-- import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad.ST
import Control.Monad.Primitive


getTails :: [a] -> [[a]]
getTails [] = []
getTails x@(_:as) = x : getTails as

cards :: VU.Vector Int
cards = VU.fromList [-1,5,2]

lastIdx = VU.length cards

expt :: VUM.MVector -> VUM.MVector -> Int -> Int -> ST s Int
expt mineExpt yoursExpt yourVal   = do
  vec <- VUM.new n
  expt vec cards True w

  where
--    expt :: a -> [(Int, Int)] -> Bool -> Int -> ST s Int
    expt _ [(_, v)] sw w = return $ abs (v - w)
    expt vec ((i, v) : cards) sw w = do
      p <- VUM.read vec i
      case (if sw then fst else snd) p of
        Just t -> return t
        Nothing -> do
          ts <- sequence [expt cs' (not sw) v | cs' <- getTails cards]
          let t = (if sw then minimum else maximum) ts
          VUM.modify vec f i
          return t
            where f (x0, y0) = if sw then (Just t, y0) else (x0, Just t)



{-
expX :: Int -> Int -> Int
expX i y = case i of
  n -> abs ((a ! n) - y)
  _ -> minimum [expY j (a ! i) | j <- [i + 1 .. n]]

expY :: Int -> Int -> Int
expY i x = case i of
  n -> abs ((a ! n) - x)
  _ -> maximum [expX j (a ! i) | j <- [i + 1 .. n]]
-}


main = do
  putStrLn "hello"
