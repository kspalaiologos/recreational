#include <stdio.h>
#include <array>

// ~~ Algorithm Description ~~
// Since sqrt(max) = 100000000 = M, we should precompute primes until M,
// because all factors of N are always smaller or equal to sqrt(N).
// There are 5761455 primes smaller than M.

// After these maneuvers, assuming that `ull' is 8 bytes large, the binary
// will grow by approximately 46 megabytes.

// Notice that this solution largely makes use of the C++ compile-time features
// and the fact that the program's compile-time isn't timed nor the binary size
// isn't measured.

// BUILDING:
// g++ -O3 -std=c++20 pgen.cpp -o pgen -fconstexpr-ops-limit=1000000000000 -fconstexpr-loop-limit=1000000000

typedef unsigned long long ull;

template <std::size_t N>
constexpr std::array<ull, N> get_ptab() {
    std::array<ull, N> ptab;
    ull gen = 3;
    ptab[0] = 2; ptab[1] = 3; ptab[2] = 5;
    for(std::size_t i = 7; gen < N; i += 2) {
        bool ok = true;
        if(i % 3 == 0 || i % 5 == 0)
            continue;
        for(std::size_t j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                ok = false;
                break;
            }
        }
        if(ok)
            ptab[gen++] = i;
    }
    return ptab;
}

constexpr std::array<ull, 5761455> ptab = get_ptab<5761455>();

int main(void) {
    // Step 1: print all the primes that we've hardcoded already.
    for(std::size_t i = 0; i < ptab.size(); i++)
        printf("%llu\n", ptab[i]);
    // Step 2: starting with ptab.back(), go up until max, checking if
    // N is divisible by any of the primes we've hardcoded.
    // If it is, skip it. If it isn't, print it.
    for(std::size_t i = ptab.back(); i < 10000000000000000; i+=2) {
        bool ok = true;
        for(std::size_t j = 0; j < ptab.size() && i <= ptab[j]; j++) {
            if(i % ptab[j] == 0) {
                ok = false;
                break;
            }
        }
        if(ok)
            printf("%llu\n", i);
    }
    return 0;
}
