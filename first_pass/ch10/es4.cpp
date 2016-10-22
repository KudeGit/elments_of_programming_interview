#include <iostream>
#include "btree.hpp"
#include "../utils.hpp"






template <class T>
std::shared_ptr<BTN<T>> lowest_common_ancestor (
        const std::shared_ptr<BTN<T>>& root,
        const std::shared_ptr<BTN<T>>& a,
        const std::shared_ptr<BTN<T>>& b)

{
    if (!root) {
        return nullptr;
    }
    if (root == a|| root == b) {
        return root;
    }
    auto l_res = lowest_common_ancestor(root->left, a, b);
    auto r_res = lowest_common_ancestor(root->right, a, b);
    if (l_res && r_res) {
        return root;
    }
    return l_res ? l_res : r_res;
}


template <class T>
int find_height (const std::shared_ptr<BTN<T>>& root, 
        const std::shared_ptr<BTN<T>>& a,
        int h)
{
    if (!root) {
        return -1;
    }

    if (a == root) {
        return h;
    }
    auto res_l = find_height(root->left, a, h+1);
    auto res_h = find_height(root->right, a, h+1);
    return res_l != -1 ? res_l : res_h;
}

template <class T>
std::shared_ptr<BTN<T>> lowest_common_ancestor_with_parent(
        const std::shared_ptr<BTN<T>>& root,
        std::shared_ptr<BTN<T>> a,
        std::shared_ptr<BTN<T>> b)
{

    auto ha = find_height(root, a, 0);
    auto hb = find_height(root, b, 0);
    if (ha == -1 || hb == -1) {
        throw std::invalid_argument("cannot find one of the nodes");
    }
    auto h_max = std::max(ha, hb);
    auto& lower_node = h_max == ha ? a : b;
    while (h_max > std::min (ha, hb)) {
        auto p = lower_node->parent.lock();
        if (!p) {
            throw std::logic_error("Parent does not exist????");
        }
        lower_node = p;
        --h_max;
    }
    while ((a && b) && (a != b)) {
        auto pa = a->parent.lock();
        a = pa;
        auto pb = b->parent.lock();
        b = pb;
    }
    return a;
}


int main (void)
{
    auto root = create_3_unbalanced_tree();
    auto a = find (root, 'd');
    auto b = find (root, 'x');
    auto lca = lowest_common_ancestor(root, a, b);
    //auto lca = lowest_common_ancestor_with_parent(root, a, b);
    if (lca) {
        std::cout << *lca << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
