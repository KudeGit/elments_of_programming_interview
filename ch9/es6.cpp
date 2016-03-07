#include <iostream>
#include <stack>
#include "../ch15/tree.hpp"

template <class T>
void inorder_visit_no_recursion (std::shared_ptr<TreeNode<T>> root)
{
    auto x = root;
    std::stack<std::shared_ptr<TreeNode<T>>> s;
    while (x || !s.empty()) {
        if(x) {
            s.push(x);
            x = x->left;
        } else {
            x = s.top(); s.pop();
            std::cout << x->data << std::endl;
            x = x->right;
        }
    }
}

int main (void)
{
    auto root = std::make_shared<TreeNode<int>>();
    root->data = 12;
    inorder_visit_no_recursion(root);
    return 0;
}
