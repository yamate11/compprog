import Control.Monad
import Debug.Trace

{-
    Binary Search
-}

-- Finds the least i such that (lo <= i <= hi && prop i) holds
-- Precondition: prop j && j <= k ==> prop k
-- Returns: Just i  .. if such i exists
--          Nothing .. no such i, or range is empty
lower_bound :: (Int -> Bool) -> Int -> Int -> Maybe Int
lower_bound prop lo hi = (+ 1) <$> divideTF prop' (lo-1) hi
  where prop' i = (i /= lo-1) && prop i
{-
lower_bound prop lo hi
  | hi < lo || not (prop hi) = Nothing
  | prop lo = Just lo
  | otherwise = sub lo hi
  where sub lo hi | lo + 1 == hi = Just hi
                  | prop mid     = sub lo mid
                  | otherwise    = sub mid hi
          where mid = (lo + hi) `div` 2
-}

-- Finds the greatest i such that (lo <= i <= hi && prop i) holds
-- Precondition: prop j && j >= k ==> prop k
upper_bound :: (Int -> Bool) -> Int -> Int -> Maybe Int
upper_bound prop lo hi = divideTF prop' lo (hi+1)
  where prop' i = (i /= hi+1) && prop i
{-
upper_bound prop lo hi
  | hi < lo || not (prop lo) = Nothing
  | prop hi = Just hi
  | otherwise = sub lo hi
  where sub lo hi | lo + 1 == hi = Just lo
                  | prop mid     = sub mid hi
                  | otherwise    = sub lo mid
          where mid = (lo + hi) `div` 2
-}

-- Finds the point i0 where all lo <= i <= i0, prop i is True (False resp)
-- and for all i0+1 <= i <= hi, prop i is False (True resp)
-- Precondition: (prop j <=> prop k) && j <= l <= k ==> (prop j <=> prop l)
-- Returns: Just i0 ... if such i0 exists
--          Nothing ... no such i0 (i.e. all values are the same) or
--                      the range contains at most one
divideTF :: (Int -> Bool) -> Int -> Int -> Maybe Int
divideTF prop lo hi
  | hi <= lo = Nothing
  | bLo == bHi = Nothing
  | otherwise = sub lo hi
  where bLo = prop lo
        bHi = prop hi
        sub lo hi | lo + 1 == hi    = Just lo
                  | prop mid == bLo = sub mid hi
                  | otherwise       = sub lo mid
          where mid = (lo + hi) `div` 2

lower_boundM :: Monad m => (Int -> m Bool) -> Int -> Int -> m (Maybe Int)
lower_boundM prop lo hi = do
  mm <- divideTFM prop' (lo-1) hi
  return $ (+ 1) <$> mm
  where prop' i | i == lo-1 = return False
                | otherwise = prop i
{-
lower_boundM prop lo hi | hi < lo = return Nothing
lower_boundM prop lo hi = do
  b <- prop hi
  if not b then return Nothing else do
    b2 <- prop lo
    if b2 then return (Just lo) else sub lo hi
  where
  sub lo hi | lo + 1 == hi = return $ Just hi
            | otherwise = do
                let mid = (lo + hi) `div` 2
                b3 <- prop mid
                if b3 then sub lo mid else sub mid hi
-}

upper_boundM :: Monad m => (Int -> m Bool) -> Int -> Int -> m (Maybe Int)
upper_boundM prop lo hi = divideTFM prop' lo (hi+1)
  where prop' i | i == hi+1 = return False
                | otherwise = prop i
{-
upper_boundM prop lo hi | hi < lo = return Nothing
upper_boundM prop lo hi = do
  b <- prop lo
  if not b then return Nothing else do
    b2 <- prop hi
    if b2 then return (Just hi) else sub lo hi
  where
  sub lo hi | lo + 1 == hi = return $ Just lo
            | otherwise = do
                let mid = (lo + hi) `div` 2
                b3 <- prop mid
                if b3 then sub mid hi else sub lo mid
-}

divideTFM :: Monad m => (Int -> m Bool) -> Int -> Int -> m (Maybe Int)
divideTFM prop lo hi | hi <= lo = return Nothing
divideTFM prop lo hi = do
  bLo <- prop lo
  bHi <- prop hi
  if bLo == bHi then return Nothing else sub bLo lo hi
  where
  sub bLo lo hi | lo + 1 == hi = return $ Just lo
  sub bLo lo hi = do
    let mid = (lo + hi) `div` 2
    b <- prop mid
    if b == bLo then sub bLo mid hi else sub bLo lo mid





f1 i | i <= 10 = False
     | otherwise = True
f2 i | i <= 4 = True
     | otherwise = False
f3 i | i <= 7 = return False
     | otherwise = return True
f4 i | i <= 5 = return True
     | otherwise = return False

tv1 = lower_bound f1 0 12
test1 = tv1 == Just 11
tv2 = lower_bound f1 0 5
test2 = tv2 == Nothing
tv3 = lower_bound f1 15 30
test3 = tv3 == Just 15
tv4 = lower_bound f1 10 9
test4 = tv4 == Nothing
tv5 = upper_bound f2 0 12
test5 = tv5 == Just 4
tv6 = upper_bound f2 (-4) 3
test6 = tv6 == Just 3
tv7 = upper_bound f2 5 7
test7 = tv7 == Nothing
tv8 = lower_bound f2 10 9
test8 = tv8 == Nothing

driver testF prop lo hi exp label = do
  x <- testF prop lo hi
  when (x /= exp) (error ("Failed " ++ show (label)))

tv21 :: IO ()
tv21 = driver lower_boundM f3 0 20 (Just 8) "tv21"
tv22 = driver lower_boundM f3 1 3 (Nothing) "tv22"
tv23 = driver lower_boundM f3 10 15 (Just 10) "tv23"
tv24 = driver lower_boundM f3 4 3 (Nothing) "tv24"
tv25 = driver upper_boundM f4 0 20 (Just 5) "tv25"
tv26 = driver upper_boundM f4 (-4) (-1) (Just (-1)) "tv26"
tv27 = driver upper_boundM f4 20 25 (Nothing) "tv27"
tv28 = driver upper_boundM f3 4 3 (Nothing) "tv28"

alltestA =
  test1 && test2 && test3 && test4 && test5 && test6 && test7 && test8
alltestB = do
  tv21
  tv22
  tv23
  tv24
  tv25
  tv26
  tv27
  tv28
  putStrLn "pass"

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


