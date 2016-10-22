#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <limits>
#include "../utils.hpp"

struct SetEntry {
    int val;
    int array;
};
struct CmpValue {
    bool operator() (const SetEntry& lhs, const SetEntry& rhs) const
    {
        if (lhs.val != rhs.val) {
            return lhs.val < rhs.val;
        } else {
            return lhs.array < rhs.array;
        }
    }
};

std::vector<int>
find_min_distance (const std::vector<std::vector<int>>& A)
{
    std::set<SetEntry, CmpValue> BST;
    std::vector<int> idx(A.size(), -1);
    std::vector<int> res;

    for (int l = 0; l < idx.size(); ++l) {
        if (++idx[l] < A[l].size()) {
            BST.insert(SetEntry{A[l][idx[l]], l});
        }
    }
    debug(idx);
    int min_distance = std::numeric_limits<int>::max();
    while (!BST.empty()) {
        const auto x = BST.cbegin();
        const auto current_distance = abs(BST.crbegin()->val - x->val);
        if (min_distance > current_distance) {
            res = idx;
            min_distance = current_distance;
            debug(res);
            debug(min_distance);
        }
        int l = x->array;
        BST.erase(x);
        if (idx[l] < A[l].size()) {
            BST.insert(SetEntry{A[l][++idx[l]], l});
        } else {
            break;
        }
    }
    return res;
}

int main (void)
{
    std::vector<std::vector<int>> A = {
        {20, 24, 100},
        {2, 19, 22, 79, 800},
        {10, 12, 23, 24, 119}
    };
    auto res = find_min_distance(A);
    debug(res);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << A[i][res[i]] << ", ";
    }
    std::cout << std::endl;
    return 0;
}
