#include <iostream>


int reverseDigits (int k)
{
    bool is_negative = false;
    int res = 0;
    if (k  < 0) {
        is_negative = true;
        k *= -1;
    }
    while (k) {
        res = res*10 + (k%10);
        k /= 10;
    }
    res = (is_negative) ? -res : res;
    return res;
}


int main (void)
{
    int a = 1249;
    int b = -1249;
    std::cout << a << " => " << reverseDigits(a) << std::endl;
    std::cout << b << " => " << reverseDigits(b) << std::endl;
    return 0;
}
