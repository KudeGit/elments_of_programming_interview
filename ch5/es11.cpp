#include <iostream>
#include <cmath>
#include "../utils.hpp"

bool isNPalindorme (const int n)
{
    if (n < 0) {
        return false;
    }
    int n_digits = static_cast<int>(std::log10(n))  + 1;
    int n2 = n_digits/2;
    int low = n % static_cast<int>(std::pow(10, n2 ));
    int high = n / static_cast<int>(std::pow(10, n_digits - n2));

    for (int i = 0; i < n2; ++i) {
        if ( (low % 10) != (high/static_cast<int>(pow(10, n2 - i - 1)))) {
            return false;
        }
        low /= 10;
        high %= static_cast<int>(pow(10, n2 - i - 1));
    }
    return true;
}


int main (void)
{
    std::cout << isNPalindorme(123454321) << std::endl;
    std::cout << isNPalindorme(1234554321) << std::endl;
    std::cout << isNPalindorme(1234554320) << std::endl;
    return 0;
}
