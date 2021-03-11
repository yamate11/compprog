import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as VM

toBits :: B.ByteString -> Integer
toBits =
  B.foldl' op zeroBits
  where op bits '0' = shiftL bits
        op bits '1' = setBit (shiftL bits) 0


main :: IO ()
main = do
  conts <- B.getContents
  [strA, strB] = B.lines conts
  bitsA = toBits strA
  bitsB = toBits strB
  putStr $ show $ solve bitsA bitsB
