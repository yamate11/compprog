{-# LANGUAGE ViewPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.Map as M
import Control.Monad
import Data.Maybe

solve s t = if uniq s t && uniq t s then "Yes" else "No"

uniq s t = maybe False (const True) $ foldM op M.empty (zip s t)
  where op mp (c1,c2) = case M.lookup c1 mp of
                          Nothing -> Just (M.insert c1 c2 mp)
                          Just c0 -> if c0 == c2 then Just mp else Nothing

main = do
  conts <- B.getContents
  let [s,t] = map B.unpack $ B.words conts
  putStrLn $ solve s t
