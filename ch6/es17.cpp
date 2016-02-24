#include <iostream>
#include <random>
#include <vector>
#include "../utils.hpp"

template <class T> 
void compute_rand_permutation (std::vector<T> &A)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    for (int i = 0; i < A.size(); ++i) {
        std::uniform_int_distribution<> d(0, A.size() - 1 - i);
        std::swap(A[d(g)], A[A.size() - 1 - i]);
    }
}

