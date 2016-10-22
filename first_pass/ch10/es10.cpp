#include <iostream>
#include <stack>
#include "btree.hpp"
#include "../utils.hpp"

template <class T>
void visit_preorder_no_rec (const std::shared_ptr<BTN<T>>& root)
{
    if (!root) {
        return;
    }
    std::stack<std::shared_ptr<BTN<T>>> S;
    S.push(root);
    while (!S.empty()) {
        auto x = S.top();
        std::cout << *x << ", ";
        S.pop();
        auto left = x->left;
        auto right = x->right;
        if (right) {
            S.push(right);
        }
        if (left) {
            S.push(left);
        }
    }
    std::cout << std::endl;
    return;
}



template <class T> 
void visit_in_order_no_rec (const std::shared_ptr<BTN<T>>& root)
{
    if (!root) {
        return;
    }
    auto x = root;
    std::stack<std::shared_ptr<BTN<T>>> S;
    while (x || !S.empty()) {
        if(x) {
            S.push(x);
            x = x->left;
        } else {
            x = S.top();
            std::cout << *x << ", ";
            S.pop();
            x = x->right;
        }
    }
    std::cout << std::endl;
}


template <class T>
void visit_post_order_no_rec (const std::shared_ptr<BTN<T>>& root)
{
    if (!root) {
        return;
    }
    std::stack<std::shared_ptr<BTN<T>>> S1;
    std::stack<std::shared_ptr<BTN<T>>> S2;
    S1.push(root);
    while (!(S1.empty() && S1.empty())) {
        auto x = S1.top();
        S1.pop();
        S2.push(x);
        if (x->left) {
            S1.push(x->left);
        }
        if (x->right) {
            S1.push(x->right);
        }
    }
    while (!S2.empty()) {
        std::cout << *S2.top() << ", ";
        S2.pop();
    }
    std::cout << std::endl;
    return;
}


int main (void)
{
    auto root = create_3_unbalanced_tree();
    //print_tree_preorder(root);
    //banner();
    //visit_preorder_no_rec(root);
    //banner();
    //visit_in_order_no_rec(root);
    //banner();
    print_tree_postorder(root);
    banner();
    visit_post_order_no_rec(root);
    return 0;
}
