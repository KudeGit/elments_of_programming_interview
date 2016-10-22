#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <functional>
#include <tuple>
#include "../utils.hpp"




template<class T>
using pq_el_t = std::tuple<int, T>;

template <class T>
auto pq_el_cmp_t = [](const pq_el_t<T>& a, const pq_el_t<T>& b) {
    return std::get<1>(a) > std::get<1>(b);};


template <class T>
std::vector <T> merge (const std::vector<std::vector<T>>& A)
{
    std::vector<int> A_idx(A.size(), 0);
    std::priority_queue<pq_el_t<T>, std::vector<pq_el_t<T>>, decltype(pq_el_cmp_t<T>)> min_heap(pq_el_cmp_t<T>);
    std::vector<T> res;
    //init min_heap
    for (int i = 0; i < A.size(); ++i) {
        if(A_idx[i] < A[i].size()) {
            auto new_pq_el = std::make_tuple(i, A[i][A_idx[i]]);
            ++A_idx[i];
            min_heap.push(new_pq_el);
        }
    }
    while (!min_heap.empty()) {
        auto& curr = min_heap.top();
        auto i = std::get<0>(curr);
        auto curr_data = std::get<1>(curr);
        res.push_back(curr_data);
        min_heap.pop();

        if(A_idx[i] < A[i].size()) {
            auto new_pq_el = std::make_tuple(i, A[i][A_idx[i]]);
            min_heap.push(new_pq_el);
            ++A_idx[i];
        }
    }

    return res;
}


template <class T>
std::vector<T> sort_k_inc_dec (const std::vector<T>& A)
{
    bool is_increasing = true;
    std::vector<std::vector<T>> S;
    int start = 0;
    for (int i = 1; i < A.size(); ++i) {
        if(A[i] < A[i-1] && is_increasing) {
            S.emplace_back(A.cbegin() + start, A.cbegin() + i);
            is_increasing = !is_increasing;
            start = i;
        } else if(A[i] > A[i-1] && !is_increasing) {
            S.emplace_back(A.crbegin() + A.size() - i, A.crbegin() + A.size() - start);
            is_increasing = !is_increasing;
            start = i;
        }
    }
    if(start < A.size()) {
        if(is_increasing) {
            S.emplace_back(A.cbegin() + start, A.end());
        } else {
            S.emplace_back(A.crbegin(), A.crbegin() + A.size() - start);
        }
    }
    return merge(S);
}




int main (void)
{
    std::vector<std::vector<int>> A = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {5,6,7,8,9,10},
        {7, 9, 11, 13, 15}
    };
    std::vector<int> V = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
    auto res = sort_k_inc_dec(V);
    std::cout << res << std::endl;
    return 0;
    auto a = merge(A);
    std::cout << a << std::endl;
    return 0;
}
