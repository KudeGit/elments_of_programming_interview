#include <iostream>
#include <vector>

int search_identity (const std::vector<int>& A)
{
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        auto m = l + ((r-l)>>2);
        if (A[m] < m) {
            l = m + 1;
        } else if (A[m] == m){
            return m;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
