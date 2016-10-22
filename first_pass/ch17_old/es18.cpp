#include <iostream>
#include <vector>
#include "../utils.hpp"


int num_ways_helper (const int N, const int K, std::vector<int>& cache)
{
    if (N == 0) {
        return 1;
    }
    if (cache[N] != -1) {
        debug(cache[N]);
        return cache[N];
    }
    int num_ways = 0;
    for (int k = 1; k <= K; ++k) {
        if (N - k >= 0) {
            num_ways += num_ways_helper(N - k, K, cache);
        }
    }
    cache[N] = num_ways;
    debug(cache);
    return num_ways;
}

int num_ways (const int N, const int K)
{
    std::vector<int> cache (N+1, -1);
    return num_ways_helper(N, K, cache);
}


int num_ways2 (const int N, const int K)
{
    std::vector<int> ways(N+1, 0);
    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int k = 1; k <= K && k <= i; ++k) {
            ways[i] += ways[i-k];
        }
    }
    return ways.back();
}


int main (void)
{
    auto ways = num_ways2(4, 2);
    std::cout << ways << std::endl;
    return 0;
}
