#include <iostream>
#include <vector>
#include "../utils.hpp"


double get_prob_majority (const std::vector<double>& p, int N)
{
    std::vector<std::vector<double>> cache(N+1, std::vector<double>(N+1, 0.0));
    cache[0][0] = 1;
    //for (int r = 0; r <= N; ++r) {
    //    cache[0][r] = 0;
    //    cache[r][0] = 1;
    //}

    for (int n = 1; n <= N; ++n) {
        for (int r = 0; r <= n; ++r) {
            cache[n][r] = (r > 0) ? p[n-1] * cache[n-1][r-1] +
                (1-p[n-1]) * cache[n-1][r] : (1 - p[n-1]);
        }
    }
    debug(cache);
    double res = 0.0;
    for (int r = (N >> 1) + 1; r <= N; ++r) {
        res += cache[N][r];
    }
    return res;
}

double get_prob_majority_rec_helper(const std::vector<double>& p,
        const int N, const int R,
        std::vector<std::vector<double>>& cache)
{
    if (N < 0 || R > N) {
        return 0;
    } else if (N == 0 && R == 0){
        return 1;
    } else if (cache[N][R] != -1.0) {
        return cache[N][R];
    } else {
        cache[N][R] = p[N-1] * get_prob_majority_rec_helper(p, N - 1, R - 1, cache) +
            (1 - p[N-1]) * get_prob_majority_rec_helper(p, N-1, R, cache);
    }
    return cache[N][R];
}


double get_prob_majority_rec (const std::vector<double>& p, int N) 
{
    std::vector<std::vector<double>> cache(N+1, std::vector<double>(N+1, -1.0));
    auto res = 0.0;
    for (int r = (N >> 1) + 1; r <= N; ++r) {
        res += get_prob_majority_rec_helper(p, N, r, cache);
    }
    debug(cache);
    return res;
}



int main (void)
{
    std::vector<double> P = {0.3, 0.35, 0.35};
    auto res1 = get_prob_majority(P, P.size());
    auto res2 = get_prob_majority_rec(P, P.size());
    debug(res1);
    debug(res2);
    return 0;

}
