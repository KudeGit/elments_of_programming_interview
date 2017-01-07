#include <iostream>
#include <vector>
#include "../../utils.hpp"


int remove_key (std::vector<int>& A, int target)
{
    auto k = 0;
    for (int i = 0; i < A.size() - k; ++i) {
        if (A[i] == target) {
            std::swap(A[i], A[A.size() - 1 - k]);
            ++k;
        }
    }
    for (; k>= 0; --k) {
        A.pop_back();
    }
    return A.size();
}
int remove_key2 (std::vector<int>&A, int target)
{
    auto j = 0;
    for (auto i = 0; i < A.size(); ++i) {
        if(A[i] != target) {
            A[j++] = A[i];
        }
    }
    while (A.size() > j) {
        A.pop_back();
    }
    return j;
}

int main (void)
{
    std::vector<int> A{5,3,7,11,2,3,13,5,7};
    debug(A);
    auto res = remove_key2(A, 3);
    debug(A);

}
