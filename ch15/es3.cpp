#include <iostream>
#include <tuple>
#include "tree.hpp"

template <class T>
BSTN<T>* get_maximum (const BSTN<T>* root)
{
    if(!root) {
        return;
    }
    while (root->right) {
        root = root->right.get();
    }
    return root;
}

template <class T>
BSTN<T>* get_minimum (BSTN<T>* root)
{
    if(!root) {
        return nullptr;
    }
    while (root->left) {
        root = root->left.get();
    }
    return root;
}

template <class T>
std::tuple<bool, BSTN<T>*> find_next_helper (std::unique_ptr<BSTN<T>>& root, 
        const T& elem)
{
    if (!root) {
        return std::make_tuple(false, nullptr);
    }

    std::tuple<bool, BSTN<T>*> x;
    if (elem == root->data) {
        if(root->right) {
            auto next = get_minimum(root->right.get());
            return std::make_tuple(true, next);
        } else {
            return std::make_tuple(false, root.get());
        }
    } else {
        if (elem < root->data) {
            x = find_next_helper(root->left, elem);
        } else {
            x = find_next_helper(root->right, elem);
        }
    }

    auto x_ptr = std::get<1>(x);
    if (!x_ptr) {
        return std::make_tuple(false, nullptr);
    } else {
        bool is_finished = std::get<0>(x);
        if (is_finished) {
            return x;
        } else {
            return std::make_tuple(root->left.get() == x_ptr,root.get());
        }
    }
}

template<class T>
BSTN<T>* find_next (std::unique_ptr<BSTN<T>>& root, T elem)
{
    if (!root) {
        return nullptr;
    }
    auto res = find_next_helper(root, elem);
    if(std::get<0>(res)) {
        return std::get<1>(res);
    }
    return nullptr;
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
    for (const auto& a: A) {
        auto x = find_next(root, a);
        std::cout << "next of " << a << " is "
            << (x ? x->data : -1) << std::endl;
    }
    return 0;
}
