#include <iostream>
#include <vector>
#include "../../utils.hpp"


int count_steps(int n, int k)
{
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    auto res = 0;
    for (int i = 1; i <= std::min(n,k); ++i) {
        res += count_steps(n-i,k);
    }
    return res;
}

int main (void)
{
    auto res = count_steps(4, 2);
    debug(res);
    return 0;
}
