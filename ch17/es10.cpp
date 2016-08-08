#include <iostream>
#include <vector>
#include <numeric>
#include "../utils.hpp"


int compute_fair_split (const std::vector<int> items) 
{
    auto tot_val = std::accumulate(items.begin(), 
            items.end(), 0);

    std::vector<std::vector<bool>> K ((tot_val >> 1) + 1,
            std::vector<bool>(items.size() + 1, false));

    for (int i = 0; i <= items.size(); ++i) {
        K[0][i] = true; 
    }
    for (int i = 1; i <= (tot_val >> 1); ++i) {
        for (int j = 0; j < items.size(); ++j) {
            K[i][j+1] = K[i][j] || 
                (items[j] <= i ? K[i-items[j]][j] : false);
        }
    }

    for (int i = (tot_val >> 1); i >= 0; --i) {
        if(K[i].back()) {
            return tot_val - i - i;
        }
    }
    return tot_val;
}


int main (void)
{
    std::vector<int> A = {1,2,3,4,100};
    auto res2 = compute_fair_split(A);
    std::cout << res2 << std::endl;
    return 0;
}

