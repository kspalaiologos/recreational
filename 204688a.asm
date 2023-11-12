; Essentially, our game plan is to compare amount of `b' and `s' occurences.
; Start a new label
@loop
; Read a character from stdin, put it in r1.
  in r1
; If r1 = 'b' (note the way of expressing a character constant), set
; the condition flag.
  ceq r1,.b
; If the condition flag is set, add 1 to r2
  cadd r2,1
; If r1 = 's', set the condition flag. Otherwise, clear it.
  ceq r1,.s
; If the condition flag is set, add 1 to r3
  cadd r3,1
; If r1 is bigger than zero, we didn't hit eof yet, so continue reading.
; Note: The golfed version is based on a certain property beyond explaining.
; It's related to the way how labels work under the hood.
  jnz r1,%l
; The loop finished.
; Compare r2 and r3 (the accumulators).
gt r2,r3
; Display the result
out r2
