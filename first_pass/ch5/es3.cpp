#include<iostream>
#include "bit.hpp"

size_t reverse (const size_t& a)
{
    size_t res = 0;
    for (size_t i = 0; i < sizeof(a)*8; ++i) {
        res |=  ((a >> i) & 0x01llu) << (sizeof(a)*8 - i - 1);
    }
    return res;
}

int main (void)
{
    size_t a  = 24;
    printBit(a);
    printBit(a-1);
    printBit(a & (a-1));
    printBit(a & ~(a-1));
    //size_t b = reverse(a);
    //printBit(b);
    return 0;
}
