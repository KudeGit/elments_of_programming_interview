#include <iostream>
#include "btree.hpp"
#include "../utils.hpp"


void check_path_with_weight (const std::shared_ptr<BTN<int>>& root, 
        const int weight, int current, bool& found)
{
    if (!root) {
        return;
    }

    current += root->data;
    if (!root->left && root->right){
        if(!found) {
            found = weight == current ? true : false;
        }
        return;
    }
    if (!found) {
        check_path_with_weight(root->left, weight, current, found);
    }
    if (!found) {
        check_path_with_weight(root->right, weight, current, found);
    }
    return;
}

bool check_path_with_weight (const std::shared_ptr<BTN<int>>& root, 
        const int weight)
{
    int current = 0;
    bool found = false;
    check_path_with_weight(root, weight, current, found);
    return found;
}


int main (void)
{
    auto root = create_int_tree();
    auto res = check_path_with_weight(root, 591);
    std::cout << res << std::endl;
    return 0;
}
