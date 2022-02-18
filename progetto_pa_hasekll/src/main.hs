import System.IO
import Control.Monad

type Matrix a = [[a]]

main = do
  let contents = readFile "dataset.txt"
  ls <- fmap lines (contents)
  let alive = map words ls
  print alive

