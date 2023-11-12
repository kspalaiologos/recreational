#!/usr/bin/env bfmake
    stk 16
    org 0
db_ 0
db_ 65
db_ 0
db_ 0
#PAGE_SIZE = 16
#MM_BASE = 5
#call("alloc")
    mov r4, r6
#call("_main")
    end
@alloc
#alloc("r6", "r5")
    ret
@_p
    rclr1,r4
    outr1
    ret
@_g
    in r1
    ret
@_main
    psh 3
    psh 0
#call("_g")
    mov r2, r1
    pop r1
    sto r1, r2
    pop r1
    sto r1, r2
@L1
    mov r2, 3
    rcl r1, r2
    dec r1
    sto r2, r1
    inc r1
    jz_ r1, %L2
    psh r4
#call("alloc")
    mov r2, 1
    rcl r1, r2
    inc r1
    sto r2, r1
    dec r1
    sto r6, r1
    mov r4, r6
#call("_p")
#free("r4")
    pop r4
    psh 2
    psh 65
    rcl r1, 0
    mov r2, r1
    pop r1
    add r1, r2
    mov r2, r1
    pop r1
    sto r1, r2
@L3
    rcl r1, 2
    psh r1
    rcl r1, 0
    mov r2, r1
    pop r1
    sub r1, r2
    mov r2, 65
    sub r1, r2
    psh r1
    rcl r1, 0
    mov r2, 1
    sub r1, r2
    mov r2, r1
    pop r1
    lt_ r1, r2
    jz_ r1, %L4
    psh r4
#call("alloc")
    mov r2, 2
    rcl r1, r2
    inc r1
    sto r2, r1
    dec r1
    sto r6, r1
    mov r4, r6
#call("_p")
#free("r4")
    pop r4
    jmp %L3
@L4
    psh r4
#call("alloc")
    sto r6, 10
    mov r4, r6
#call("_p")
#free("r4")
    pop r4
    jmp %L1
@L2
    ret
