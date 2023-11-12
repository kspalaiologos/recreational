# asm2bf, 62 bytes.

## Encoding

Algorithm takes input in r1.

```
@l
mov r2,r1
mod r2,94
add r2,32
out r2
div r2,94
jmp %l
```

## Decoding

```
@l
add r2,r1
clr r4
@x
rcl r3,r2
eq_ r2,r1
jnz r2,%z
rcl r3,r2
add r4,r3
mul r4,94
jmp %x
@z
div r4,94
```
