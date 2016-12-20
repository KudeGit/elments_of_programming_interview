#include <iostream>
#include <vector>
#include "../../utils.hpp"
#include <cassert>

int count(const int n, std::vector<int>& T)
{
    if (n == 0) {
        return 1;
    }
    if (T[n] != -1) {
        return T[n];
    }
    auto k = 0;
    for (int i = 1; i <= n; ++i) {
        k += count(i-1, T)*count(n - i, T);
    }
    T[n] = k;
    return k;
}


int count(const int n)
{
    std::vector<int> T(n+1, -1);
    return count(n, T);
}


void test()
{
    assert(count(1) == 1);
    assert(count(2) == 2);
    assert(count(3) == 5);
}

int main (void)
{
    test();
    return 0;
}
