#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../utils.hpp"

int search_completeness (int budget, std::vector<int>& A)
{
    std::sort(A.begin(), A.end());
    std::vector<int> prefix_sum;
    std::partial_sum(A.begin(), A.end(), std::back_inserter(prefix_sum));
    std::vector<int> costs;
    for (int i = 0; i < prefix_sum.size(); ++i) {
        costs.emplace_back(prefix_sum[i] + A[i] * (A.size() - i - 1));
    }
    auto l = std::lower_bound(costs.begin(), costs.end(), budget);
    if (l == costs.end()) {
        return -1; //no solution, sum is lower than budget already
    }
    if (l == costs.begin()) {
        return budget / static_cast<int>(A.size());
    }
    auto idx = std::distance(costs.begin(), l) - 1;
    auto sigma = A[idx] + (budget - costs[idx])/(A.size() - idx);
    return sigma;
}
