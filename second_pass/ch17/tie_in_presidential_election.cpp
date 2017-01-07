#include <iostream>
#include <vector>
#include <numeric>
#include "../../utils.hpp"
#include <cassert>


bool is_tie_possible (const std::vector<int>& votes)
{
    long tot_votes = std::accumulate(votes.begin(), votes.end(), 0);
    if (tot_votes & 0x01l) {
        //it's odd, not tie possible
        return false;
    }
    std::vector<std::vector<long>> K(votes.size() + 1, std::vector<long>(tot_votes+1, 0));
    K[0][0]=1;

    int i = 1;
    for (auto& v: votes) {
        for (int j = 1; j <= tot_votes; ++j) {
            K[i][j] = K[i-1][j];
            if (j >= v) {
                K[i][j] += K[i-1][j - v];
            }
        }
        ++i;
    }
    return K[votes.size()][tot_votes >> 1] > 0;
}

void test()
{
    auto res = is_tie_possible({2,2});
    assert(res == true);

    res = is_tie_possible({2,2,2});
    assert(res == false);
}

int main (void)
{
    test();
    const std::vector<int> states = {
         9,  3,
         3,  5,
         11,  6,
         6,  4,
         55,  14,
         9,  5,
         7,  29,
         3,  15,
         29,  3,
         16,  18,
         4,  7,
         4,  7,
         20,  20,
         11,  4,
         6,  9,
         6,  3,
         8,  11,
         8,  38,
         4,  6,
         10,  3,
         11,  13,
         16,  12,
         10,  5,
         6,  10,
         10,  3,
         3,
    };
    auto tie = is_tie_possible(states);
    debug(tie);
    return 0;

}
