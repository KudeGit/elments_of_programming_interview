#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include "../utils.hpp"

struct Node {
    int v_idx;
    int value;
};

bool operator< (const Node& a, const Node& b) {
    if (a.value != b.value) {
        return a.value < b.value;
    } else {
        return a.v_idx < b.v_idx;
    }
};

std::ostream& operator<< (std::ostream& out, const Node& n)
{
    out << "(" << n.v_idx  << ", " << n.value <<")";
    return out;
}

std::vector<int>
find_min_distance (const std::vector<std::vector<int>>& A)
{
    std::vector<int> idx(A.size(), -1);
    std::vector<int> min_idx(A.size(), -1);
    if (A.empty()) {
        return idx;
    }
    std::set<Node> nodes;
    for (int i = 0; i < A.size(); ++i) {
        if(A[i].empty()) {
            return idx;
        }
        idx[i] = 0;
        nodes.emplace(Node{.v_idx = i, .value = A[i][idx[i]]});

    }

    int min_diff = std::numeric_limits<int>::max();
    while (true) {
        auto curr_min = nodes.crbegin()->value - nodes.cbegin()->value;
        if (curr_min < min_diff) {
            min_diff = curr_min;
            for(int i = 0; i < idx.size(); ++i) {
                min_idx[i] = idx[i];
            }
        }
        auto v_idx = nodes.begin()->v_idx;
        idx[v_idx]++;
        if (idx[v_idx] >= A[v_idx].size()) {
            return min_idx;
        }
        nodes.erase(nodes.cbegin());
        nodes.emplace(Node{.v_idx = v_idx, .value = A[v_idx][idx[v_idx]]});
    }

    return min_idx;
}


int main (void)
{
    std::vector<std::vector<int>> A = {
        {20, 24, 100},
        {2, 19, 22, 79, 800},
        {10, 12, 23, 24, 119}
    };
    auto res = find_min_distance(A);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << A[i][res[i]] << ", ";
    }
    std::cout << std::endl;
    return 0;
}
