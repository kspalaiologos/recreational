# XY Machine

The program is a file with exactly two lines. The first line is a decimal number (subsequently called the _magic_ number) and the second line is the code. The code may not exceed 105 octets, or an error message will be printed and the interpreter will terminate.

First, the following substitutions are made on the code line:

```
R => BBB8B25BGf
P => 558545C5F5535E
O => FB04001058039BBB
N => 455E4D09988F87213E656060
M => Gj369Gf825Gl471AGzGzGzGy
L => 12GeF0Hi5BBB8BGfHh4BBB7BBBA1GfBBB444Hg66BBB3BB9Gf8BBB888
K => F73619D1253F15651565FE8F2F2E620B320F73E232357576A3B4342A
J => 10151512234334533535906165151510572322324454545824350353
```

Then, every instance of the letter G followed by a lowercase letter is replaced with the amount of zeroes corresponding to the position of the letter in the lowercase alphabet (0-indexed). For example, `Gg` becomes `000000`. The same rule holds for the uppercase letters H and I, except H produces `B`s and I produces `F`s, so for example `Ig` becomes `FFFFFF`.

After these transformations are performed, the code becomes a a sequence of hexadecimal digits. Then, the magic algorithm of the code is performed.

The magic "encryption" algorithm steps follow:
- Consider T the array of ASCII codepoints of the input. Consider TL the length of it.
- Create an array called C with 256 zeroes.
- Create an array called A with TL zeroes.
- For each element E of the T array, increment the E-th cell of C.
- Given I=0, for each number N in range `<0, 256)`, set the N-th element of C to I and increment I by the previous value of the N-th element of C.
- For each I in `<0, magic number)`, take the I-th element of T and call it X. Use X to index into C and then A. Set the value in the A array to I. Increment X-th element of C. 
- For each I in `<magic number, TL)`, take the I-th element of T and call it X. Use X to index into C and then A. Set the value in the A array to I + 1. Increment X-th element of C. 
- For each I in range `<0, TL)`:
  - Consider c = 0, length = 256, half = 128.
  - While length is non-zero:
    - If the (c+half)-th element of C is smaller than the magic number, add half+1 to c and subtract the inverted least significant bit of length from half.
    - Set length to half and halve half.
  - Set the I-th element of T to c.
  - Set take the (magic number - 1)-th element of the A array. Make it the new magic number.
- Turn every element of the T array to a character value and concatenate them all to return a code string.

Then, break up the code string into three byte-long pieces. Then, interpret every three byte long piece as a hexadecimal number. If the number is greater than 2048, subtract 4096 from it. Finally, yield it. This process will turn the code into an array of signed integers.

Then, pad the resulting array (call it the memory) with zeroes to MEM entries (implementation defined, the supplied interpreter assumes MEM=65536). Then enter the evaluation loop. Assuming, initially, i=0:
- if memory[i] = -1: set memory[memory[i + 1]] to the number read from standard input.
- if memory[i + 1] = -1: print memory[memory[i]] as a number to the standard output.
- Otherwise, subtract in-place memory[memory[i]] from memory[memory[i + 1]]. If the value of memory[memory[i + 1]] becomes less than or equal to 0, set i=memory[i + 2] and enter the next iteration of the evaluation loop.
- Finally, increment i by 3.
