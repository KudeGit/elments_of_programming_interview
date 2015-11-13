#include <iostream>
#include <vector>
#include "../utils.hpp"


int find_first_missing_int (std::vector<int>& A)
{
    size_t i = 0;
    while (i < A.size()) {
        if (A[i] <  A.size() && A[i] >= 0 && A[A[i]] != A[i] && A[i] != i) {
            std::swap(A[i], A[A[i]]);
        } else {
            ++i;
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        if(A[i] != i) {
            return i;
        }
    }
    return A.size();
}



int main (void)
{
    std::vector<int> A({1,3,4,2,0});
    std::cout << find_first_missing_int(A) << std::endl;
    return 0;
}
