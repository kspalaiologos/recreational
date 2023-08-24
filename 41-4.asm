
; FALSE interpreter in brainfuck.
; Copyright (C) 2023 by Kamila Szewczyk.
; Released to the public domain.
; Terminate the input with EOF or NUL.
; Interpreter must set cell to 0
; or leave it unchanged on EOF

; X   Y   FEAT
; [X] [X] COMMENTS
; [X] [X] DECIMAL LITERALS
; [X] [X] CHARACTER LITERALS
; [X] [X] QUOTES
; [X] [X] VARIABLE REF
; [X] [X] VARIABLE LOAD
; [X] [X] VARIABLE STORE
; [X] [X] STACK DUP
; [X] [X] STACK DISCARD
; [X] [X] STACK ROLL
; [X] [X] STACK ROLL 3
; [X] [X] STACK PICK
; [X] [X] +
; [X] [X] -
; [X] [X] *
; [X] [X] /
; [X] [X] _
; [X] [X] &
; [X] [X] |
; [X] [X] ~
; [X] [X] =
; [X] [X] >
; [X] [X] !
; [X] [X] ?
; [X] [ ] WHILE (#)
; [X] [X] CHAROUT
; [X] [X] CHARIN
; [X] [X] INTOUT

stk 16

mov r4, 255
inc r4
jnz r4, %skip
#gen_text("Please use a 16-bit interpreter.")
jmp 0
@skip

?ds=r6
?cs=r5
mov ds, 26
mov cs, ds

@loop
    clr r1
    in r1
    jz r1, %exec
    sto ds, r1
    inc ds
    jmp %loop

; ds: points past the end of the code.
; cs: points to the beginning of the code.

; Memory layout:
; a-z    code     stack
@exec
    ; Fetch.
    rcl r1, cs
    inc cs
    jz r1, 0
    ceq r1, 32
    corle r1, 13
    cjnz %exec
    ceq r1, .{
    cmov r4, .}
    cjnz %comment
    ; If single quote:
    ceq r1, 39
    cjnz %charlit
    ; Handle decimals:
    cge r1, .0
    candle r1, .9
    cjnz %decimal
    ; Handle double quotes:
    ceq r1, 34
    cjnz %string
    ; Handle [
    ceq r1, .[
    cjnz %codequote
    ; Handle ]: return.
    ceq r1, .]
    cjnz %coderet
    ; Handle single letter variables:
    cge r1, .a
    candle r1, .z
    cjnz %var
    ceq r1, .;
    cjnz %varload
    ceq r1, .:
    cmov r4, %varstore
    cjnz %ld2
    ceq r1, .$
    cjnz %stkdup
    ceq r1, .%
    cjnz %stkdsc
    ceq r1, .\
    cmov r4, %stkroll
    cjnz %ld2
    ceq r1, .@
    cmov r4, %stkroll3
    cjnz %ld2
    ceq r1, .O
    cjnz %stkpick
    ceq r1, .+
    cmov r4, %fadd
    cjnz %ld2
    ceq r1, .-
    cmov r4, %fsub
    cjnz %ld2
    ceq r1, .*
    cmov r4, %fmul
    cjnz %ld2
    ceq r1, ./
    cmov r4, %fdiv
    cjnz %ld2
    ceq r1, ._
    cjnz %ffloor
    ceq r1, .&
    cmov r4, %fband
    cjnz %ld2
    ceq r1, .|
    cmov r4, %fbor
    cjnz %ld2
    ceq r1, .~
    cjnz %fbneg
    ceq r1, .=
    cmov r4, %feq
    cjnz %ld2
    ceq r1, .>
    cmov r4, %fgt
    cjnz %ld2
    ceq r1, .!
    cjnz %bang
    ceq r1, .?
    cmov r4, %question
    cjnz %ld2
    ceq r1, .#
    cmov r4, %whi
    cjnz %ld2
    ceq r1, .^
    cjnz %chain
    ceq r1, .,
    cjnz %chapri
    ceq r1, ..
    cjnz %decpri
    jmp %exec

@comment
    rcl r1, cs
    inc cs
    jz r1, %exec
    sub r1, r4
    jz r1, %exec
    jmp %comment

@ld2
    dec ds
    rcl r1, ds
    dec ds
    rcl r2, ds
    jmp r4

@st1
    sto ds, r1
    inc ds
    jmp %exec

@charlit
    rcl r1, cs
    inc cs
    jmp %st1

@decimal
    mul r2, 10
    sub r1, .0
    ^add r2, r1
    rcl r1, cs
    inc cs
    cge r1, .0
    candle r1, .9
    cjnz %decimal
    dec cs
    ^mov r1, r2
    jmp %st1

@string
    rcl r1, cs
    inc cs
    ceq r1, 34
    cjnz r1, %exec
    out r1
    jmp %string

@codequote
    sto ds, cs
    inc ds
    mov r2, 1 ; Need to find 1 ].
