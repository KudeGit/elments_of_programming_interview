#include <iostream>
#include <vector>
#include <cassert>

int find_idx_equal_val (const std::vector<int>& A)
{
    int l = 0;
    int r = A.size();
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] == m) {
            return m;
        } else {
            if (A[m] > m) {
                 r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return -1;
}


int main (void)
{
    //                      0  1  2  3  4  5  6
    std::vector<int> A1 = {-2, 0, 2, 3, 6, 7, 9};
    std::vector<int> A2 = {-2, 0, 2, 4, 6, 7, 9};
    std::vector<int> A3 = {-2, 0, 1, 4, 6, 7, 9};
    int k = find_idx_equal_val(A1);
    assert(k == 2 || k == 3);
    k = find_idx_equal_val(A2);
    assert(k == 2);
    k = find_idx_equal_val(A3);
    assert(k == -1);
    return 0;

}
