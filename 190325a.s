lbl 1
mov r1,r2
ret
lbl 2
mov r1,r3
ret
lbl 3
jz_ r2,4
jz_ r3,4
mov r1,1
ret
lbl 4
mov r1,2
ret
lbl 5
jz_ r2,6
mov r1,2
ret
lbl 6
mov r1,1
ret
lbl 7
jnz r2,8
jnz r3,8
mov r1,2
ret
lbl 8
mov r1,1
ret
lbl 9
jnz r2,8
jnz r3,8
lbl 10
mov r1,2
ret
lbl 8
eq_ r2,r3
jnz r2,10
mov r1,1
ret
lbl 11
jz_ r2,12
lbl 13
mov r1,1
ret
lbl 12
jnz r3,13
mov r1,2
ret
