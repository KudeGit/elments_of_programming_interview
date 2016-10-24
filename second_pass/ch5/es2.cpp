#include <iostream>
#include <cstdint>
#include "ch1.hpp"

uint64_t swap_bit(uint64_t a, const int i, const int j)
{
    auto bit_i = (a >> i) & 0x1lu;
    auto bit_j = (a >> j) & 0x1lu;
    return (bit_i == bit_j) ?
            a : a ^ (((1 << j) | (1 << i)));
}
