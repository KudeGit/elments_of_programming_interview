#include <iostream>
#include <vector>
#include <memory>
#include "btree.hpp"
#include "../utils.hpp"



template <class T>
std::pair<int, int> find_endpoints (
        const T curr,
        const std::vector<T>& inorder,
        int start, int end)
{
    for (int i = start; i <= end; ++i) {
        if (curr == inorder[i]) {
            return std::pair<int,int>(i-1,i+1);
        }
    }
    return std::pair<int, int>(-1, -1);

}

template <class T>
std::shared_ptr<BTN<T>> rebuild_from_pre_order_helper (
        const std::vector<T>& inorder,
        const std::vector<T>& preorder,
        int& idx,
        int start, int end)
{
    if (idx >= inorder.size()) {
        return nullptr;
    }
    if (start == end) {
        auto curr = std::make_shared<BTN<T>>();
        curr->data = inorder[start];
        return curr;
    }

    auto curr = std::make_shared<BTN<T>>();
    curr->data = preorder[idx];
    auto end_points = find_endpoints(preorder[idx],
            inorder, start, end);
    curr->left = rebuild_from_pre_order_helper(inorder,
            preorder, ++idx, start, end_points.first);
    curr->right = rebuild_from_pre_order_helper(inorder,
            preorder, ++idx, end_points.second, end);
    return curr;
}


template <class T>
std::shared_ptr<BTN<T>> rebuild_from_pre_order (
        const std::vector<T>& inorder,
        const std::vector<T>& preorder)
{
    if (inorder.size() != preorder.size()) {
        return nullptr;
    }
    int idx = 0;
    return rebuild_from_pre_order_helper(inorder, preorder, 
            idx, 0, inorder.size() - 1);
}


int main (void)
{
    std::vector<char> inorder = {'c', 'b', 'd', 'a',
        'f', 'e', 'h', 'g'};
    std::vector<char> preorder = {'a', 'b', 'c',
        'd', 'e', 'f', 'g', 'h'};

    auto root = rebuild_from_pre_order(inorder, preorder);
    print_tree_preorder(root);
    banner();
    print_tree_inorder(root);
    return 0;

}
