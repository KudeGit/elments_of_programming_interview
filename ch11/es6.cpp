#include <iostream>
#include <queue>
#include <vector>
#include "../utils.hpp"



template <class T>
struct Comp {
    bool operator() (const std::pair<int, T>& a,
            const std::pair<int, T>& b) {
        return a.second < b.second;
    }
};


template <class T>
std::vector<T> get_k_largest (const std::vector<T>& A, int k) 
{
    if (k <= 0) {
        return {};
    }
    using pair_t = std::pair<int, T>;
    std::priority_queue<pair_t, 
        std::vector<pair_t>, Comp<T>> maxH;
    std::vector<T> res;
    maxH.emplace(0, A[0]);
    while (k) {
        auto curr = maxH.top();
        res.emplace_back(curr.second);
        maxH.pop();
        if ((curr.first << 1) + 1 < A.size()) {
            maxH.emplace((curr.first << 1) + 1, A[(curr.first << 1) + 1]);
        }
        if ((curr.first << 1) + 2 < A.size()) {
            maxH.emplace((curr.first << 1) + 2, A[(curr.first << 1) + 2]);
        }
        k--;
    }
    return res;
}


int main (void)
{
    const std::vector<int> A = {10, 8, 9, 6, 4, 5, 7};
    auto res = get_k_largest(A, 1);
    std::cout << res << std::endl;
    res = get_k_largest(A, 4);
    std::cout << res << std::endl;
    return 0;
}
