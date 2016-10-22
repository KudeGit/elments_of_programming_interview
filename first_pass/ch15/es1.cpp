#include <iostream>
#include <limits>
#include "tree.hpp"
#include "../utils.hpp"

template <class T>
bool is_bst (const std::unique_ptr<BSTN<T>>& root,
        T min, T max)
{
    if (!root) {
        return true;
    } else if (root->data < min || root->data > max) {
        return false;
    }

    auto is_bst_left = is_bst (root->left, min, root->data);
    auto is_bst_right = is_bst (root->right, root->data, max);
    return is_bst_left && is_bst_right;
}



bool is_bst (const std::unique_ptr<BSTN<int>>& root)
{
    return is_bst(root,
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max());
}


template <class T>
bool is_bst_iterative (const std::unique_ptr<BSTN<T>>& root)
{
    if(!root) {
        return true;
    }
    auto current = root.get();
    std::stack<decltype(current)> s;
    auto prev = root.get();
    while (current || !s.empty()) {
        if (current) {
            s.push(current);
            current = current->left.get();
        } else {
            current = s.top();
            s.pop();
            if (!prev && prev->data > current->data) {
                return false;
            } else {
                prev = current;
                current = current->right.get();
            }
        }
    }
    return true;
}



int main (void)
{
    std::vector<int> A(10, 0);
    A[0] = 10;
    A[1] = 5; 
    A[2] = 7;
    A[3] = 20;
    A[4] = 3;
    A[5] = 15;
    A[6] = 17;
    A[7] = 17;
    A[8] = 100;
    A[9] = 0;
    std::unique_ptr<BSTN<int>> root = create_bst(A);
    in_order_visit_no_rec(root);
    auto res = is_bst(root);
    std::cout << res << std::endl;
    res = is_bst_iterative(root);
    std::cout << res << std::endl;
    return 0;
}
