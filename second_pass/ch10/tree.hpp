#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <stack>
#define debug(x) std::cout << #x ":" << x << std::endl

template <class T>
struct tree_node {
    //in reality maybe we want a pointer to the data
    T data;
    std::unique_ptr<tree_node<T>> left;
    std::unique_ptr<tree_node<T>> right;
    tree_node(): left(nullptr), right(nullptr){}
    tree_node(T x):data(x), left(nullptr), right(nullptr){}
};
template <class T>
std::ostream& operator<< (std::ostream& out, const tree_node<T>& tn)
{
    out << tn.data;
    return out;
}


template <class T>
struct tree {
    std::unique_ptr<tree_node<T>> root = nullptr;
    void add_node (T data);
    template <class F>
    void visit(tree_node<T>* x, F f) {
        if (x == nullptr) {
            return;
        }
        visit(x->left.get(), f);
        f(x);
        visit(x->right.get(), f);

    }
    template <class F>
    void visit(F f = [](tree_node<T> __unused *x) {return;}) {
        visit(root.get(), f);
    }
    int is_balanced (tree_node<T>* x, bool& balanced) {
        if (!x) {
            return 0;
        }
        auto left_h = is_balanced(x->left.get(), balanced);
        auto right_h = is_balanced(x->right.get(), balanced);
        balanced &= (std::abs(left_h - right_h) <= 1);
        return std::max(left_h, right_h)+1;
    }

    bool is_balanced() {
        bool balanced = true;
        is_balanced(root.get(), balanced);
        return balanced;
    }
    int is_k_balanced (tree_node<T>* x, int k,  tree_node<T>*& res) {
        if (!x) {
            return 0;
        }
        auto lh = is_k_balanced(x->left.get(),  k, res);
        auto rh = is_k_balanced(x->right.get(), k, res);
        if (!res) {
            if (std::abs(lh - rh) >= k) {
                res = x;
            }
        }
        return std::max(lh, rh) + 1;
    }

    tree_node<T>* is_k_balanced (int k) {
        tree_node<T>* res = nullptr;
        is_k_balanced(root.get(), k, res);
        return res;
    }
};
template< class T>
void tree<T>::add_node(T data)
{
    if (!root) {
        root = std::move(std::make_unique<tree_node<T>>(data));
        return;
    }
    auto x = root.get();
    auto prev = x;

    while (x) {
        prev = x;
        if(data <= x->data) {
            x = x->left.get();
        } else {
            x = x->right.get();
        }
    }
    if (data <= prev->data) {
        prev->left = std::make_unique<tree_node<T>>(data);
    } else {
        prev->right = std::make_unique<tree_node<T>>(data);
    }
}



template <class T>
struct tree_iterator {
    typedef tree_iterator<T>            _Self;
    typedef tree_node<T>                _Node;
    typedef ptrdiff_t                   difference_type;
    typedef std::input_iterator_tag     iterator_category;
    typedef T                           value_type;
    typedef T*                          pointer;
    typedef T&                          reference;

    tree_node<T>* t_node;
    //std::stack<_Self> S;

    tree_iterator():t_node(){}
    tree_iterator(tree_node<T>* x):t_node(x){}

    reference operator*() const {
        return t_node->data;
    }
    pointer operator->() const {
        return &(operator*());
    }
    
    _Self& operator++() {
        while(1) {
            return *this;
        }
    }
};

template <class T>
bool operator< (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return lhs.data < rhs.data;
}

template <class T>
bool operator> (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return operator<(rhs,lhs);
}

template <class T>
bool operator<= (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return !operator>(lhs, rhs);
}


template <class T>
bool operator>= (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return !operator<(lhs, rhs);
}

template <class T>
bool operator== (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return lhs->data == rhs->data;
}

template <class T>
bool operator!= (const tree_node<T>& lhs, const tree_node<T>& rhs)
{
    return !operator==(lhs, rhs);
}

#endif //__TREE_HPP__
