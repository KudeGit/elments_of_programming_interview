#include <iostream>
#include <vector>
#include <set> //used as bst
#include "ch15.hpp"


int min_distance_3_sorted_array (const std::vector<std::vector<int>>& A)
{
    struct TreeNode {
        int idx;
        const std::vector<int>& a;
    };
    auto TreeNodeCmp = [](const TreeNode& lhs, const TreeNode& rhs) {
        return lhs.a[lhs.idx] != rhs.a[rhs.idx] ? lhs.a[lhs.idx] < rhs.a[rhs.idx] : lhs.idx < rhs.idx;
    };
    std::set<TreeNode, decltype(TreeNodeCmp)> T(TreeNodeCmp);
    for (const auto& a: A) {
        if (!a.empty()) {
            T.insert(TreeNode{0, a});
        }
    }
    int min_dist = std::numeric_limits<int>::max();
    while (!T.empty()) {
        auto first = T.begin();
        auto last = T.rbegin();
        min_dist = std::min (min_dist, last->a[last->idx] - first->a[first->idx]);
        if (first->idx + 1 < first->a.size()) {
            TreeNode next{1 + first->idx, first->a};
            T.insert(next);
            T.erase(first);
        } else {
            break;
        }
    }
    return min_dist;

}


