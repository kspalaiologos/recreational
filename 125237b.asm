lbl 1
mov r3,1
lbl 2
mov r4,r3
mul r4,r3
le_ r4,r2
jz_ r4,3
mov r4,r2
mod r4,r3
jz_ r4,4
lbl 5
inc r3
jmp 2
lbl 4
mov r4,r2
div r4,r3
eq_ r4,r3
jz_ r4,5
mov r1,1
ret
lbl 3
clr r1
ret
