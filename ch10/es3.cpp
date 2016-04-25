#include <iostream>
#include "btree.hpp"
#include "../utils.hpp"

template<class T>
bool is_simmetric_helper (const std::shared_ptr<BTN<T>>& left,
        const std::shared_ptr<BTN<T>>& right)
{

    if (!left && !right) {
        //debug("both null");
        return true;
    }
    if ((!left && right) || (left && !right)) {
        //debug("one is not null");
        return false;
    }
    if (left->data != right->data) {
        //debug((*left));
        //debug((*right));
        //debug("data are different");
        return false;
    }
    return is_simmetric_helper(left->left, right->right) && 
        is_simmetric_helper(left->right, right->left);
}



template<class T>
bool is_simmetric (const std::shared_ptr<BTN<T>>& root)
{
   if (!root) {
       return true;
   }
   return is_simmetric_helper (root->left, root->right);
}



int main (void)
{
    auto root1 = create_symmetric_tree();
    auto root2 = create_asymmetric_tree1();
    auto root3 = create_asymmetric_tree2();
    std::cout << "symmetric tree:" << is_simmetric(root1) << std::endl;
    std::cout << "asymmetric tree(value):" << is_simmetric(root2) << std::endl;
    std::cout << "asymmetric tree(structure):" << is_simmetric(root3) << std::endl;
    return 0;
}
