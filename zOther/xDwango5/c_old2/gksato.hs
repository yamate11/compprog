{-# LANGUAGE BangPatterns #-}

import qualified Data.Vector.Unboxed as VU
import qualified Data.ByteString.Char8 as BS
import Control.Monad

data Counter = Counter { cD :: {-# UNPACK #-} !Int,
                         cM :: {-# UNPACK #-} !Int,
                         cDM :: {-# UNPACK #-} !Int,
                         cAcc :: {-# UNPACK #-} !Int }

query :: VU.Vector Char -> Int -> Int
query vec k = cAcc $ VU.foldl' update cInit padded
  where
    cInit = Counter 0 0 0 0
    padded = VU.zip vec $ VU.replicate (k-1) 'X' VU.++ vec
    update c0 (now,old) = c2
      where
        c1 = case now of
          'D' -> c0 { cD = cD c0 + 1 }
          'M' -> c0 { cM = cM c0 + 1, cDM = cDM c0 + cD c0 }
          'C' -> c0 { cAcc = cAcc c0 + cDM c0 }
          _   -> c0
        c2 = case old of
          'D' -> c1 { cD = cD c1 - 1, cDM = cDM c1 - cM c1 }
          'M' -> c1 { cM = cM c1 - 1 }
          _   -> c1

main :: IO ()
main = do
  n <- read <$> getLine
  vec <- VU.unfoldrN n BS.uncons <$> BS.getLine
  q <- read <$> getLine
  ks <- VU.unfoldrN q (BS.readInt . BS.dropWhile (==' ')) <$> BS.getLine
  VU.mapM_ (putStrLn . show . query vec) ks
