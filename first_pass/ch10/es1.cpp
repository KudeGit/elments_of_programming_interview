#include <iostream>
#include <memory>
#include "btree.hpp"
#include <tuple>


template <class T>
std::tuple<bool, int> is_balanced_helper (const std::shared_ptr<BTN<T>> root)
{
    if(root == nullptr) {
        return std::make_tuple(true, 0);
    }
    auto left = is_balanced_helper(root->left);
    auto is_b_l = std::get<0>(left);
    if (!is_b_l) {
        return std::make_tuple(is_b_l, -1);
    }
    auto h_l = std::get<1>(left);
    auto right = is_balanced_helper(root->right);
    auto is_b_r = std::get<0>(right);
    if (!is_b_r) {
        return std::make_tuple(is_b_r, -1);
    }
    auto h_r  = std::get<1>(right);

    auto is_b = (is_b_l && is_b_r) && 
        (((h_l - h_r) >= -1) && ((h_l - h_r) <= 1));
    auto h = std::max(h_l, h_r)  + 1;
    return std::make_tuple(is_b, h);
}


template <class T>
bool is_balanced (std::shared_ptr<BTN<T>> root)
{
    auto res = is_balanced_helper(root);
    return std::get<0>(res);
}

int main (void)
{

    auto root_b  = create_tree_balanced();
    auto root_not_b  = create_tree_not_balanced();
    std::cout << is_balanced(root_b) << std::endl;
    std::cout << is_balanced(root_not_b) << std::endl;
    return 0;
}
