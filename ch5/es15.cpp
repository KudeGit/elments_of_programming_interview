#include <iostream>
#include <algorithm>


size_t GDC (size_t a, size_t b)
{
    if(a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return GDC(std::max(a,b) - std::min(a,b), std::min(a,b));
}
size_t GDCfast (size_t a, size_t b)
{
    if (b == 0) {return a;}
    if (a == 0) {return b;}
    if ((a & 0x01llu) && (b & 0x01llu)) {
        return GDCfast(a >> 1, b >> 1) << 1;
    } else if (a & 0x01llu) {
        return GDCfast(a >> 1, b);
    } else if (b & 0x01llu) {
        return GDCfast(a, b >> 1) << 1;
    } else {
        return  GDCfast(std::max(a,b) - std::min(a,b), std::min(a,b));
    }
}

int main (void)
{
    std::cout << GDCfast(10, 20) << std::endl;
    return 0;
}
