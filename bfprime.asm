; Algorithm: Read N (amount of primes to print separated with newlines).
; Print N consecutive primes starting with 2, 3, 5, and so on.
; Uses the fact that primes greater than 7 are in the form 6n-1 or 6n+1
; for n >= 2. Because memory access is very slow we use trial division
; of these values up until isqrt(n) computed via binary search.
@read_number_loop
  in r1
  sub r1, .0
  cle r1, 9
  cbegin
    mul r2, 10
    add r2, r1
  cend
  cjnz %read_number_loop
  cge r2, 1
  cout .2
  cout 10
  cge r2, 2
  cout .3
  cout 10
  cge r2, 3
  cout .5
  cout 10
  cge r2, 4
  cout .7
  cout 10
  cle r2, 4
  cjnz 0
  sub r2, 4
  mov r6, r2
  mov r3, 12
@loop
  jz r6, 0
  dec r3
  mov r1, r3
  add r1, 2
  push r3
  ; r2 = isqrt(r1)
  mov r2, 0
  mov r4, r1
  inc r4
@isqrt_loop
  dec r4
  ceq r4, r2       ; <-- bottleneck
  cjnz %isqrt_end
  inc r4
  mov r3, r4
  add r3, r2
  asr r3
  mov r5, r3
  mul r5, r3
  cle r5, r1
  cmov r2, r3
  cflip
  cmov r4, r3
  jmp %isqrt_loop
@isqrt_end
  pop r3
  sub r1, 2
#call("is_prime")
  jz r1, %skip1
  mov r1, r3
#call("print_number")
  out 10
  dec r6
@skip1
  jz r6, 0
  add r3, 2
  mov r1, r3
#call("is_prime")
  jz r1, %skip2
  mov r1, r3
#call("print_number")
  out 10
  dec r6
@skip2
  add r3, 5
  jmp %loop
end

; Naive primality test of the number in r1: check all divisors
; of n up to sqrt(n), excluding 2 and 3. result in r1 (0 = not prime, 1 = prime).
@is_prime
  push r3
  ; r3 = 5
  mov r3, 5
@is_prime_loop
  ; if r3 > r2 then return 1
  cgt r3, r2
  cmov r1, 1
  cjnz %is_prime_end
  ; if r1 % r3 == 0 then return 0
  mov r4, r1
  mod r4, r3
  ceq r4, 0
  cmov r1, 0
  cjnz %is_prime_end
  ; r3 += 2
  add r3, 2
  jmp %is_prime_loop
@is_prime_end
  pop r3
  ret

; Print the number in r1.
@print_number
  push r3
  mov r4, 0
  nav r1
  raw .[
  mov r3, r1
  mod r3, 10
  push r3
  div r1, 10
  inc r4
  nav r1
  raw .]
  nav r4
  raw .[
  dec r4
  pop r3
  add r3, .0
  out r3
  nav r4
  raw .]
  pop r3
  ret
