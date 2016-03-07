#include <iostream>
#include <vector>
#include <tuple>
#include "../utils.hpp"
#include <stdexcept>


template <class T>
std::tuple<T, T> minmax (const T& a, const T& b)
{
    return (a > b) ? std::make_tuple(b, a) : std::make_tuple(a, b);
}

template <class T>
std::tuple<T, T> find_min_max (const std::vector<T> &A)
{
    if (A.empty()) {
        throw std::logic_error("cannot comupte min max on an empty array");
    }
    if (A.size() == 1) {
        return std::make_tuple(A.front(), A.front());
    }
    auto res = minmax(A[0], A[1]);
    for (int i = 2; i < A.size(); i += 2) {
        auto tmp = minmax(A[i], A[i + 1]);
        res = std::make_tuple(std::min(std::get<0>(res), std::get<0>(tmp)),
                std::max(std::get<1>(res), std::get<1>(tmp)));
    }
    if (A.size() & 1) {
        res = std::make_tuple(std::min(std::get<0>(res), A.back()),
                std::max(std::get<1>(res), A.back()));
    }
    return res;
}


int main (void)
{
    std::vector<int> A = {0 ,1 ,2, 3, 4, 5, 6, 7, 9, 10};
    auto res = find_min_max(A);
    std::cout << res << std::endl;
    return 0;
}
