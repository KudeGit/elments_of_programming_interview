#include <iostream>
#include "../utils.hpp"

double pow (double a, int b)
{
    if (b == 0) {
        return 1.0;
    }

    if(b < 0) {
        a = 1.0/a;
        b *= -1;
    }

    if (b & 0x01) {
        return a * pow(a, b >> 1) * pow (a, b >> 1);
    } else {
        return pow(a, b >> 1) * pow (a, b >> 1);
    }
}


int main (void)
{
    double a = 2.0;
    int b = -2;

    std::cout << pow(a,b) << std::endl;
    return 0;
}
