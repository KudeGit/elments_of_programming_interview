#include <iostream>
#include <vector>
#include "../utils.hpp"


int max_margin_helper (const std::vector<int>& coins,
        int a, int b,
        std::vector<std::vector<int>>& K) {

    if(a > b) {
        return 0;
    }
    if (K[a][b] == -1) {
        auto res_a = coins[a] +
            std::min(max_margin_helper(coins, a + 2, b, K),
                max_margin_helper(coins, a + 1, b - 1, K));

        auto res_b = coins[b] +
            std::min(max_margin_helper(coins, a, b - 2, K),
                max_margin_helper(coins, a + 1, b - 1, K));

        K[a][b] = std::max(res_a, res_b);
    }
    return K[a][b];
}


int max_margin (const std::vector<int>& coins)
{
    std::vector<std::vector<int>> K(coins.size(), std::vector<int>(coins.size(), -1));
    return max_margin_helper(coins, 0, coins.size() - 1, K);
}


int main (void)
{
    std::vector<int> C = {25,5,10,5,10,5,10,25,1,25,1,25,1,25,5,10};
    auto res = max_margin(C);
    debug(res);
    return 0;
}
