import Data.Ord (comparing)
import Data.List (maximumBy, intersect, inits, tails)
import Data.Function (on)
entry=(maximumBy(comparing length).).(intersect`on`concatMap(tail.inits).tails)
