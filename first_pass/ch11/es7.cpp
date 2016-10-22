#include <iostream>
#include <queue>
#include <vector>
#include "../utils.hpp"

struct Comp {
    bool operator () (const std::pair<int, int>& a,
            const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

std::vector<int> compute_bonuses (const std::vector<int>& A)
{
    std::vector<int> res(A.size(), 0);
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int,int>>, Comp> minH;
    for (int i = 0; i < A.size(); i++) {
        minH.emplace(i, A[i]);
    }
    while (!minH.empty()) {
        auto idx = minH.top().first;
        int candidate = 1;
        if (idx > 0) {
            candidate = std::max(candidate, res[idx-1]+1);
        }
        if (idx < A.size() - 1) {
            candidate = std::max(candidate, res[idx+1]+1);
        }
        res[idx]= candidate;
        minH.pop();
    }
    return res;
}


int main (void)
{
    std::vector<int> A = {300, 400, 500, 200};
    auto res = compute_bonuses(A);
    std::cout << A << std::endl;
    std::cout << res << std::endl;
    return 0;
}
