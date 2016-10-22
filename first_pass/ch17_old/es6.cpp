#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include "../utils.hpp"


using cache_t = std::tuple<int, int, int>;

struct HashKey {
    size_t operator() (const cache_t& c) const {
        return std::hash<int>()(std::get<0>(c)) ^
            std::hash<int>()(std::get<1>(c)) ^
            std::hash<int>()(std::get<2>(c));
    }
};

struct KeyEqual {
    bool operator() (const cache_t& a, const cache_t& b) const {
        return std::get<0>(a) == std::get<0>(b) &&
            std::get<1>(a) == std::get<1>(b) &&
            std::get<2>(a) == std::get<2>(b);
    }
};

bool find_sequence_helper (const std::vector<std::vector<int>>& A,
        const std::vector<int>& S,
        std::unordered_map<cache_t, bool, HashKey, KeyEqual>& cache,
        int i, int j, int k)
{
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) {
        return false;
    }
    if (k == S.size()) {
        return true;
    }
    std::tuple<int,int,int> current = std::make_tuple(i,j,k);
    if (cache.find(current) !=  cache.end()) {
        return cache[current];
    }

    auto res = A[i][j] == S[k] &&
        (find_sequence_helper(A,S, cache, i-1, j, k+1) ||
         find_sequence_helper(A,S, cache, i+1, j, k+1) ||
         find_sequence_helper(A,S, cache, i, j-1, k+1) ||
         find_sequence_helper(A,S, cache, i, j+1, k+1));
    
    cache[current] = res;
    return res;

}

bool find_sequence (const std::vector<std::vector<int>>& A,
        const std::vector<int>& S)
{
    std::unordered_map<cache_t, bool, HashKey, KeyEqual> cache;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (find_sequence_helper(A,S,cache, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}


int main (void)
{
    std::vector<std::vector<int>> A = {
        {1,2,3}, {3,4,5}, {5,6,7}};
    std::vector<int> S = {1,3,4,6};
    auto res = find_sequence(A,S);
    std::cout << res << std::endl;
    return 0;
}
