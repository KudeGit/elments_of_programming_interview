#include <iostream>
#include <vector>
#include "../utils.hpp"


int longest_increasing_subsequence (const std::vector<int>& A)
{
    std::vector<int> K(A.size(), 1);
    for (int i = 1; i < A.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            K[i] = std::max(A[j] <= A[i] ?  K[j] + 1 : 0, K[i]);
        }
        debug(K);
    }
    return K.back();
}

int main (void)
{
    std::vector<int> A = { 10, 22, 9, 33, 21, 50, 41, 60 };
    auto lis = longest_increasing_subsequence(A);
    std::cout << lis << std::endl;
    return 0;
}
