#include <iostream>
#include <vector>
#include <queue>

std::vector<int> compute_fair_bonuses (const std::vector<int>& locs)
{
    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    };
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>, 
        decltype(cmp)> pq(cmp);

    int i = 0;
    for (const auto l: locs) {
        pq.push(std::make_pair(l, i++));
    }
    
    std::vector<int> res(locs.size(), 0);
    while (!pq.empty()) {
        auto idx = pq.top().second;
        res[idx] = std::max(idx > 0 ? res[idx - 1] : 0,
                (idx < locs.size() - 1) ? res[idx+1]  : 0) + 1;
        pq.pop();
    }
    return res;
}
