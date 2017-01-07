#include <iostream>
#include <vector>
#include <limits>

struct Point {
    int x;
    int y;
    int z;
};


int minimum_capacity (const std::vector<Point>& P)
{
    auto max_energy = 0;
    auto min_so_far = std::numeric_limits<int>::max();
    for (auto& p: P) {
        std::min(min_so_far, p.z);
        max_energy = std::max(max_energy, p.z - min_so_far);
    }
    return max_energy;
}


int max_difference_no_transaction_limits (const std::vector<int>& A)
{
    auto max_profit = 0;
    for (int i = 1; i < A.size(); ++i) {
        max_profit += std::max(0, A[i] - A[i-1]);

    }
    return max_profit;
}

int max_difference_2_transaction (const std::vector<int>& A)
{
    std::vector<int> max_forward(A.size(), 0);
    auto max_backward = max_forward;
    auto max_profit = 0;
    auto min_so_far = std::numeric_limits<int>::max();
    for (auto i = 0; i < A.size(); ++i) {
        min_so_far = std::min(min_so_far, A[i]);
        max_profit = std::max(max_profit, A[i] - min_so_far);
        max_forward[i] = max_profit;
    }
    auto max_so_far = std::numeric_limits<int>::min();
    max_profit = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        max_so_far = std::max(max_so_far, A[i]);
        max_profit = std::max(max_profit, max_so_far - A[i]);
        max_backward[i] = max_profit;
    }
    max_profit = 0;
    for (int i = 0; i < A.size(); ++i) {
        max_profit = std::max(max_forward[i] + max_backward[i], max_profit);
    }
    return max_profit;
}

int max_profit_k_transaction (int K, const std::vector<int>& prices)
{
    std::vector<std::vector<int>> dp(K+1, std::vector<int>(prices.size() + 1, 0));
    for (int k = 1; k <= K; ++k) {
        auto curr_max = std::numeric_limits<int>::min();
        for (int i = 0; i < prices.size(); ++i) {
            auto a = dp[k-1][i+1];
            auto b = dp[k][i];
            curr_max = std::max(curr_max, dp[k-1][i] - prices[i]);
            auto c = prices[i] + curr_max;
            dp[k][i+1] = std::max(a, std::max(b,c));
        }
    }
    return dp.back().back();

}



int main (void)
{
    //tested on leetcode: same od https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    return 0;
}
