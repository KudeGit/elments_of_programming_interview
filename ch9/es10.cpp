#include <iostream>
#include "../ch10/btree.hpp"
#include <queue>
#include <memory>
#include "../utils.hpp"


template <class T>
void empty_fill_and_print (std::queue<std::shared_ptr<TreeNode<T>>>& q1, 
        std::queue<std::shared_ptr<TreeNode<T>>>& q2)
{
    while(!q1.empty()) {
        std::cout << q1.front()->data << " ";
        auto x = q1.front(); q1.pop();
        if(x->left) {
            q2.push(x->left);
        }
        if (x->right) {
            q2.push(x->right);
        }
    }
}

template <class T>
void print_b_tree_by_level (std::unique_ptr<TreeNode<T>> root)
{
    if(!root) {
        return;
    }
    std::queue<std::unique_ptr<TreeNode<T>>> q1, q2;
    q1.push(root);
    while (!(q1.empty() && q2.empty())) {
        empty_fill_and_print(q1, q2);
        std::cout << std::endl;
        empty_fill_and_print(q2, q1);
        std::cout << std::endl;
    }
}


int main (void)
{
    auto a = std::make_shared<TreeNode<char>>();
    auto b = std::make_shared<TreeNode<char>>();
    auto c = std::make_shared<TreeNode<char>>();
    auto d = std::make_shared<TreeNode<char>>();
    auto e = std::make_shared<TreeNode<char>>();
    auto f = std::make_shared<TreeNode<char>>();
    auto g = std::make_shared<TreeNode<char>>();
    a->data = 'a';
    a->left = b; a->right = c;

    b->data = 'b';
    b->left = d; b->right = e;

    c->data = 'c';
    c->left = f; c->right = g;

    d->data = 'd';
    e->data = 'e';
    f->data = 'f';
    g->data = 'g';

    print_b_tree_by_level(a);
    return 0;
}
