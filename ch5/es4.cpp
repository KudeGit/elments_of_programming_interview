#include <iostream>

size_t findClosest(size_t a)
{
    for (size_t i = 0; i < sizeof(a)*8-1; ++i) {
        if ( ((a>>i) & 0x01llu) != ((a>> (i+1)) & 0x01llu)) {
            a ^= (0x01llu << i) | (0x01 << (i+1));
            break;
        }
    }
    return a;
}


int main (void)
{
    size_t a = 3;
    std::cout << "The closest to " << a << " with the same weight is " << findClosest(a) << std::endl;
    return 0;
}
