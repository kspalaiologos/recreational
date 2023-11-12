lbl 3               ; Main loop - the kinda entry point

    mov r2, 51      ; Loop 51 times.
    lbl 1           ; Loop start.
        in_ r1      ; Read character
        dec r2      ; Decrement the loop accumulator.
        jz_ r1, 4   ; If zero was read, end.
        jnz r2, 1   ; If we still loop, loop again.

    lbl 2           ; Second loop, accumulating the result.
        in_ r1      ; Read a character.
        jz_ r1, 4   ; If character is zero, end the loop and print result.
        sub r1, 10  ; Decrement r1 by 10 for next check.
        jz_ r1, 3   ; If the character - 10 (the newline) is zero, jump to 3
        inc r3      ; Increment character read amount.
        jmp 2
lbl 4
    out r3          ; Print out the result as an ASCII character.
