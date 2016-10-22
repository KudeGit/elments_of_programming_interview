#include <iostream>
#include "tree.hpp"

template <class T>
void
find_largest_k_elems_helper (const std::unique_ptr<BSTN<T>>& root, 
        std::vector<BSTN<T>*>& res,
        int k)
{
    if (!root) {
        return;
    }
    if(res.size() >= k) {
        return;
    }
    find_largest_k_elems_helper(root->right, res, k);
    if (res.size() < k) {
        res.push_back(root.get());
    }
    find_largest_k_elems_helper(root->left, res, k);
}


template <class T>
std::vector<BSTN<T>*>
find_largest_k_elems (const std::unique_ptr<BSTN<T>>& root, int k)
{
    std::vector<BSTN<T>*> res;
    find_largest_k_elems_helper(root, res, k);
    return res;
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
    auto res = find_largest_k_elems(root, 3);
    for (const auto& x: res) {
        std::cout << x->data << ", ";
    }
    std::cout << std::endl;
    return 0;
}
