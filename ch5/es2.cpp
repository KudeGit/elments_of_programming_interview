#include <iostream>
#include "../utils.hpp"
#include "bit.hpp"

void swapBit (size_t& a, size_t i, size_t j)
{
    if (((a>>i) & 0x01llu) == ((a>>j) & 0x01llu)) {
        return;
    }
    bool ith_bit = getBit(a, i);
    bool jth_bit = getBit(a, j);
    setBit(a, i, jth_bit);
    setBit(a, j, ith_bit);
    return;
}


int main (void)
{
    size_t a = 32;
    printBit(a);
    std::cout << a << std::endl;
    swapBit(a, 5, 0);
    std::cout << a << std::endl;
    return 0;
}
