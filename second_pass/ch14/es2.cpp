#include <iostream>
#include <vector>


void merge_in_place (std::vector<int>& A, int NA, const std::vector<int>& B)
{
    if (A.size () != NA + B.size()) {
        throw std::logic_error("cannot merge in place... array size mismatch");
    }
    int i = NA-1, j = B.size() - 1, k = A.size() - 1;
    while (i >=0  && j >= 0) {
        if (A[i] >= B[j]) {
            A[k] = A[i--];
        } else {
            A[k] = B[j--];
        }
        --k;
    }
    while (i >= 0) {
        A[k--] = A[i--];
    }
    while (j >= 0) {
        A[k--] = B[j--];
    }
}
