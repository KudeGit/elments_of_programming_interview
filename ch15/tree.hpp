#include <iostream>
#include <memory>

template <class T>
struct TreeNode {
    T data;
    std::shared_ptr<TreeNode<T>> left = nullptr;
    std::shared_ptr<TreeNode<T>> right = nullptr;
};


