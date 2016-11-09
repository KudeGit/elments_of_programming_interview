#include <iostream>
#include <vector>

#include "ch12.hpp"


int find_first_occurence2 (const std::vector<int>& A, const int el)
{
    int l = 0, r = A.size() - 1;
    auto res = -1;
    while (l <= r) {
        auto m = l + ((r - l) >> 1);
        if (A[m] >= el) {
            r  = m - 1; 
            if (A[m] == el) {
                res = m;
            }
        } else {
            l = m + 1;
        }
    }
    return res;
}

int find_first_occurence (const std::vector<int>& A,const int el)
{
    int l = 0, r = A.size() - 1;
    auto res = -1;
    while (l <= r) {
        auto m = l + ((r - l ) >> 1);
        if (A[m] > el) {
            r = m - 1;
        } else if (A[m] == el) {
            res = m; 
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}
