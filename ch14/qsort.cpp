#include <iostream>
#include <vector>
#include <random>
#include "../utils.hpp"




template <class T>
long partition (std::vector<T>& A, long start, long end)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<long> d(start, end);
    long pivot = d(g);
    std::swap(A[start], A[pivot]);
    pivot = start;
    long j = start + 1;
    for (long i = start + 1; i <= end; ++i) {
        if(A[i] <= A[pivot]) {
            std::swap(A[i], A[j]);
            ++j;
        }
    }
    std::swap(A[--j], A[pivot]);
    return j;
}

template <class T>
void qsort (std::vector<T>& A, long start, long end)
{
    if (start >= end) {
        return;
    }
    //debug(A);
    //debug(start); debug(end);
    auto pivot = partition(A, start, end);
    qsort(A, start, pivot - 1);
    qsort(A, pivot + 1, end);
}

template <class T>
void qsort (std::vector<T>& A)
{
    qsort (A, 0, A.size() - 1);
}



int main (void)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(0, 10);
    std::vector<int> A;
    for (int i = 0; i < 10; ++i) {
        A.emplace_back(d(g));
    }
    std::cout << A << std::endl;
    qsort(A);
    //partition(A, 0, A.size() - 1);
    std::cout << A << std::endl;
    return 0;
}
