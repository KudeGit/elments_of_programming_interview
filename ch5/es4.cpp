#include <iostream>
#include <stdexcept>

unsigned long findClosest(unsigned long a)
{
    for (int i = 0; i < 63; ++i) {
        if (((a >> i) & 0x1LU) ^ ((a >> (1+i)) & 0x1LU)) {
            a ^= (0x1LU << i) | (0x1LU << (i+1));
            return a;
        }
    }
    throw std::invalid_argument("all bits are 1 or 0");
}


int main (void)
{
    size_t a = 0;
    try {
        int b = findClosest(a);
        std::cout << "The closest to " << a << " with the same weight is " << b << std::endl;
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
    return 0;
}
