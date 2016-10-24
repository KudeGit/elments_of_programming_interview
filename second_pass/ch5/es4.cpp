#include <iostream>
#include <cstdint>
#include <stdexcept>

uint64_t find_closest_same_weight (uint64_t a)
{
    for (int i = 0; i < 63; ++i) {
        if (((a >> i) & 0x1ul) != ((a >> (i+1)) & 0x01lu)) {
            return a ^ ((0x01lu << i) |( 0x01 << (i+1)));
        }
    }
    throw std::invalid_argument("all bits are 0 or 1");
}
