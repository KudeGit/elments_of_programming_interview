#include <iostream>
#include <vector>
#include "../utils.hpp"

bool parity(size_t a)
{
    int p = 0;
    while (a) {
        ++p;
        a &= (a - 1);
    }
    return (p & 0x1);
}


size_t look_up_parity_16(size_t a)
{
    static const size_t mask =  0x6996; //0000110010110
    size_t b = mask >> a;
    return b;
}

bool parityFast (size_t a)
{
    int n_bits = sizeof(size_t)*8;
    a ^= a >> 32;
    a ^= a >> 16;
    a ^= a >> 8;
    a ^= a >> 4;
    a &= 0xfllu;

    bool p =  (look_up_parity_16(a) & 0x01llu) == 0x01llu ;
    return p;


}


int main (void)
{
    std::vector<int> test = {0, 1, 2, 3, 4, 5, 7, 63, 64};
    std::vector<bool> res = {true, false, false, true, false, true, false, true, false};
    int i = 0;
    bool p = false;
    for (auto a: test) {
        if( (p = parityFast(a)) != !res[i]) {
            std::cout << "error with parity(" << a << ") returned " << p << " but expected " << !res[i] << std::endl;
        }
        ++i;
    }
}
