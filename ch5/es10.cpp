#include <iostream>
#include <string>
#include "../utils.hpp"

int reverseInteger (int n)
{
    int res = 0;
    bool is_neg = n < 0;
    if (is_neg) {
        n = -n;
    }
    while (n) {
        int d = n % 10;
        n /= 10;
        res = res*10 + d;
    }
    if (is_neg) {
        res = -res;
    }
    return res;
}

int main (int argc, char* argv[]) 
{
    if (argc != 2) {
        error("usage: %s <nuber>", argv[0]);
        return 0;
    }
    int n = std::stoi(std::string(argv[1]));
    int res = reverseInteger(n);
    std::cout << "The reverse of " << n << " is " << res << std::endl;
    return 1;
}
