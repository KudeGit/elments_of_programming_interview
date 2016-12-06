
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Empty)
{
    std::vector<int> A{1,2,3};

    auto root = rebuild_from_sorted_vector (A);
    std::vector<int> preorder;
    std::vector<int> inorder;
    pre_order_visit(root.get(),[&preorder](const BSTNode<int>* n) {
                preorder.emplace_back(n->val);
            });
    in_order_visit(root.get(),[&inorder](const BSTNode<int>* n) {
                inorder.emplace_back(n->val);
            });

    CHECK(preorder[0] == 2);
    CHECK(preorder[1] == 1);
    CHECK(preorder[2] == 3);

    CHECK(inorder[0] == A[0]);
    CHECK(inorder[1] == A[1]);
    CHECK(inorder[2] == A[2]);
}

