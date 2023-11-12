00000000  BA22822000        mov edx,0x208222
00000005  D3EA              shr edx,cl
00000007  F6C201            test dl,0x1
0000000A  740B              jz 0x17
0000000C  8D519F            lea edx,[ecx-0x61]
0000000F  83FA19            cmp edx,byte +0x19
00000012  8D59E0            lea ebx,[ecx-0x20]
00000015  EB09              jmp short 0x20
00000017  8D51BF            lea edx,[ecx-0x41]
0000001A  83FA19            cmp edx,byte +0x19
0000001D  8D5920            lea ebx,[ecx+0x20]
00000020  0F46CB            cmovna ecx,ebx
00000023  8808              mov [eax],cl
00000025  40                inc eax
00000026  0FBE08            movsx ecx,byte [eax]
00000029  85C9              test ecx,ecx
0000002B  75D3              jnz 0x0
0000002D  C3                ret
