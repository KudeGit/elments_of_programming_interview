#include <iostream>
#include <vector>
#include <utility>
#include "../../utils.hpp"



int countInversionSimple (std::vector<int>& A)
{
    auto inv_count = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i+1; j < A.size(); ++j) {
            //debug(std::make_pair(i,j));
            //debug(std::make_pair(A[i],A[j]));
            inv_count += (A[j] < A[i]) ? 1 : 0;
        }
    }
    return inv_count;
}


static
int merge (std::vector<int>& A,
        std::vector<int>& _A,
        const int l, const int m, const int r)
{
    //debug(l);
    //debug(m);
    //debug(r);
    auto i = l, j = m+1, k = l;
    auto invs = 0;
    while (i <= m && j <= r) {
        if (A[i] <= A[j]) {
            _A[k++] = A[i++]; //no inversion
        } else {
            //debug(std::make_pair(i, A[i]));
            //debug(std::make_pair(j, A[j]));
            _A[k++] = A[j++]; //inversion
            invs += m - i + 1;
        }
    }
    while (i <= m) {
        _A[k++] = A[i++];
    }
    while (j <= r) {
        _A[k++] = A[j++];
    }
    for (int i = l; i <= r; ++i) {
        A[i] = _A[i];
    }
    //debug(invs);
    return invs;
}

static
int countInversion (std::vector<int>& A,
                    std::vector<int>& _A,
                    const int l, const int r)
{
    if (l >= r) {
        return 0;
    }
    auto m = l + ((r-l) >> 1);
    auto inv_left  = countInversion(A, _A, l, m);
    auto inv_rigth = countInversion(A, _A, m+1, r);
    auto inv_merge = merge(A,_A,l, m, r);
    //debug(A);

    return inv_left + inv_rigth + inv_merge;

}


int countInversion (std::vector<int>& A)
{
    std::vector<int> _A(A.size());
    return countInversion(A,_A, 0, A.size() - 1);
}

//int main (void)
//{
//    std::vector<int> A{1, 20, 6, 4, 5};
//    auto invs = countInversion(A);
//    std::cout << invs << std::endl;
//    return 0;
//}
