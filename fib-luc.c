#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
static mpz_t prev_fib, fib, luc;
void fib_luc(int n) {
  if (n == 0) return;
  if (n % 2) {
    fib_luc(n - 1);
    mpz_set(prev_fib, fib); mpz_mul_ui(prev_fib, prev_fib, 5);
    mpz_add(fib, fib, luc); mpz_tdiv_q_2exp(fib, fib, 1);
    mpz_add(luc, luc, prev_fib); mpz_tdiv_q_2exp(luc, luc, 1);
  } else {
    fib_luc(n >> 1);
    int k = (n >> 1) % 2 * 2 - 1;
    mpz_mul(fib, fib, luc);
    mpz_mul(luc, luc, luc);
    if (k < 0) mpz_sub_ui(luc, luc, -(k * 2));
    else       mpz_add_ui(luc, luc, k * 2);
  }
}
// ./fib 45000000 => 0.98s user 0.04s system
__attribute__((flatten)) int main(int argc, char * argv[]) {
  if (argc != 2) { printf("Usage: %s <n>\n", argv[0]);  return 1; }
  int exp; exp = strtol(argv[1], NULL, 10);
  if (exp < 0) { printf("Error.\n");  return 1; }
  mpz_init(prev_fib);  mpz_init(fib);  mpz_init(luc);
  mpz_set_ui(fib, 0);  mpz_set_ui(luc, 2);  fib_luc(exp);
  printf("F(%d) = ", exp); mpz_out_str(stdout, 10, fib); printf("\n");
}
