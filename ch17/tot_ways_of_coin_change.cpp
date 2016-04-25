#include <iostream>
#include <vector>
#include "../utils.hpp"


int count_ways_rec (int tot, int i, const std::vector<int> A)
{
    if (tot < 0 || i < 0) {
        return 0;
    }
    if (tot == 0) {
        return 1;
    }
    return count_ways_rec(tot, i - 1, A) +
        count_ways_rec(tot - A[i], i, A);
}


int count_ways (const int tot, const std::vector<int>& A)
{
    std::vector<int> K(tot+1, 0);
    K[0] = 1;
    for (const auto& a: A) {
        for (int n = a; n <= tot; ++n) {
            K[n] += K[n - a];
        }
    }
    return K.back();
}

int main (void) 
{
    const std::vector<int> A = {2, 3, 7};
    auto res1 = count_ways(12, A);
    auto res2 = count_ways_rec(12, A.size() - 1, A);

    debug(res1);
    debug(res2);
    return 0;

}
