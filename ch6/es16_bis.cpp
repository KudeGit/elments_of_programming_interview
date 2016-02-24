#include <iostream>
#include <vector>
#include <random>
#include "../utils.hpp"

template <class T>
void sample_off_line(std::vector<T> &data, const int k)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    for (int i = 0; i < k; ++i) {
        std::uniform_int_distribution<int> d(0, data.size() - 1 - i);
        int j = d(g);
        std::swap(data[j], data[data.size() - 1 - i]);
    }
    return;
}


int main (void)
{
    std::vector<int> A = {0,1,2,3,4,5,6,7,8,9,10};
    sample_off_line(A, 2);
    std::cout << A << std::endl;
    return 0;
}
