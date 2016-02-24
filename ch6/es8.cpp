#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include "../utils.hpp"



int find_max_diff (const std::vector<int> &A)
{
    int max_diff = 0; 
    int c_min = A[0];
    for (const auto &a: A) {
        max_diff = std::max(max_diff, a - c_min);
        c_min = std::min(c_min, a);
    }
    return max_diff;
}

int find_max_diff_2 (const std::vector<int>& A)
{
    std::vector<int> max_f(A.size(), std::numeric_limits<int>::min());
    std::vector<int> max_b(A.size(), std::numeric_limits<int>::min());
    int c_min = A[0];
    int max_diff = std::numeric_limits<int>::min();
    for (int i = 0; i < A.size(); ++i) {
        max_diff = std::max(max_diff, A[i] - c_min);
        c_min = std::min(c_min, A[i]);
        max_f[i] = max_diff;
    }
    int c_max = A.back();
    c_min = A.back();
    max_diff = std::numeric_limits<int>::min();
    for (int i = A.size() - 1; i >= 0; --i) {
        if(A[i] > c_max) {
            c_max = A[i];
            c_min = A[i];
        }
        c_min = std::min(c_min, A[i]);
        max_diff = std::max(max_diff, c_max - c_min);
        max_b[i] = max_diff;
    }
    max_diff = std::numeric_limits<int>::min();
    debug(max_f);
    debug(max_b);
    for (int i = 1; i < A.size() - 1; ++i) {
        max_diff = std::max(max_diff, 
                std::max(max_f[i-1] + max_b[i], max_f[i] + max_b[i+1]));
    }
    return max_diff;
}

int find_max_diff_k (const std::vector<int>& A, int k)
{
    std::vector<int> sum_k(k << 1, std::numeric_limits<int>::min());
    for (int i = 0; i < A.size(); ++i) {
        std::vector<int> pre_sum_k(sum_k);
        for(int j = 0, sign = -1; j < sum_k.size() && j <= i; ++j, sign *= -1) {
            int diff = sign * A[i] + (j == 0 ? 0 : pre_sum_k[j-1]);
            sum_k[j] = std::max(pre_sum_k[j], diff);
        }
    }
    return sum_k.back();
}

int find_max_diff_any_k (const std::vector<int>& A) 
{
    int profit = 0;
    int buy = A[0];
    for (int i = 1; i < A.size() - 1; ++i) {
        if (A[i]< A[i-1] && A[i] <= A[i+1]) {
            buy = A[i];
        } else if(A[i] >= A[i-1] && A[i] > A[i+1]) {
            profit += A[i] - buy;
            buy = A[i+1];
        }
    }
    if(buy < A.back()) {
        profit += A.back() - buy;
    }
    return profit;
}

int main (void)
{
    std::vector<int> A = {2, 3, 10, 6, 4, 8, 1};
    std::vector<int> B = {7, 9, 5, 6, 3, 2};
    std::vector<int> C = {1,2,3,4,5,6,7,8,9,10};

    std::cout << A << std::endl;
    std::cout << find_max_diff(A) << std::endl;
    std::cout << find_max_diff_k(A,1) << std::endl;

    std::cout << B << std::endl;
    std::cout << find_max_diff_2(B) << std::endl;
    std::cout << find_max_diff_k(B,2) << std::endl;


    return 0;
}
