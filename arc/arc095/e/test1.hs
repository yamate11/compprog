{-# LANGUAGE ViewPatterns #-}

import qualified Data.IntSet as IS

foo :: IS.IntSet -> Bool
foo (IS.toList -> []) = False
foo m@(IS.toList -> i:is) = IS.member (i+1) m


