#include <iostream>
#include <vector>
#include "../utils.hpp"


int find_max_diff_helper(const std::vector<int>& coins,
        int a, int b, std::vector<std::vector<int>>& K)
{
    if (a > b) {
        return 0;
    }
    if(K[a][b] != -1) {
        return K[a][b];
    }
    K[a][b] = std::max(coins[a] +
            std::min(find_max_diff_helper(coins, a + 2, b, K),
                find_max_diff_helper(coins, a + 1, b - 1, K)),
            coins[b] +
            std::min(find_max_diff_helper(coins, a+1, b-1, K),
                find_max_diff_helper(coins, a, b -2, K)));
    return K[a][b];
}


int find_max_diff (const std::vector<int> coins)
{
    std::vector<std::vector<int>> K(coins.size(),
            std::vector<int>(coins.size(), -1));
    return find_max_diff_helper(coins, 0, coins.size() - 1, K);
}

int main (void)
{
    std::vector<int> C = {25,5,10,5,10,5,10,25,1,25,1,25,1,25,5,10};
    auto res = find_max_diff(C);
    debug(res);
    return 0;
}
