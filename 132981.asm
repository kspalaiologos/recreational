# (way too many) ways of zeroing a register

I remember being taught these by a certain person (I "invented" some of these myself); I don't remember who did I get them from, anyways these are the most interesting; possible use cases include restricted source code challenges or other bizzare stuff.

`=>` Zero mov:
```
mov reg, 0
; mov eax, 0: B800000000
```

`=>` `push`+`pop`:
```
push [something equal to zero]
pop reg
; push 0 / pop eax: 6A0058

; note: if you have a register equal to zero, it will be
; shorter but also equal to a mov.
```

`=>` `sub` from itself:
```
sub reg, reg
; sub eax, eax: 29C0
```

`=>` `mul` by zero:
```
imul reg, 0
; imul eax, 0: 6BC000
```

`=>` `and` by zero:
```
and reg, 0
; and eax, 0: 83E000
```

`=>` `xor` by itself:
```
xor reg, reg
; xor eax, eax: 31C0

; possibly the best way to zero an arbitrary register,
; I remembered this opcode (among other).
```

`=>` `or` and `inc` / `not`:
```
or reg, -1
inc reg     ; or not reg

; or eax, -1 / inc eax: 83C8FF40
```

`=>` reset `ECX`:
```
loop $

; loop $: E2FE
```

`=>` flush `EDX`:
```
shr eax, 1
cdq

; D1E899
```

`=>` zero `AL` (`AH = AL, AL = 0`)
```
aam 1
; D401
```

`=>` reset `AH`:
```
aad 0
; D500
```

`=>` Read 0 from the port
```
mov dx, 81h
in al, dx
; 66BA8100EC
```

`=>` Reset `AL`
```
stc
setnc al
; F90F93C0
```

`=>` Use the zero descriptor from `gdt`:
```
sgdt [esp-6]
mov reg, [esp-4]
mov reg, [reg]
; with eax: 0F014424FA8B4424FC8B00
```

`=>` Read zero from the `fs` segment (PE `exe` only)
```
mov reg, fs:[10h]
; with eax: 64A110000000
```

`=>` The brainfuck way
```
inc reg
jnz $-1
; with eax: 4075FD
```

`=>` Utilize the coprocessor
```
fldz
fistp dword ptr [esp-4]
mov eax, [esp-4]
; D9EEDB5C24FC8B4424FC
```

Another possible options:

 * Read zero using the builtin random number generator.
 * calculate sine from `pi * n` (use `fmul`).

There are way cooler and potentially useful ways to execute this operation; although I didn't come up with them, therefore I'm not posting.
