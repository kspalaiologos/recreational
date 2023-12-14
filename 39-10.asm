; -*-mode:asm;coding:utf-8-*-
; $ uname -m
; x86_64
; $ nasm cg39.asm -f elf64 && gcc cg39.o -o cg39 2> /dev/null
; $ ./cg39 "((()()())(()()()()){{}})"
; 7

[BITS 64]

default rel

extern mmap
extern mprotect
extern printf

C1 equ 0x75D2854D0B048D4B
C2 equ 0xC3894903048D4B04
C3 equ 0xC0854D0E75D2854D
C4 equ 0x1C034EC8FF491574
C5 equ 0x774C9854D0CEBC7
C6 equ 0x45C2940F41D2854D
C7 equ 0xC0894C0D75D2854D
C8 equ 0xC71C894C01408D4D
C9 equ 0x498D4DC8894C0BEB
C10 equ 0xC0854D0F75D2854D
C11 equ 0xF8C77C834A1774
C12 equ 0x74C9854DE0FF1175
C13 equ 0x7500F8CE7C834A08
C14 equ 0x4000020000000001
C15 equ 0x3145C03145DB3145
C16 equ 0x48D430575D2854D
C17 equ 0xC30109448D43C300

global main

section .text
emit:   push rbx
.redo:  mov  rax, QWORD [prg]                    ; Cache the program.
        mov  dl, BYTE [rax]
        cmp  dl, '('                             ; If not '(': try bracket.
        jne  .brk
        mov  rdx, QWORD [buf]
        cmp  BYTE [rax + 1], ')'
        lea  rcx, [rdx + 3]
        mov  QWORD [buf], rcx
        jne  .dpar                               ; If not '()': call unary.
        mov  WORD [rdx], 0xFF49
        mov  BYTE [rdx + 2], 0xC3
        jmp  .skip
.brk:   cmp  dl, '['
        jne  .brc
        cmp  BYTE [rax + 1], ']'
        mov  rdx, QWORD [buf]
        jne  .dbrk
        mov  rsi, C1
        mov  rdi, C2
        lea  rcx, [rdx + 16]
        mov  QWORD [buf], rcx
        mov  QWORD [rdx], rsi
        mov  QWORD [rdx + 8], rdi
.skip:  add  rax, 2                              ; Advance the program after nullary.
        mov  QWORD [prg], rax
        jmp  .nterm
.brc:   cmp  dl, '{'
        jne  .angl
        cmp  BYTE [rax+1], '}'
        mov  rbx, QWORD [buf]
        jne  .dbrc
        lea  rdx, [rbx + 31]
        mov  BYTE [rbx + 30], 0xCE
        mov  rsi, C3
        mov  QWORD [rbx], rsi
        mov  QWORD [buf], rdx
        mov  rdi, C4
        mov  rsi, C5
        mov  QWORD [rbx + 8], rdi
        mov  QWORD [rbx + 16], rsi
        mov  DWORD [rbx + 24], 0x4EC9FF49
        mov  WORD [rbx + 28], 0x1C03
        jmp  .skip
.angl:  cmp  dl, '<'
        jne  .nterm
        cmp  BYTE [rax + 1], '>'
        jne  .dangl
        mov  rdx, QWORD [buf]
        mov  rdi, C6
        lea  rcx, [rdx + 11]
        mov  QWORD [rdx], rdi
        mov  QWORD [buf], rcx
        mov  WORD [rdx + 8], 0xB60F
        mov  BYTE [rdx + 10], 0xD2
        jmp  .skip
.dpar:  mov  WORD [rdx], 0x3145
        inc  rax
        mov  BYTE [rdx + 2], 0xDB
        mov  QWORD [prg], rax
        xor  eax, eax
        call emit
        mov  rax, QWORD [buf]
        inc  QWORD [prg]
        mov  rsi, C7
        mov  QWORD [rax], rsi
        lea  rdx, [rax + 29]
        mov  QWORD [buf], rdx
        mov  rdi, C8
        mov  QWORD [rax + 8], rdi
        mov  rsi, C9
        mov  QWORD [rax + 16], rsi
        mov  DWORD [rax + 24], 0x1C894C01
        mov  BYTE [rax + 28], 0xC6
        jmp  .nterm
.dbrk:  mov  WORD [rdx], 0x3145
        inc  rax
        lea  rcx, [rdx + 3]
        mov  BYTE [rdx + 2], 0xDB
        mov  QWORD [prg], rax
        xor  eax, eax
        mov  QWORD [buf], rcx
        call emit
        mov  rax, QWORD [buf]
        inc  QWORD [prg]
        lea  rdx, [rax + 3]
        mov  WORD [rax], 0xF749
        mov  QWORD [buf], rdx
        jmp  .xdb
