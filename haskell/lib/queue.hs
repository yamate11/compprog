-- Queue

-- FIXME: should have circle structure (with error checking)
--        so that element can be put in both side.  Currently, only
--        one side can be used for putting, though elements can be
--        extracted from both sides
-- For usage, see e.g. edpc/z/ans.hs

actionWithValue :: ST s a -> (a -> ST s b) -> ST s a
{-# INLINE actionWithValue #-}
actionWithValue act1 act2 = do
  a <- act1
  act2 a
  return a

modSTRef :: STRef s a -> (a -> a) -> ST s a
{-# INLINE modSTRef #-}
modSTRef ref f = actionWithValue (readSTRef ref) (writeSTRef ref . f)

data Queue s a = Queue {
  queVec :: VUM.MVector s a,
  queSize :: Int,
  queTop :: STRef s Int,
  queBot :: STRef s Int
}

queInit :: VUM.Unbox a => Int -> ST s (Queue s a)
{-# INLINE queInit #-}
queInit n = do
  vec <- VUM.new n
  qt <- newSTRef 0
  qb <- newSTRef 0
  return $ Queue { queVec = vec, queSize = n, queTop = qt, queBot = qb }

quePut :: (VUM.Unbox a) => Queue s a -> a -> ST s ()
{-# INLINE quePut #-}
quePut q a = modSTRef (queBot q) (+ 1) >>= flip (VUM.write (queVec q)) a

queGetT :: (VUM.Unbox a) => Queue s a -> ST s a
{-# INLINE queGetT #-}
queGetT q = modSTRef (queTop q) (+ 1) >>= VUM.read (queVec q)

queGetB :: (VUM.Unbox a) => Queue s a -> ST s a
{-# INLINE queGetB #-}
queGetB q = modSTRef (queBot q) (+ (-1)) >>= VUM.read (queVec q) . (+ (-1))
quePeekT :: (VUM.Unbox a) => Queue s a -> Int -> ST s a
{-# INLINE quePeekT #-}
quePeekT q i = readSTRef (queTop q) >>= VUM.read (queVec q) . (+ i)

quePeekB :: (VUM.Unbox a) => Queue s a -> Int -> ST s a
{-# INLINE quePeekB #-}
quePeekB q i = readSTRef (queBot q) >>= VUM.read (queVec q) . (+ (-i-1))

queLength :: Queue s a -> ST s Int
{-# INLINE queLength #-}
queLength q = (-) <$> readSTRef (queBot q) <*> readSTRef (queTop q)
