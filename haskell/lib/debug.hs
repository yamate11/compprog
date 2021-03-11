import Debug.Trace

-- traceQ label a
--   Traces the value of a with label.
traceQ :: (Show a) => String -> a -> a
-- traceQ label a = trace (label ++ ": " ++ show a) a
traceQ _ a = a

traceZ :: String -> a -> a
-- traceZ = trace
traceZ _ a = a

{--
  an idiom for printf-debug
  foo x y z
    | trace ("foo " ++ show x ++ show y ++ show z) False = undefined
--}

traceL :: Show a => String -> a -> b -> b
traceL label showObj val = trace (label ++ " " ++ show showObj) val

traceLM :: (Monad m, Show a) => String -> (b -> a) -> m b -> m b
traceLM label showFn act = do
  aaa <- act
  traceL label (showFn aaa) (return ())
  return aaa


