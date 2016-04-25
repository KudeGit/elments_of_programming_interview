#include <iostream>
#include <vector>
#include "../utils.hpp"




void compute_all_subset (int n, int k, 
        int start, std::vector<int> current,
        std::vector<std::vector<int>>& all_subsets)
{
    if (k == 0) {
        all_subsets.emplace_back(current);
        return;
    }
    
    for (int i = start; i < n; ++i) {
        current.emplace_back(i);
        compute_all_subset(n, k-1, i+1, current, all_subsets);
        current.pop_back();
    }
}

std::vector<std::vector<int>> compute_all_subset (int n, int k)
{
    std::vector<int> current;
    std::vector<std::vector<int>> all_subsets;
    compute_all_subset(n, k, 0, current, all_subsets);
    return all_subsets;
}


int main (void)
{
    auto all_subs = compute_all_subset(5,3);
    for (const auto& s: all_subs) {
        std::cout << s << std::endl;
    }
    return 0;
}
