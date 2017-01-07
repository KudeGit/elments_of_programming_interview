#include <iostream>
#include <vector>
#include "../../utils.hpp"

double prob_of_majority (int n, double p)
{
    std::vector<std::vector<double>> P (n+1, std::vector<double>(n+1, 0.0));
    for (int i = 0; i <= n; ++i) {
        P[i][0] = 1.0 * pow(1.0-p, i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            P[i][j] = p * P[i-1][j-1] + P[i-1][j] * (1-p);
        }
    }
    auto res = 0.0;
    debug(P);
    for (int j = (n>>1) + 1; j <= n; ++j) {
        res += P[n][j];
    }
    return res;
}


int main (void)
{
    auto res = prob_of_majority(3, 0.5);
    debug(res);
    return 0;
}
