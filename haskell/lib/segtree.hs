-- segment tree

-- for usage, see e.g. ab066r077/e/ans.hs

-------------------------------------------------------------------------------
data SegTree s a = SegTree {
  sgtVec :: VUM.MVector s a,
  sgtSize :: Int
}
data SgtFT = SgtIn | SgtOut | SgtOther deriving(Show)
type SgtMF   s a b c =
  c ->             -- parameter
  SgtFT ->         -- type (In/Out/Other)
  (c -> ST s b) -> -- left recursive function
  (c -> ST s b) -> -- right recursive function
  SegTree s a ->   -- segment tree
  Int ->           -- node
  Int ->           -- left bound for the node (incl)
  Int ->           -- right bound for the node (excl)
  ST s b

sgtRead :: (VUM.Unbox a) => SegTree s a -> Int -> ST s a
{-# INLINE sgtRead #-}
sgtRead sgt node = VUM.read (sgtVec sgt) node

sgtWrite :: (VUM.Unbox a) => SegTree s a -> Int -> a -> ST s ()
{-# INLINE sgtWrite #-}
sgtWrite sgt node a = VUM.write (sgtVec sgt) node a

sgtModify :: (VUM.Unbox a) => SegTree s a -> (a -> a) -> Int -> ST s ()
{-# INLINE sgtModify #-}
sgtModify sgt f node = VUM.modify (sgtVec sgt) f node

sgtCreate :: (VUM.Unbox a) => Int -> a -> ST s (SegTree s a)
{-# INLINE sgtCreate #-}
sgtCreate n a = do
  vec <- VUM.replicate (4*n) a
  return $ SegTree { sgtVec = vec, sgtSize = n }

sgtAct :: (VUM.Unbox a) =>
          c ->             -- parameter
          SegTree s a ->   -- segment tree
          SgtMF s a b c -> -- action body
          Int ->           -- left
          Int ->           -- right
          ST s b
{-# INLINE sgtAct #-}
sgtAct c0 sgt mf left right = sub c0 0 0 (sgtSize sgt)
  where
  sub c node l r = mf c ft rcL rcR sgt node l r
    where
      ft | left <= l && r <= right = SgtIn
         | r <= left || right <= l = SgtOut
         | otherwise               = SgtOther
      mid = (l+r) `div` 2
      rcL c' = sub c' (2*node + 1) l mid
      rcR c' = sub c' (2*node + 2) mid r

sgtTrace :: (VUM.Unbox a, Show a) => SegTree s a -> ST s ()
sgtTrace sgt = 
  let size = sgtSize sgt
      sub vec node l r = do
        VUM.modify vec (\(_,_,_,a) -> (True,l,r,a)) node
        unless (l+1 == r) $ do
          let mid = (l + r) `div` 2
          sub vec (2*node+1) l mid
          sub vec (2*node+2) mid r
  in do
    vec <- VUM.new (4*size)
    forM_ [0..4*size-1] $ \node -> do
      a <- sgtRead sgt node
      VUM.write vec node (False,0,0,a)
    sub vec 0 0 size
    forM_ [0..4*size-1] $ \node -> do
      (eff,l,r,a) <- VUM.read vec node
      when eff $ 
        trace ("  " ++ show node ++ " [" ++ show l ++ ", " ++ show r ++ ")  "
               ++ show a) (return ())
