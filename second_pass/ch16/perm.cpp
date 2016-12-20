#include <iostream>
#include <vector>
#include "../../utils.hpp"


int nextPermutation(std::vector<int>& A) {
    int i = A.size() - 2;
    while (i >= 0 && A[i] >= A[i+1]) --i;
    if (i < 0) {
        std::reverse(A.begin() + i + 1, A.end());
        return -1;
    }

    auto candidate_idx = -1;
    for (auto l = i + 1; l < A.size(); ++l) {
        if (A[l] > A[i]) {
            candidate_idx = l;
        } else {
            break;
        }
    }
    std::swap(A[i], A[candidate_idx]);
    std::reverse(A.begin() + i + 1, A.end());
    return 0;
}

void printAllPerm (std::vector<int>& A, const int k)
{
    if (k == A.size()) {
        std::cout << A << std::endl;
        return;
    }
    for (int i = k; i < A.size(); ++i) {
        std::swap(A[k], A[i]);
        printAllPerm(A, k+1);
        std::swap(A[k], A[i]);
    }
}
void printAllPerm (std::vector<int> A)
{
    return printAllPerm(A,0);
}

int main (void)
{
    std::vector<int> A{1,5,1};
//    printAllPerm(A);
    nextPermutation(A);
    debug("Using next perm");
    std::cout << A << std::endl;
    return 0;
}
