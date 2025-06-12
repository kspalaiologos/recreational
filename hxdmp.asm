; read 16 bytes of data to memory:
@start
mov r1, 16
mov r2, 0
nav r1
raw .[
in r3
inc r3
ceq r3, 0
cmov r1, 1
dec r3
sto r2, r3
cflip
cadd r2, 1
dec r1
nav r1
raw .]
mov r6, r2
rcl r1, 64
jz r6, 0
mov r4, 32
mov r5, 7
nav r5
raw .[
mov r3, r1
mod r3, 16
sto r4, r3
inc r4
div r1, 16
dec r5
nav r5
raw .]
mov r4, 38
mov r5, 7
nav r5
raw .[
rcl r1, r4
cle r1, 9
cadd r1, 48
cflip
cadd r1, 55
out r1
dec r4
dec r5
nav r5
raw .]
out .0
out .:
out 32
clr r4

mov r3, 0
mov r5, r6
nav r5
raw .[
rcl r1, r4
mov r2, r1
div r2, 16
cle r2, 9
cadd r2, 48
cflip
cadd r2, 55
out r2
inc r3
mov r2, r1
mod r2, 16
cle r2, 9
cadd r2, 48
cflip
cadd r2, 55
out r2
inc r3
mov r1, r4
mod r1, 4
ceq r1, 1
coreq r1, 3
cout 32
cadd r3, 1
inc r4
dec r5
nav r5
raw .]

mov r4, 40
sub r4, r3
nav r4
raw .[
out 32
dec r4
nav r4
raw .]

out 32
clr r4
mov r5, r6
nav r5
raw .[
rcl r1, r4
cge r1, 32
candle r1, 126
cout r1
cflip
cout ..
inc r4
dec r5
nav r5
raw .]
out 10
rcl r1, 64
inc r1
mov r2, 64
sto r2, r1
jmp %start%  
