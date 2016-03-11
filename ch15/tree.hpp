#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include "../utils.hpp"

template <class T>
struct TreeNode {
    T data;
    std::weak_ptr<TreeNode<T>> parent = nullptr;
    std::shared_ptr<TreeNode<T>> left = nullptr;
    std::shared_ptr<TreeNode<T>> right = nullptr;
};


template <class T>
struct BSTN {
    T data;
    BSTN():left(nullptr), right(nullptr) {}
    BSTN(const T& e) : data(e), left(nullptr), right(nullptr) {}
    BSTN(const BSTN& other) : data(other->data), left(nullptr), right(nullptr) {}
    BSTN(const BSTN&& other) : data(std::move(other.data)), left(nullptr), right(nullptr) {}
    ~BSTN(){}
    std::unique_ptr<BSTN<T>> left = nullptr;
    std::unique_ptr<BSTN<T>> right = nullptr;
};


template <class T>
std::ostream& operator<< (std::ostream& out, const std::unique_ptr<BSTN<T>>& node) 
{
    out << node->data;
    return out;
}

template <class T>
void insert_element_in_bst (std::unique_ptr<BSTN<T>>& root, T e)
{
    if(!root) {
        std::unique_ptr<BSTN<T>> tmp_root(new BSTN<T>(e));
        root = std::move(tmp_root);
        return;
    }
    auto current = root.get();
    auto parent = root.get();
    parent = nullptr;
    while (current) {
        parent = current;
        if (e <= current->data) {
            current = current->left.get();
        } else {
            current = current->right.get();
        }
    }
    if (parent) {
        std::unique_ptr<BSTN<T>> new_node(new BSTN<T>(e));
        if ( e <= parent->data) {
            parent->left = std::move(new_node);
        } else {
            parent->right = std::move(new_node);
        }
    }
    return;
}

template <class T>
std::unique_ptr<BSTN<T>> create_bst (const std::vector<T>& elems)
{
    std::unique_ptr<BSTN<T>> root(nullptr);
    if(!elems.empty()) {
        for (const auto& e: elems) {
            insert_element_in_bst(root, e);
        }
    }
    return root;
}



template <class T>
void in_order_visit_no_rec (const std::unique_ptr<BSTN<T>>& root)
{
    if (!root) {
        return;
    }
    auto x = root.get();
    std::stack<decltype(x)> s;
    while (x || !s.empty()) {
        if (x) {
            s.push(x);
            x = x->left.get();
        } else {
            x = s.top(); s.pop();
            std::cout << x->data << std::endl;
            x = x->right.get();
        }
    }
    return;
}


