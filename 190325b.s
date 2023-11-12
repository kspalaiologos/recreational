
stk 16
org 0

; v=true(x,y)
; x=r2, y=r3, v=r1
lbl 1
    mov r1, r2
    ret

; v=false(x,y)
; x=r2, y=r3, v=r1
lbl 2
    mov r1, r3
    ret

; v=and(b1, b2)
; v=1|2;r1, b1=r2, b2=r3
lbl 3
    jz_ r2, 4
    jz_ r3, 4
    mov r1, 1
    ret
lbl 4
    mov r1, 2
    ret

; v=not(b)
; v=1|2;r1, b=r2
lbl 5
    jz_ r2, 6
    mov r1, 2
    ret
lbl 6
    mov r1, 1
    ret

; v=or(b1, b2)
; v=1|2;r1, b1=r2, b2=r3
lbl 7
    jnz r2, 8
    jnz r3, 8
    mov r1, 2
    ret
lbl 8
    mov r1, 1
    ret

; v=xor(b1, b2)
; v=1|2;r1, b1=r2, b2=r3
; r2 is trashed.
lbl 9
    jnz r2, 8
    jnz r3, 8
lbl 10
    mov r1, 2
    ret
lbl 8
    eq_ r2, r3
    jnz r2, 10
    mov r1, 1
    ret

; v=implies(b1, b2)
; v=1|2;r1, b1=r2, b2=r3
; r2 is trashed.
lbl 11
    jz_ r2, 12
lbl 13
    mov r1, 1
    ret
lbl 12
    jnz r3, 13
    mov r1, 2
    ret
