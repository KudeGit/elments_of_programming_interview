#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cassert>
#include "../../utils.hpp"

int max_no_cycle(const std::vector<int>& A)
{
    int max_sum = std::numeric_limits<int>::min();
    int curr_sum = 0;
    for (auto& a: A) {
        curr_sum += a;
        max_sum = std::max(max_sum, curr_sum);
        curr_sum = std::max(curr_sum, 0);
    }
    return max_sum;
}
int max_cycle (const std::vector<int>& A)
{
    if (A.empty()) {
        return std::numeric_limits<int>::min();
    }
    auto curr_sum = 0;
    std::vector<int> max_sum_from_start(A.size(), 0);
    std::vector<int> max_sum_from_end(A.size(), 0);
    max_sum_from_start.front() = A.front();
    auto tot_max = std::numeric_limits<int>::min();

    for (int i = 1, curr_sum = A[0] >= 0 ? A[0] :0 ; i < A.size(); ++i) {
        curr_sum += A[i];
        max_sum_from_start[i] = std::max(curr_sum,max_sum_from_start[i-1]);
    }

    max_sum_from_end.back() = A.back();
    for (int i = A.size() - 2, curr_sum = A.back() > 0 ? A.back() : 0; i >= 0; --i) {
        curr_sum += A[i];
        max_sum_from_end[i] = std::max(curr_sum, max_sum_from_end[i+1]);
    }
    auto max_sum = std::numeric_limits<int>::min();
    for (int i = 0; i < A.size(); ++i) {
        max_sum = std::max(max_sum_from_start[i] + max_sum_from_end[i], max_sum);
    }
    return max_sum;
}


int max_subarray_circular (const std::vector<int>& A)
{
    return std::max(max_no_cycle(A), max_cycle(A));
}

void test()
{
    auto res = max_subarray_circular({10, 20 , 30, -50, 20, 0});
    assert (res == 80);
}

int main (void)
{
    test();
}
