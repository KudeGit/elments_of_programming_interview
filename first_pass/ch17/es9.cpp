#include <iostream>
#include <vector>
#include <numeric>
#include "../utils.hpp"


std::vector<std::vector<long long>> count_ways (const std::vector<int>& A, 
        const long long tot)
{
    std::vector<std::vector<long long>> K(tot + 1,
            std::vector<long long>(A.size() + 1, 0));

    //only one way to to reach 0
    K[0][0] = 1;

    for (int j = 0; j < A.size(); ++j) {
        for (int i = 1; i <= tot; ++i) {
            K[i][j+1] = K[i][j] +
                (A[j] <= i ? K[i - A[j]][j] : 0);
        }
    }
    return K;
}


long long is_tie_possible (const std::vector<int>& votes)
{
    auto tot = std::accumulate(votes.begin(), votes.end(), 0);
    if ((tot  & 0x01) != 0) {
        std::cout << "Tie is not possible " << std::endl;
        return 0;
    }
    auto ways = count_ways(votes, tot);
    return ways[tot >> 1].back();
}


int main (void)
{
    const std::vector<int> states = {
        { 9}, { 3},
        { 3}, { 5},
        { 11}, { 6},
        { 6}, { 4},
        { 55}, { 14},
        { 9}, { 5},
        { 7}, { 29},
        { 3}, { 15},
        { 29,}, { 3},
        { 16}, { 18},
        { 4}, { 7},
        { 4}, { 7},
        { 20}, { 20},
        { 11}, { 4},
        { 6}, { 9},
        { 6}, { 3},
        { 8}, { 11},
        { 8}, { 38},
        { 4}, { 6},
        { 10}, { 3},
        { 11}, { 13},
        { 16}, { 12},
        { 10}, { 5},
        { 6}, { 10},
        { 10}, { 3},
        { 3},
    };
    auto votes = is_tie_possible({2,2});
    debug(votes);
    return 0;
}
