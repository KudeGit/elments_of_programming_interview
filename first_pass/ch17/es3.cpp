#include <iostream>
#include <vector>
#include "../utils.hpp"

long compute_binomial (const int n, const int k)
{
    std::vector<std::vector<int>> C (n + 1,
            std::vector<int>(k + 1, 0));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
    }
    for (int i = 0; i <= k; ++i) {
        C[i][i] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    return C[n][k];
}


int main (void)
{
    auto res = compute_binomial(12, 10);
    std::cout << res << std::endl;
    return 0;
}
