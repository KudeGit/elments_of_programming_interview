#include <iostream>
#include <vector>
#include "tree.hpp"
#include "../utils.hpp"
#include <tuple>



template <class T>
std::unique_ptr<BSTN<T>> build_from_pre_order_visit_helper (
        const std::vector<T>& data, size_t s, size_t e) 
{
    if (s >= e) {
        return std::unique_ptr<BSTN<T>>(nullptr);
    }
    debug(std::make_tuple(s,e));
    auto s_l = s + 1;
    auto x = s + 1;
    while (x < e && data[x] < data[s]) {
        ++x;
    }
    std::unique_ptr<BSTN<T>> root(new BSTN<T>(data[s]));
    root->left = build_from_pre_order_visit_helper(data, s_l, x);
    root->right = build_from_pre_order_visit_helper(data, x, e);
    return root;
}


template <class T>
std::unique_ptr<BSTN<T>> build_from_pre_order_visit (
        const std::vector<T>& data) 
{
    return build_from_pre_order_visit_helper(data, 0, data.size());
}

int main (void)
{
    std::vector<int> data = {20, 10, 5, 0, 7, 12, 15, 13, 40, 25, 30, 28, 29, 35, 50, 100};
    //std::vector<int> data = {10, 5, 20};
    auto root = build_from_pre_order_visit(data);
    in_order_visit_no_rec(root);
    std::cout << std::endl;
    pre_order_visit(root);
    std::cout << std::endl;
}

