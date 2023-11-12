; Read the number from the standard input.
in r1

; We start the division with 1.
inc r2

@l
    ; r3 = r1 mod r2
    mov r3, r1
    mod r3, r2

    ; if r3 is zero, then the streak
    ; isn't over.
    ceq r3, 0

    ; Pass around next number and divisor.
    cad r1, 1
    cad r2, 1

    ; Loop
    cjn %l

; Display the final result (it's always off-by-one), yet a dec fixes it.
dec r2
out r2
