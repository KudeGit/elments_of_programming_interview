#include <iostream>
#include <cstdint>

uint64_t reverse_bits (uint64_t a)
{
    uint64_t x = 0;
    constexpr int N = sizeof(a) * 8;
    for (int i = 0; i < N; ++i) {
        x <<= 1;
        x |= (a & 0x1lu);
        a >>= 1;
    }
    return x;
}
