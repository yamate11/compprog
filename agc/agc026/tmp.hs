import qualified Data.IntMap as IM

data Trie a = Trie a [(Char, Trie a)]


xfib :: (Int -> Int) -> Int -> Int
xfib mf 0 = 1
xfib mf 1 = 1
xfib mf n = mf (n-1) + mf (n-2)

