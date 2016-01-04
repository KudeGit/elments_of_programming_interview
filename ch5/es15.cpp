#include <iostream>
#include <algorithm>
#include <string>
#include "../utils.hpp"


size_t gdc (long long a, long long b)
{
    if(a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else if (!(a & 0x01ll) && !(b & 0x01ll)) {
        return gdc(a >> 1, b >> 1) << 1;
    } else if (a & 0x01ll && !(b & 0x01ll)) {
            return gdc(a, b >> 1);
    } else if (b & 0x01ll && !(a & 0x01ll)) {
        return gdc(a >> 1, b);
    } else if (a > b) {
        return gdc(a - b, b);
    } else {
        return gdc(a, b - a);
    }
}


int main (int argc, char* argv[])
{
    if(argc != 3) {
        error("usage: %s <a> <b>", argv[0]);
        return 1;
    }
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    std::cout << "gdc(" << a << ", " << b << "): " << gdc(a,b) << std::endl;
    return 0;
}
