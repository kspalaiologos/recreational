# Read the file passed in args to a string.

import sys

# Maximum amount of memory. Tweak if needed.
MEM = 65536

with open(sys.argv[1], 'r') as f:
    code = f.read().split('\n')

magic, code = int(code[0]), code[1]

if len(code) > 105:
    print("Code too long.")
    exit()

conversions = {
    'R':'BBB8B25BGf', 'P':'558545C5F5535E', 'O':'FB04001058039BBB',
    'N':'455E4D09988F87213E656060', 'M':'Gj369Gf825Gl471AGzGzGzGy',
    'L':'12GeF0Hi5BBB8BGfHh4BBB7BBBA1GfBBB444Hg66BBB3BB9Gf8BBB888',
    'K':'F73619D1253F15651565FE8F2F2E620B320F73E232357576A3B4342A',
    'J':'10151512234334533535906165151510572322324454545824350353'
}

for key in conversions:
    code = code.replace(key, conversions[key])

new_code = ''
i = 0
while i < len(code):
    if code[i] == 'G':
        new_code = new_code + "0" * (ord(code[i + 1]) - ord('a'))
        i = i + 1
    elif code[i] == 'H':
        new_code = new_code + "B" * (ord(code[i + 1]) - ord('a'))
        i = i + 1
    elif code[i] == 'I':
        new_code = new_code + "F" * (ord(code[i + 1]) - ord('a'))
        i = i + 1
    else: new_code = new_code + code[i]
    i += 1

# The magic algorithm.
T = [ord(c) for c in new_code]
TL = len(T)
C = [0] * 256
i = p = length = half = 0
A = [0] * TL
for c in new_code: C[ord(c)] += 1
for c in range(256):
    p = C[c]; C[c] = i; i += p
for i in range(magic):
    A[C[T[i]]] = i
    C[T[i]] += 1
for i in range(magic, TL):
    A[C[T[i]]] = i + 1
    C[T[i]] += 1
p = magic
for i in range(TL):
    c = 0
    length = 256
    half = length >> 1
    while 0 < length:
        # ...
        if C[c + half] < p:
            c += half + 1
            half -= (length & 1) ^ 1
        length = half
        half = half >> 1
    T[i] = c
    p = A[p - 1]

def brk(s, n):
    return [s[i:i+n] for i in range(0, len(s), n)]

def convert(s):
    num = int(s, 16)
    if num > 2048:
        return num - 4096
    else:
        return num

a = list(map(convert, brk(''.join([chr(c) for c in T]), 3)))

a += [0] * (MEM - len(a))

i = 0
while i >= 0:
    if a[i] == -1:
        a[a[i + 1]] = int(input())
    elif a[i + 1] == -1:
        print(str(a[a[i]]) + " ", end="")
    else:
        a[a[i + 1]] -= a[a[i]]
        if a[a[i + 1]] <= 0:
            i = a[i + 2]
            continue
    i += 3