d←'.'
q←'s',⍨w←'bottle'
x←∊a z←' of beer' ' on the wall'
{⎕←∊⍵q x','⍵q a d⋄⎕←∊'Take one down and pass it around,'(⍵-1)w('s'/⍨⍵≠2)x d}¨⌽1↓⍳99
∊1w x','1w a d
∊'Go to the store and buy some more,'99q x d
