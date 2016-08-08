#include <iostream>
#include <vector>
#include "utils.hpp"

bool get_next_perm(std::vector<int>& A)
{
    int k = A.size() - 2;
    while (k >= 0 && A[k] > A[k+1]) {
        --k;
    }
    if (k == -1) {
        return false;
    }
    int l = -1;
    for (int i = k + 1; i < A.size(); ++i) {
        if (A[i] > A[k]) {
            l = i;
        } else {
            break;
        }
    }
    std::swap(A[l], A[k]);
    std::reverse(A.begin() + k + 1, A.end());
    return true;
}


int main (void)
{
    std::vector<int> A = {1,2,3,4,5,6};
    bool next = false;
    int n = 1;
    do {
        std::cout << A << std::endl;
        next = get_next_perm(A);
        ++n;
    } while (next);
    debug(n);
    return 0;
}
