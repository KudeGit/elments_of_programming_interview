#include <iostream>
#include <vector>
#include "../utils.hpp"

int compute_ways (const std::vector<int>& coins, int change)
{
    std::vector<std::vector<int>> K(change + 1, std::vector<int>(coins.size(), 0));
    for (int i = 0; i < coins.size(); ++i) {
        K[0][i] = 1;  //1 way for  change = 0
    }
    for (int i = 1; i <= change; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            K[i][j] = ((coins[j] <= i) ? K[i - coins[j]][j] : 0) +  //include coins[j]
                       ((j > 0) ? K[i][j-1] : 0 );                   //exclude coins[j]
        }
        debug(K);
    }
    return K.back().back();
}


int compute_ways_2 (const std::vector<int> coins, const int change)
{
    std::vector<int> combinations (change + 1, 0);
    combinations[0] = 1;
    for (int c: coins) {
        for (int i = c; i <= change; ++i) {
            combinations[i] += combinations[i - c];
        }
    }
    return combinations.back();
}


int main (void)
{
    std::vector<int> coins = {1, 2, 3};
    std::cout << compute_ways(coins, 1) << std::endl;
    std::cout << compute_ways(coins, 4) << std::endl;
    std::cout << compute_ways_2(coins, 4) << std::endl;
    return 0;
}
