{-# LANGUAGE TypeFamilies, TypeOperators, CPP #-}

import Data.Function (fix)
import Data.Bits
import Data.Word
import Data.Int
import Control.Arrow (first,(&&&))

import System.Environment
import Data.List

fibF :: (Int->Int) -> Int -> Int
fibF _ 0 = 1
fibF _ 1 = 1
fibF f n = f (n-1) + f (n-2)

fib = fix fibF

fib' = memoFix fibF

fib3 :: Int -> Int
fib3 n = head $ drop n $ unfoldr p (1,1)
  where p (x,y) = Just (x, (y, x+y))

main = do
  [sn] <- getArgs
  putStrLn $ show $ fib3 (read sn)


----------------------------------------------------------------------
-- Excerpts from Data.MemoTrie
----------------------------------------------------------------------

infixr 0 :->:

-- | Mapping from all elements of @a@ to the results of some function
class HasTrie a where
  -- | Representation of trie with domain type @a@
  data (:->:) a :: * -> *
  -- | Create the trie for the entire domain of a function
  trie   :: (a  ->  b) -> (a :->: b)
  -- | Convert a trie to a function, i.e., access a field of the trie
  untrie :: (a :->: b) -> (a  ->  b)
  -- | List the trie elements.  Order of keys (@:: a@) is always the same.
  enumerate :: (a :->: b) -> [(a,b)]

-- | Domain elements of a trie
domain :: HasTrie a => [a]
domain = map fst (enumerate (trie (const oops)))
  where
    oops = error "Data.MemoTrie.domain: range element evaluated."

instance HasTrie () where
  newtype () :->: a = UnitTrie a
  trie f = UnitTrie (f ())
  untrie (UnitTrie a) = \ () -> a
  enumerate (UnitTrie a) = [((),a)]

                                                 
instance HasTrie Bool where
  data Bool :->: x = BoolTrie x x
  trie f = BoolTrie (f False) (f True)
  untrie (BoolTrie f t) = if' f t
  enumerate (BoolTrie f t) = [(False,f),(True,t)]
                                                  
-- | Conditional with boolean last.
-- Spec: @if' (f False) (f True) == f@
if' :: x -> x -> Bool -> x
if' t _ False = t
if' _ e True  = e

instance (HasTrie a, HasTrie b) => HasTrie (Either a b) where
  data (Either a b) :->: x = EitherTrie (a :->: x) (b :->: x)
  trie f = EitherTrie (trie (f . Left)) (trie (f . Right))
  untrie (EitherTrie s t) = either (untrie s) (untrie t)
  enumerate (EitherTrie s t) = enum' Left s `weave` enum' Right t

{-
instance Newtype (Either a b :->: x) where
  type O (Either a b :->: x) = (a :->: x, b :->: x)
  pack (f,g) = EitherTrie f g
  unpack (EitherTrie f g) = (f,g)
-}

enum' :: (HasTrie a) => (a -> a') -> (a :->: b) -> [(a', b)]
enum' f = (fmap.first) f . enumerate

weave :: [a] -> [a] -> [a]
[] `weave` as = as
as `weave` [] = as
(a:as) `weave` bs = a : (bs `weave` as)

instance (HasTrie a, HasTrie b) => HasTrie (a,b) where
  newtype (a,b) :->: x = PairTrie (a :->: (b :->: x))
  trie f = PairTrie (trie (trie . curry f))
  untrie (PairTrie t) = uncurry (untrie .  untrie t)
  enumerate (PairTrie tt) =
    [ ((a,b),x) | (a,t) <- enumerate tt , (b,x) <- enumerate t ]

instance HasTrie x => HasTrie [x] where
  newtype [x] :->: a = ListTrie (Either () (x,[x]) :->: a)
  trie f = ListTrie (trie (f . list))
  untrie (ListTrie t) = untrie t . delist
  enumerate (ListTrie t) = enum' list t

list :: Either () (x,[x]) -> [x]
list = either (const []) (uncurry (:))

delist :: [x] -> Either () (x,[x])
delist []     = Left ()
delist (x:xs) = Right (x,xs)

#define WordInstance(Type,TrieType)\
instance HasTrie Type where \
  newtype Type :->: a = TrieType ([Bool] :->: a);\
  trie f = TrieType (trie (f . unbits));\
  untrie (TrieType t) = untrie t . bits;\
  enumerate (TrieType t) = enum' unbits t

WordInstance(Word,WordTrie)
WordInstance(Word8,Word8Trie)
WordInstance(Word16,Word16Trie)
WordInstance(Word32,Word32Trie)
WordInstance(Word64,Word64Trie)

-- | Extract bits in little-endian order
bits :: (Num t, Bits t) => t -> [Bool]
bits 0 = []
bits x = testBit x 0 : bits (shiftR x 1)

-- | Convert boolean to 0 (False) or 1 (True)
unbit :: Num t => Bool -> t
unbit False = 0
unbit True  = 1

-- | Bit list to value
unbits :: (Num t, Bits t) => [Bool] -> t
unbits [] = 0
unbits (x:xs) = unbit x .|. shiftL (unbits xs) 1


instance HasTrie Char where
  newtype Char :->: a = CharTrie (Int :->: a)
  untrie (CharTrie t) n = untrie t (fromEnum n)
  trie f = CharTrie (trie (f . toEnum))
  enumerate (CharTrie t) = enum' toEnum t

#define IntInstance(IntType,WordType,TrieType) \
instance HasTrie IntType where \
  newtype IntType :->: a = TrieType (WordType :->: a); \
  untrie (TrieType t) n = untrie t (fromIntegral n); \
  trie f = TrieType (trie (f . fromIntegral)); \
  enumerate (TrieType t) = enum' fromIntegral t

IntInstance(Int,Word,IntTrie)
IntInstance(Int8,Word8,Int8Trie)
IntInstance(Int16,Word16,Int16Trie)
IntInstance(Int32,Word32,Int32Trie)
IntInstance(Int64,Word64,Int64Trie)

memo :: HasTrie t => (t -> a) -> (t -> a)
memo = untrie . trie

-- | Memoize a binary function, on its first argument and then on its
-- second.  Take care to exploit any partial evaluation.
memo2 :: (HasTrie s,HasTrie t) => (s -> t -> a) -> (s -> t -> a)

-- | Memoize a ternary function on successive arguments.  Take care to
-- exploit any partial evaluation.
memo3 :: (HasTrie r,HasTrie s,HasTrie t) => (r -> s -> t -> a) -> (r -> s -> t -> a)

-- | Lift a memoizer to work with one more argument.
mup :: HasTrie t => (b -> c) -> (t -> b) -> (t -> c)
mup mem f = memo (mem . f)

memo2 = mup memo
memo3 = mup memo2

-- | Memoizing recursion. Use like `fix`.
memoFix :: HasTrie a => ((a -> b) -> (a -> b)) -> (a -> b)
memoFix h = fix (memo . h)
