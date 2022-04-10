import Data.List ( transpose, inits )
import Data.Function ( on )
import Control.Monad ( ap )

answer :: Int
answer = 42

count :: (a -> Bool) -> [a] -> Int
count = (length .) . filter

whereInd :: [Bool] -> [Int]
whereInd = map fst . filter snd . zip [0..]

processSingle :: [[[Int]]] -> [Int] -> [Int]
processSingle = (whereInd .) . ap (ap . (on (zipWith (||)) check .) . match) ((map transpose .) . match)
  where
    match = (foldl1 (zipWith (zipWith (zipWith (||)))) .) . map . flip (map . map . map . (==))
    check = map (any ((5 ==) . count id))

entry :: [[[Int]]] -> [Int] -> Int
entry = (head .) . (. (tail . inits)) . (=<<) . processSingle
