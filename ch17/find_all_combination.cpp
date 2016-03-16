#include <iostream>
#include <vector>
#include "../utils.hpp"

template<class T>
void find_combinations_helper (const std::vector<T>& items, int k, int n,
        std::vector<T>& current, std::vector<std::vector<T>>& res)
{
    if(current.size() == k) {
        res.emplace_back(current);
        return;
    }
    for (int i = n; i < items.size(); ++i) {
        current.emplace_back(items[i]);
        find_combinations_helper(items, k, i+1, current, res);
        current.pop_back();
    }
}

template <class T>
std::vector<std::vector<T>> find_combinations (const std::vector<T>& items, int k)
{
    std::vector<std::vector<T>> res;
    std::vector<T> current;
    find_combinations_helper(items, k, 0, current, res);
    return res;
}

int main (void)
{
    std::vector<int> items = {1,2,3,4,5};
    auto combinations = find_combinations(items, 3);
    for (const auto& c: combinations) {
        std::cout << c << std::endl;
    }
    return 0;
}
