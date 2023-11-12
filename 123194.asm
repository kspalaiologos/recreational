
; edi => input string.
; eax <= 1 or 0.

; notes:
; the string needs to be null terminated and located in a
; writable memory location, as it will be mutated.

BITS 64

DENNIS: MOV RAX, RDI
        MOV RSI, RDI
        MOV R8D, 0x208222
.CTOR:  MOV CL, BYTE [RSI]
        TEST CL, CL
        JE .SP
        MOV EDX, ECX
        AND EDX, -33
        MOVSX EDX, DL
        SUB EDX, 65
        CMP EDX, 25
        JA .LI
        MOV EDX, R8D
        INC RAX
        SAR EDX, CL
        AND EDX, 1
        MOV BYTE [RAX-1], DL
.LI:    INC RSI
        JMP .CTOR
.SP:    MOV BYTE [RAX], 2
.EQL:   INC RDI
        DEC RAX
        MOV DL, BYTE [RDI]
        MOV SIL, BYTE [RAX]
        CMP BYTE [RDI-1], SIL
        JNE .EQE
        CMP DL, 2
        JNE .EQL
.EQE:   XOR EAX, EAX
        CMP DL, 2
        SETE AL
        RET
