#include <iostream>
#include "bit.hpp"



bool getBit (size_t &a, size_t pos)
{
    return  ((a >> pos) & 0x01llu) != 0x00llu;
}

void setBit (size_t &a, size_t pos, bool val)
{
    if (val) {
        a |= (0x01llu << pos);
    } else {
        a &= ~(0x01llu << pos);
    }
}

void printBit (const size_t& a)
{
    bool first = true;
    for (size_t i = 0; i < 8*sizeof(a); ++i) {
        size_t mask = 0x01llu << i;
        if (first) {
            std::cout << ((a & mask) != 0);
            first = false;
        } else {
            std::cout << ", " << ((a & mask) != 0);
        }
    }
    std::cout << std::endl;
}


int test (void)
{
    size_t a = 0;
    for (size_t i = 0; i < 8*sizeof(a); ++i) {
        setBit(a, i, true);
        if (a != (0x01llu << i)) {
            std::cout << "error setting bit " << i << " to true " << std::endl;
        }
        printBit(a);
        a = 0;
    }
    return 0;
    a = ~0;
    for (size_t i = 0; i < 8*sizeof(a); ++i) {
        setBit(a, i, false);
        if (a != (~(0x01llu << i))) {
            std::cout << "error setting bit " << i << " to true " << std::endl;
        }
        a = ~0;
    }

    return 0;
}
