#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <cassert>
#include "../../utils.hpp"


template <class T>
void apply_permutation (std::vector<T>& A, std::vector<int>& P)
{
    for (auto i = 0; i < A.size(); ++i) {
        auto a = A[i];
        auto p_idx = i;
        while (P[p_idx] >= 0) {
            auto next_a = A[P[p_idx]];
            A[P[p_idx]] = a;
            auto next_p_idx = P[p_idx];
            P[p_idx] -= P.size();
            p_idx = next_p_idx;
            a = next_a;
        }
    }
    for (auto& p: P) {
        p += P.size();
    }
}


template <class T>
std::vector<T> apply_permutation_stupid(const std::vector<T>& A, const std::vector<int>& P)
{
    auto res = A;
    for (int i = 0; i < A.size(); ++i) {
        res[P[i]] = A[i];
    }
    return res;
}

template <class T>
bool operator== (const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}



int main (void)
{
    std::vector<char> A(77);
    std::vector<int> P(A.size());
    std::iota(P.begin(), P.end(), 0);
    std::iota(A.begin(), A.end(), '0');
    for (int i = 0; i < 100; ++i) {
        auto original = A;
        std::random_shuffle(P.begin(), P.end());
        auto expexted = apply_permutation_stupid(A, P);
        apply_permutation(A, P);
        assert(expexted == A);
    }


    return 0;

}