@codequote_loop
    rcl r1, cs
    inc cs
    ceq r1, .[
    cadd r2, 1
    ceq r1, .]
    csub r2, 1
    jnz r2, %codequote_loop
    jmp %exec

@coderet
    pop cs
    ret

@var
    mov r4, .a
    ^sub r1, r4
    jmp %st1

@varload
    dec ds
    rcl r1, ds
    rcl r2, r1
    ^mov r1, r2
    jmp %st1

@varstore
    sto r1, r2
    clr r2
    jmp %exec

@stkdup
    dec ds
    rcl r1, ds
    inc ds
    jmp %st1

@stkdsc
    dec ds
    jmp %exec

@stkroll
    sto ds, r1
    inc ds
    ^mov r1, r2
    jmp %st1

@stkroll3
    dec ds
    rcl r3, ds
    sto ds, r1
    inc ds
    sto ds, r2
    inc ds
    sto ds, r3
    inc ds
    clr r2
    clr r3
    jmp %exec

@stkpick
    dec ds
    rcl r1, ds
    inc r1
    mov r2, ds
    ^sub r2, r1
    ^rcl r1, r2
    jmp %st1

@fadd
    ^add r1, r2
    jmp %st1

@fsub
    ^sub r2, r1
    ^mov r1, r2
    jmp %st1

@fmul
    mul r1, r2
    clr r2
    jmp %st1

@fdiv
    ^div r2, r1
    ^mov r1, r2
    jmp %st1

@ffloor
    dec ds
    rcl r1, ds
    bneg r1
    inc r1
    jmp %st1

@fband
    band r1, r2
    clr r2
    jmp %st1

@fbor
    bor r1, r2
    clr r2
    jmp %st1

@fbneg
    dec ds
    rcl r1, ds
    bneg r1
    jmp %st1

@feq
    ^eq r1, r2
    not r1
    dec r1
    jmp %st1

@fgt
    swp r1, r2
    ^gt r1, r2
    not r1
    dec r1
    jmp %st1

@bang
    dec ds
    rcl r1, ds
    push %exec
    push cs
    ^mov cs, r1
    jmp %exec

@question
    jz r2, %exec
    push %exec
    push cs
    ^mov cs, r1
    clr r2
    jmp %exec

@decpri
    dec ds
    rcl r1, ds
    ; push 0
    sto ds, 0
    inc ds
    ; push digits:
@digits_loop
    mov r2, r1
    mod r2, 10
    div r1, 10
    add r2, .0
    sto ds, r2
    inc ds
    jnz r1, %digits_loop
@digits_printer
    dec ds
    rcl r1, ds
    jz r1, %exec
    out r1
    jmp %digits_printer

@chapri
    dec ds
    rcl r1, ds
    out r1
    jmp %exec

@chain
    in r1
    ceq r1, 0
    csub r1, 1
    sto ds, r1
    inc ds
    jmp %exec

@whi
    ; r1 = loop_body
    ; r2 = loop_cond
    push r1
    push r2
@again
    sgt r2, 1 ; pop r2, push r2
    push %cond_done
    push cs
    ^mov cs, r2
    jmp %exec
@cond_done
    sgt r2, 1
    sgt r1, 2
    ; condition fail => quit.
    dec ds
    rcl r3, ds
    ceq r3, 0
    cbegin
        dsc
        dsc
        clr r2
    cend
    cjnz %exec
    ; ok, call loop_body.
    push %again
    push cs
    ^mov cs, r1
    clr r2
    clr r3
    jmp %exec
