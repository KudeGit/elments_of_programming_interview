#include <iostream>
#include <vector>
#include "../utils.hpp"

int knapsack (
        const std::vector<int>& V,
        const std::vector<int>& W,
        const int C)
{
    std::vector<std::vector<int>> K(C+1, std::vector<int>(V.size()+1, 0));

    for (int w = 0; w <= C; ++w) {
        for (int i = 0; i < V.size(); ++i) {
            K[w][i+1] = w - W[i] >= 0 ? 
                std::max(K[w - W[i]][i] + V[i], K[w][i]) :
                K[w][i];
        }
    }
    return K.back().back();

}


int main (void)
{

    std::vector<int> V = {8,1,0,5,3};
    std::vector<int> W = {1,2,3,2,2};
    int C = 4;
    auto max_value = knapsack(V, W, C);
    std::cout << max_value << std::endl;
    return 0;
}
