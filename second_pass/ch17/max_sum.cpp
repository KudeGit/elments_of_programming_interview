#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cassert>
#include "../../utils.hpp"

std::pair<int, int> find_max_subarray (const std::vector<int>& A)
{
    std::pair<int,int> idx{0,0};
    long curr_sum  = 0, max_sum = std::numeric_limits<long>::min();
    int cfirst = -1, max_first = -1, max_last = -1;
    for (int i = 0; i < A.size(); ++i) {
        curr_sum += A[i];
        if (curr_sum > max_sum) {
            max_first = cfirst+1;
            max_last = i;
            max_sum = curr_sum;
        }
        if (curr_sum <= 0) {
            curr_sum = 0;
            cfirst = i;
        }
    }
    return {max_first, max_last};
}

void test()
{
    auto res = find_max_subarray({904, 40, 253, 12, -335, -385, -124, 481, -31});
    assert(res.first == 0 && res.second == 3);

    res = find_max_subarray({-904, -40, -253, -12, -335, -385, -124, -481, -31});
    assert(res.first == 3 && res.second == 3);

    res = find_max_subarray({});
    assert(res.first == -1 && res.second == -1);

    res = find_max_subarray({904, 40, 253, 12, -335, -3850, -124, 481000, -31});
    assert(res.first == 7 && res.second == 7);
}

int main (void)
{
    test();
}
