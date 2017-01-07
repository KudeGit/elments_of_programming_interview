#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.hpp"

int pick_up_coins (const std::vector<int>& coins, int a, int b,
        std::vector<std::vector<int>>& K)
{
    if (b < a) {
        return 0;
    }
    if (K[a][b] == -1) {
        auto move1 = coins[a] +
            std::min(pick_up_coins(coins, a+2, b, K),
                     pick_up_coins(coins, a+1, b-1, K));

        auto move2 = coins[b] +
            std::min(pick_up_coins(coins, a, b-2, K),
                     pick_up_coins(coins, a+1, b-1, K));

        K[a][b] = std::max(move1, move2);
    }
    return K[a][b];
}

int pick_up_coins (const std::vector<int>& coins)
{
    std::vector<std::vector<int>> K(coins.size(),
            std::vector<int>(coins.size(), -1));

    return pick_up_coins(coins, 0, coins.size() - 1, K);
}

int main (void)
{
    std::vector<int> coins{25, 5, 10,
                            5, 10, 5,
                            10, 25, 1,
                            25, 1, 25,
                            1, 25, 5, 10};

    auto res = pick_up_coins(coins);
    assert(res == 140);
    return 0;
}
