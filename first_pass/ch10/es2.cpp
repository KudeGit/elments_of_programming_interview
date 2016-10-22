#include <iostream>
#include "btree.hpp"
#include <memory>
#include <tuple>


template <class T>
std::tuple<std::shared_ptr<BTN<T>>,int> 
is_not_k_balanced_helper (std::shared_ptr<BTN<T>> root, int k)
{
    if(!root) {
        return std::make_tuple(nullptr, 0);
    }
    auto l = is_not_k_balanced_helper(root->left, k);
    auto candidate = std::get<0>(l);
    auto hl = std::get<1>(l);
    if (candidate) {
        return std::make_tuple(candidate, -1);
    }
    auto r = is_not_k_balanced_helper(root->right, k);
    candidate = std::get<0>(r);
    auto hr = std::get<1>(r);
    if (candidate) {
        return std::make_tuple(candidate, -1);
    }
    if (std::abs(hr - hl) < k) {
        return std::make_tuple(nullptr, std::max(hr,hl) + 1);
    }
    return std::make_tuple(root, -1);
}



template <class T>
std::shared_ptr<BTN<T>>
is_not_k_balanced (std::shared_ptr<BTN<T>> root, int k)
{
    auto res = is_not_k_balanced_helper(root, k);
    return std::get<0>(res);
}

int main (void)
{
    auto root = create_3_unbalanced_tree();
    auto x = is_not_k_balanced(root, 3);
    std::cout << x->data << std::endl;

    return 0;
}
