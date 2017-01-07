#include <iostream>
#include <vector>
#include "../../utils.hpp"


void get_next_permutation (std::vector<int>& A)
{
    int i = A.size() - 2;
    while (i >= 0 && A[i] >= A[i+1]) --i;
    if (i == -1) {
        return;
    }
    auto l = i, k = i;
    for (i = l+1; i < A.size(); ++i) {
        if(A[i] > A[l]) {
            k = i;
        } else {
            break;
        }
    }
    std::swap(A[l], A[k]);
    std::reverse(A.begin()+l+1, A.end());
}


int main (void)
{
    std::vector<int> A = {1,5,1};
    get_next_permutation(A);
    debug(A);
    return 0;
}
