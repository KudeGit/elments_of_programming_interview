#include <iostream>
#include "tree.hpp"
#include <stack>
#include <cassert>



template <class T>
BSTN<T>* find_first_equal (const std::unique_ptr<BSTN<T>>& root, const T& el)
{
    if (!root) {
        return nullptr;
    }
    if (root->data == el) {
        auto x = find_first_equal (root->left, el);
        return x ? x : root.get();
    }
    auto x = find_first_equal(el < root->data ? root->left : root->right, el);
    return x;
}


template <class T>
BSTN<T>* find_first_no_rec (const std::unique_ptr<BSTN<T>>& root, const T& el)
{
    if(!root) {
        return nullptr;
    }
    bool found = false;
    auto x = root.get();
    BSTN<T>* candidate = nullptr;
    while (x) {
        if (x->data == el) {
            candidate = x;
            x = x->left.get();
        } else {
            x = el < x->data ? x->left.get() : x->right.get();
        }
    }
    return candidate;
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
    int a = 17;
    auto x = find_first_no_rec(root, a);
    auto y = find_first_equal (root, a);
    assert (x == y);

    x = find_first_no_rec(root, 100);
    y = find_first_equal(root, 100);
    assert (x == y);

    x = find_first_no_rec(root, 1000);
    y = find_first_equal(root, 1000);
    assert (x == y);
    return 0;

}


