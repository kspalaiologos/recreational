00000000  B8BF847B09        mov eax,0x97b84bf
00000005  B90A000000        mov ecx,0xa
0000000A  31D2              xor edx,edx
0000000C  C74424FCA4100A00  mov dword [rsp-0x4],0xa10a4
00000014  48C1E022          shl rax,byte 0x22
00000018  48894424EC        mov [rsp-0x14],rax
0000001D  48B83C0000000000  mov rax,0x245e00000000003c
         -5E24
00000027  48894424F4        mov [rsp-0xc],rax
0000002C  89F8              mov eax,edi
0000002E  66F7F1            div cx
00000031  4889D0            mov rax,rdx
00000034  83E00F            and eax,byte +0xf
00000037  66035444EC        add dx,[rsp+rax*2-0x14]
0000003C  C3                ret
