#include <iostream>
#include "../utils.hpp"

unsigned int divide (unsigned int a, unsigned int b)
{
    if (b > a) {
        return 0;
    }
    int res = 0;
    res += 1 + divide(a-b, b);
    return res; 
}


unsigned int divideFast (unsigned int a, unsigned int b)
{
    if (a < b) {
        return 0;
    } 
    int res = 0;
    // looking for k such that 2^k*y < x;
    unsigned int power = 1;
    while ( ((b << power) <= a)) {
        ++power;
    }
    res += (0x01u << (power-1)) + divideFast(a - (b << (power-1)), b);
    return res;
}


int main (void)
{
    int a = 93;
    int b = 5;
    std::cout << divideFast(a,b) << " == " << a/b << std::endl;
    return 0;
}
