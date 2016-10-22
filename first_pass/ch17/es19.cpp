#include <iostream>
#include <vector>
#include "../utils.hpp"

double prob_rep_majority (const int N, 
        const int R,
        const std::vector<double>& P)
{
    std::vector<std::vector<double>> K(N + 1,
            std::vector<double>(R + 1, 0.0));

    K[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        K[i][0] = 1 - P[i-1];
    }

    for (int n = 1; n <= N; ++n) {
        for (int r = 1; r <= N; ++r) {
            K[n][r] = P[n-1] * K[n-1][r-1] + 
                (1 - P[n-1]) * K[n-1][r];
        }
    }
    double res = 0;
    for (int r = (N >> 1) + 1; r <= N; ++r) {
        res += K[N][r];
    }
    return res;
}


int main (void)
{
    std::vector<double> P = {0.3, 0.35, 0.35};
    auto res1 = prob_rep_majority(P.size(), P.size(), P);
    return 0;

}