.dbrc:  mov  DWORD [rbx], 0x48DB3145             ; Unary '{': Need to adjust begin/end loads.
        inc  rax
        lea  rdx, [rbx + 48]
        mov  rdi, C10
        mov  rcx, C11
        mov  QWORD [rbx + 13], rdi
        mov  rsi, C12
        mov  rdi, C13
        mov  BYTE [rbx + 4], 0xB8
        mov  QWORD [rbx + 21], rcx
        mov  QWORD [rbx + 29], rsi
        mov  QWORD [rbx + 37], rdi
        mov  WORD [rbx + 45], 0xFF02
        mov  BYTE [rbx + 47], 0xE0
        mov  QWORD [prg], rax
        xor  eax, eax
        mov  QWORD [buf], rdx
        call emit
        mov  rax, QWORD [buf]
        lea  rdx, [rbx + 3]
        inc  QWORD [prg]
        mov  QWORD [rax + 2], rdx
        lea  rdx, [rax + 12]
        mov  WORD [rax], 0xB848
        mov  WORD [rax + 10], 0xE0FF
        mov  QWORD [buf], rdx
        mov  QWORD [rbx + 5], rdx
        jmp  .nterm
.dangl: inc  rax
        mov  QWORD [prg], rax
        xor  eax, eax
        call emit
        mov  rax, QWORD [buf]
        inc  QWORD [prg]
        lea  rdx, [rax + 3]
        mov  WORD [rax], 0x3145
        mov  QWORD [buf], rdx
.xdb:   mov  BYTE [rax + 2], 0xDB
.nterm: mov  rax, QWORD [prg]                    ; Add next term.
        mov  al, BYTE [rax]                      ; Loop if term not: ])}> or null.
        cmp  al, '>'
        jg   .ckp
        test al, al
        js   .redo
        mov  rdx, C14
        bt   rdx, rax
        jnc  .redo
        jmp  .done
.ckp:   and  eax, -0x21
        cmp  al, ']'
        jne  .redo
.done:  pop  rbx
        ret


main:   xor  edi, edi
        xor  r9d, r9d
        or   r8d, -1                             ; fd = -1.
        mov  rbp, QWORD [rsi + 8]
        mov  QWORD [prg], rbp                    ; Program is argv[1].
        mov  edx, 3                              ; PROT_READ | PROT_WRITE
        mov  esi, 0x400000                       ; Size of the machine code region.
        mov  ecx, 34                             ; MAP_ANONYMOUS | MAP_PRIVATE
        call mmap wrt ..plt                      ; Allocate 0x400000 for the machine code.
        mov  rbx, rax
        add  rax, 12                             ; Write stub (zero working registers).
        mov  QWORD [buf], rax
        mov  rax, C15
        mov  QWORD [rbx], rax
        xor  eax, eax
        mov  DWORD [rbx + 8], 0xD23145C9
        call emit                                ; Emit the code.
        mov  rax, QWORD [buf]
        mov  esi, 0x400000
        mov  rdi, rbx
        mov  rcx, C16                            ; rax = (height << 1) | sel_stack
        mov  QWORD [rax], rcx
        lea  rdx, [rax + 16]
        mov  rcx, C17
        mov  QWORD [rax + 8], rcx
        mov  QWORD [buf], rdx
        mov  edx, 5                              ; PROT_READ | PROT_EXEC
        call mprotect wrt ..plt                  ; Mark executable.
        lea  rsi, [s2]                           ; Load the stacks.
        lea  rdi, [s1]
        call rbx                                 ; Run the JIT-compiled code.
        test al, 1                               ; Determine active stack.
        jne  .ts2
        sar  eax, 1
        xor  ebp, ebp
        mov  ebx, eax
.s1l:   cmp  ebx, ebp                            ; Loop from 0 to height (rax >> 1 = rbx).
        jle  .done
        lea  rsi, [s1]
        mov  rsi, QWORD [rsi + rbp * 8]          ; Load stack element, format.
        lea  rdi, [fmt]
        xor  eax, eax
        inc  rbp
        call printf wrt ..plt
        jmp  .s1l
.ts2:   sar  eax, 1
        xor  ebp, ebp
        mov  ebx, eax
.s2l:   cmp  ebx, ebp
        jle  .done
        lea  rsi, [s2]
        mov  rsi, QWORD [rsi + rbp * 8]
        lea  rdi, [fmt]
        xor  eax, eax
        inc  rbp
        call printf wrt ..plt
        jmp  .s2l
.done:  xor  eax, eax
        ret

section .bss
s2:     resb 4096
s1:     resb 4096

section .data
prg:    dq 0
buf:    dq 0
fmt:    db "%ld", 10, 0
