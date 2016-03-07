#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.hpp"


template <class T>
int find_first (const std::vector<T>& A, const T target)
{
    int l = 0;
    int r = A.size() - 1;
    int candidate =  -1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] == target) {
            candidate = m;
            r = m -1;
        } else {
            if (A[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return candidate;
}

template <class T>
int find_last (const std::vector<T>& A, const T target)
{
    int l = 0;
    int r = A.size();
    int candidate = -1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] == target) {
            candidate = m;
            l = m + 1;
        } else {
            if (A[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return candidate;
}


int main (void)
{
    //                      0    1   2   3   4    5    6    7    8    9
    std::vector<int> A  = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};

    int k = find_first(A, 500);
    assert(k == -1);
    k = find_first(A, 108);
    assert(k == 3);
    k = find_first(A, 243);
    assert(k == 5);
    k = find_first(A, 285);
    assert(k == 6);

    k = find_last(A, 285);
    assert(k == 8);
    k = find_last(A, 401);
    assert(k == 9);
    k = find_last(A, 500);
    assert(k == -1);
    k = find_last(A, 108);
    assert (k == 4);
    k = find_last(A, -14);
    assert(k == 0);
    k = find_last(A, -100);
    assert(k == -1);


    return 0;
}
