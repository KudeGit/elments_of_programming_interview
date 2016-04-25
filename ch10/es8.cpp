#include <iostream>
#include "btree.hpp"
#include "../utils.hpp"



template <class T>
std::shared_ptr<BTN<T>> find_k_node (const std::shared_ptr<BTN<T>>& root,
        const int k)
{
    if (!root) {
        return nullptr;
    }
    auto rel_position = root->nodes - (root->right ? root->right->nodes : 0) - 1;
    //banner();
    //debug(*root);
    //debug(k);
    //debug(rel_position);
    if (k == rel_position) {
        return root;
    }
    if (k < rel_position) {
        return find_k_node(root->left, k);
    } else {
        return find_k_node(root->right, k - rel_position - 1);
    }
}


template <class T>
int computes_subunodes (const std::shared_ptr<BTN<T>>& root) 
{
    if (!root) {
        return 0;
    }
    auto nl =  computes_subunodes(root->left);
    auto nr =  computes_subunodes(root->right);
    root->nodes = nl + nr + 1;
    return root->nodes;
}



int main (void)
{
    auto root = create_3_unbalanced_tree();
    auto n  = computes_subunodes(root);
    print_tree_inorder(root);
    banner();

    //auto el = find_k_node(root, 2);
    for (int i = 0; i < n; ++i) {
        auto el = find_k_node(root, i);
        if(!el) {
            error("fuck");
        } else {
            std::cout << *el << std::endl;
        }
    }
    return 0;


}
