#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Cmp{
    bool operator() (const int a, const int b) {
        return fabs(a - _m) < fabs(b - _m);
    }
    double _m;
};

double find_median(std::vector<int>& A)
{
    int half = A.size() >> 1;
    nth_element(A.begin(), A.begin() + half, A.end());
    if (A.size() & 0x01) {
        return A[half];
    } else {
        auto x = A[half];
        nth_element(A.begin(), A.begin() + half-1, A.end());
        return 0.5 * (x + A[half-1]);
    }
}


std::vector<int> find_k_closest_to_median (std::vector<int>& A, const int k)
{
    Cmp cmp{find_median(A)};
    std::nth_element(A.begin(), A.begin() + k, A.end(), cmp);
    return {A.begin(), A.begin() + k};
}
