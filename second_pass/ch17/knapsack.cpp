#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include "../../utils.hpp"

using Item = std::pair<int, int>;
//Item.first is value
//Item.second is weight

int knapsack (const std::vector<Item>& items, const int W)
{
    std::vector<std::vector<int>> K(items.size()+1,
            std::vector<int>(W+1, 0));

    for (auto i = 1; i <= items.size(); ++i) {
        auto item = items[i-1];
        for (auto w = 1; w <= W; ++w){
            K[i][w] = K[i-1][w];
            if (w >= item.second) {
                K[i][w] = std::max(K[i-1][w], K[i-1][w - item.second] + item.first);
            }
        }
    }
    return K.back().back();
}

int main (void)
{
    std::vector<Item> items = {
        {65, 20},
        {35, 8},
        {245, 60},
        {195, 55},
        {65, 40},
        {150, 70},
        {275, 85},
        {155, 25},
        {120, 30},
        {320, 65},
        {75, 75},
        {40, 10},
        {200, 95},
        {100, 50},
        {220, 40},
        {99, 10}
    };
    auto res = knapsack(items, 130);
    assert(res == 695);
    return 0;
}
