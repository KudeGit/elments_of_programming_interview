#include <iostream>
#include <vector>
#include "ch6.hpp"

void dutch_flag (std::vector<int>& A, const size_t l)
{
    if (l >= A.size()) {
        throw std::invalid_argument("index outsize boundaries");
    }

    auto pivot = A[l];
    for (int i =0, j = 0, k=0; i < A.size(); ++i) {
        if (A[i] < pivot) {
            std::swap(A[i],A[k]);
            std::swap(A[j++],A[k++]);
        } else if (A[i] == pivot) {
            std::swap(A[i], A[k++]);
        }
    }
}
