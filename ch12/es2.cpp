#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.hpp"


template <class T>
int find_first_larger_than (const std::vector<T>& A, const T& K)
{
    int l = 0, r = A.size() - 1;
    int candidate = -1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] > K) {
            candidate = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return candidate;
}



int main (void)
{
    std::vector<int> A  = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    int a = find_first_larger_than(A, 500);
    assert(a == -1);
    a = find_first_larger_than(A, 101);
    assert(a == 3);
    
    banner("ALL GOOD");
    return 0;



}
