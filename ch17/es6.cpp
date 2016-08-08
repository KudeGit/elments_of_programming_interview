#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_set>
#include "../utils.hpp"


struct KeyHash {
    size_t operator() (const std::tuple<int, int, int>& t) const {
        return std::hash<int>()(std::get<0>(t)) ^
            std::hash<int>()(std::get<1>(t)) ^
            std::hash<int>()(std::get<2>(t));
    }
};


struct KeyEqual {
    bool operator() (const std::tuple<int, int, int>& t1,
            const std::tuple<int, int, int>& t2) const {
        return std::get<0>(t1) == std::get<0>(t2) &&
            std::get<1>(t1) == std::get<1>(t2) &&
            std::get<2>(t1) == std::get<2>(t2);
    }
};



bool find_helper(const std::vector<std::vector<int>>& A,
        const int i, const int j, 
        const std::vector<int>& S, const int k,
        std::vector<std::tuple<int, int>>& curr,
        std::vector<std::tuple<int, int>>& res,
        std::unordered_set<std::tuple<int, int, int>, KeyHash, KeyEqual>& T)
{
    if (k == S.size()) {
        res = curr;
        return true;
    }
    if (!((i >= 0 && i < A.size()) &&
                (j >=0 && A[0].size()))) {
        return false;
    }
    auto idx = std::make_tuple(i, j, k);
    if (T.find(idx) != T.end()) {
        return false;
    }

    if (A[i][j] == S[k]) {
        auto ij = std::make_tuple(i, j);
        curr.emplace_back(ij);
        auto is_present = find_helper(A, i+1, j, S, k+1, curr, res, T) ||
            find_helper(A, i-1, j, S, k+1, curr, res, T) ||
            find_helper(A, i, j+1, S, k+1, curr, res, T) ||
            find_helper(A, i, j-1, S, k+1, curr, res, T);
        if (is_present) {
            return true;
        } else {
            curr.pop_back();
        }
    }
    T.insert(idx);
    return false;
}

std::vector<std::tuple<int, int>> find_sequence (
        const std::vector<std::vector<int>>& A,
        const std::vector<int>& S)
{
    std::vector<std::tuple<int, int>> curr;
    std::vector<std::tuple<int, int>> res;
    std::unordered_set<std::tuple<int, int, int>, KeyHash, KeyEqual> T;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(find_helper(A, i, j, S, 0, res, curr, T)) {
                return res;
            }
        }
    }
    return res;
}


int main (void)
{
    std::vector<std::vector<int>> A = {
        {1,2,3},
        {3,4,5},
        {5,6,7},
    };
    std::vector<int> S = {1,3,4,6};
    auto res = find_sequence(A, S);
    std::cout << res << std::endl;
    return 0;
}
