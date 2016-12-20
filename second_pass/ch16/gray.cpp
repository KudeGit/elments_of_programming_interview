#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.hpp"

int flip_bit (int a, int pos)
{
    return (a ^ (0x1 << pos));
}

void gray_helper (int n, int& a, std::vector<int>& codes)
{
    if (n == 0) {
        codes.emplace_back(a);
        return;
    }
    gray_helper(n-1, a, codes);
    a = flip_bit(a, n-1);
    gray_helper(n-1, a, codes);
}

int count_ones (int n)
{
    int c = 0;
    while (n) {
        n &= n-1;
        ++c;
    }
    return c;
}

std::vector<int> gray (int n)
{
    int a = 0;
    std::vector<int> codes;
    gray_helper(n, a, codes);
    return codes;
}

bool verify_code (const std::vector<int>& code)
{
    for (int i = 1; i < code.size();++i) {
        if (count_ones(code[i] ^ code[i-1]) != 1) {
            std::cout << code[i] << " and " << code[i-1] << " differs for more than one bit" << std::endl;
            return false;
        }
    }
    return true;
}

void test()
{
    assert(verify_code({0,1,3,2,6,7,5,4}));
    for (int i = 1; i < 10; ++i)
        assert(verify_code(gray(1)));
}

int main (void)
{
    test();
    return 0;
}
