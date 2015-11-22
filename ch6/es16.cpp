#include <iostream>
#include <random>

    template <class T>
std::vector<T> sample(std::vector<T> A, int k)
{
    std::default_random_engine g;
    for (int i = 0 ; i < k; ++i) {
        std::uniform_int_distribution<int> d(0,A.size());
        int index = d(g);
        std::swap(A[index], A.back());
        A.pop();
    }
    return A;
}


int main (void)
{
    return 0;
}
