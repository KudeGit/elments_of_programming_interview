#include <iostream>
#include <vector>
#include <stack>
#include "utils.hpp"

int find_max_area (const std::vector<int>& H)
{
    std::stack<int> S;
    if (H.empty()) {
        return 0;
    }
    auto max_area = 0;
    auto i = 0;
    while (i < H.size()) {
        if (S.empty() || H[S.top()] <= H[i]) {
            S.push(i);
            ++i;
        } else {
            auto k = S.top();
            S.pop();
            auto base = S.empty() ? i : i - S.top() - 1;
            max_area = std::max(H[k] * base, max_area);
        }
    }
    while (!S.empty()) {
        auto k = S.top();
        S.pop();
        auto base = S.empty() ? i : i - S.top() - 1;
        max_area = max_area = std::max(H[k] * base, max_area);
    }
    return max_area;
}


int main (void)
{
    std::vector<int> H = {6, 2, 5, 4, 5, 1, 6};
    std::cout << find_max_area(H) << std::endl;
    return 0;

}
