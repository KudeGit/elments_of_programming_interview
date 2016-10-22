#include <iostream>
#include "tree.hpp"
#include "../utils.hpp"



template <class T>
BSTN<T>* get_lca_bst (const std::unique_ptr<BSTN<int>>& root,
        const T& data1, const T& data2)
{
    if (!root) {
        return nullptr;
    }
    BSTN<int>* x = root.get();
    while (x) {
        if (data1 < x->data && data2 < x->data) {
            x = x->left.get();
        } else if (data1 > x->data && data2 > x->data) {
            x = x->right.get();
        } else {
            return x;
        }
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
    auto x = get_lca_bst(root, 0, 7);
    std::cout << x->data << std::endl;
    return 0;
}
