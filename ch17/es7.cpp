#include <iostream>
#include <vector>
#include "../utils.hpp"


struct Item {
    int v;
    int w;
};


int knapsack (const std::vector<Item>& items, const int C)
{
    std::vector<std::vector<int>> K (C + 1,
            std::vector<int>(items.size() + 1, 0));
    for (int j = 0; j <= C; ++j) {
        for (int i = 1; i <= items.size(); ++i) {
            K[j][i] = std::max(K[j][i-1],
                    items[i-1].w <= j ?
                    K[j - items[i-1].w][i-1] + items[i-1].v : 0);
        }
    }
    return K.back().back();
}


int main(void)
{
    std::vector<Item> items = {
        Item{65, 20},
        Item{35, 8},
        Item{245, 60},
        Item{195, 55},
        Item{65, 40},
        Item{150, 70},
        Item{275, 85},
        Item{155, 25},
        Item{120, 30},
        Item{320, 65},
        Item{75, 75},
        Item{40, 10},
        Item{200, 95},
        Item{100, 50},
        Item{220, 40},
        Item{99, 10},
    };

    auto res = knapsack(items, 130);
    std::cout << res << std::endl;
    return 0;
}

