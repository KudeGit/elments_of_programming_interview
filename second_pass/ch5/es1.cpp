#include <iostream>
#include <cstdint>
#include "ch1.hpp"
#include "../../utils.hpp"

bool parity_bit_slow(uint64_t a)
{
    int n = 0;
    while (a) {
        a &= (a-1);
        ++n;
    }
    return n & 0x1lu;
}

bool parity_bit_fast(uint64_t a)
{
    const uint16_t mask = 0x6996;
    a ^= (a>>32);
    a ^= (a>>16);
    a ^= (a>>8);
    a ^= (a>>4);
    a &= 0xflu;
    auto res  = (((mask >> a) & 0x01lu) == 0x1lu);
    return res;
}


