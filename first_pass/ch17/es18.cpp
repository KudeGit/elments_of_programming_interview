#include <iostream>
#include <vector>
#include "../utils.hpp"


int count_ways_helper (const int n, int k, std::vector<int>& cache)
{
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (cache[n] != -1) {
        return cache[n];
    } else {
        cache[n] = 0;
        for (int i = 1; i <= k; ++i) {
            cache[n] += count_ways_helper(n - i, k, cache);
        }
        return cache[n];
    }
}

int count_ways (const int n, const int k)
{
    std::vector<int> cache(n+1, -1);
    return count_ways_helper(n, k, cache);
}

int cout_ways_no_rec (const int n, const int k)
{
    std::vector<int> cache(n+1, 0);
    cache[0] = 1;
    cache[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k && j <= i; ++j) {
            cache[i] += cache[i - j];
        }
    }
    return cache.back();

}

int main (void)
{
    int n = 4;
    int k = 2;

    auto ways = count_ways(n, k);
    auto ways2 = count_ways(n, k);

    std::cout << ways << std::endl;
    std::cout << ways2 << std::endl;
    return ways;

}
