#include <iostream>


template <class T>
int sum (T a, T b)
{
    if (b == 0) {
        return a;
    }
    T carry = (a & b) << 1;
    return sum (a^b, carry);
}

unsigned int multuply (unsigned int a, unsigned int b)
{
    unsigned int res = 0;
    while (b) {
        if(b & 0x01u) {
            res = sum(res,a);
        }
        b >>= 1;
        a <<= 1;
    }
    return res;
}

int main (void)
{
    unsigned int a = 2;
    unsigned int b = 5;
    std::cout << sum(a,b) << " == " << a + b << std::endl;
    std::cout << multuply(a,b) << " == " << a*b << std::endl;
    return 0;

}
