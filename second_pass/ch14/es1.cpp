#include "ch14.hpp"
#include <iostream>
#include <vector>


std::vector<int> unique_elements_in_sorted_array (const std::vector<int>& A)
{
    std::vector<int> unique_el{};
    int i = 0;
    while (i < A.size()) {
        while (i == 0 || (i < A.size() && A[i] != A[i - 1])) {
            unique_el.emplace_back(A[i++]);
        }
        ++i;
    }
    return unique_el;
}


//tested on leecode
std::vector<int> compute_intersection(const std::vector<int>& A, const std::vector<int>& B)
{
    int i = 0; int j = 0;
    std::vector<int> intersection{};
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j] && (i == 0 || A[i] != A[i-1])) {
            intersection.emplace_back(A[i]);
            ++i; ++j;
        } else if (A[i] < B[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return intersection;
}
