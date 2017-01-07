#include <iostream>
#include <vector>
#include <random>
#include "../../utils.hpp"


template <class T>
void offline_random_sampling2 (std::vector<T>& A, int k)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < k; ++i) {
        std::uniform_int_distribution<int> d(i,A.size() - 1);
        std::swap(A[i], A[d(gen)]);
    }
    A.resize(k);
}


int main (void)
{
    std::vector<int> A{1,2,3,4,5,6,7,8,9,0};
    offline_random_sampling2(A, 2);
    debug(A);
    return 0;
}
