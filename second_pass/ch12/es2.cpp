#include <iostream>
#include <vector>
#include "ch12.hpp"

int find_first_largest(const std::vector<int>& A, const int el)
{
    int l = 0, r = A.size() - 1;
    int res = -1;
    while (l <= r) {
        auto m = l + ((r - l) >> 1);
        if (A[m] > el) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}
