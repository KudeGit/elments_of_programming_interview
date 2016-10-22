#include <iostream>
#include <cmath>
#include <string>
#include "../utils.hpp"


bool isNPalindorme (int n)
{
    int n_digits = static_cast<int>(log10(n)) + 1;
    int msd_mask = static_cast<int>(pow(10, n_digits-1));
    int nn = n;
    for (int i = 0; i < n_digits >> 1; ++i) {
        int lsd = n % 10;
        n /= 10;
        int msd = nn / msd_mask;
        nn %= msd_mask;
        msd_mask /= 10;
        if(lsd != msd) {
            return false;
        }
    }
    return true;
}



int main (int argc, char* argv[]) 
{
    if (argc != 2) {
        error("usage: %s <number>", argv[0]);
        return 1;
    }
    int n = std::stoi(std::string(argv[1]));

    std::cout << n << " is palindrome? " << isNPalindorme(n) << std::endl;
}
