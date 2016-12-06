
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(RebuildFromPreorder)
{

};


TEST(RebuildFromPreorder, Simple1)
{
    auto root = build_simple_bst();
    std::vector<int> preorder;
    pre_order_visit(root.get(), [&preorder](const BSTNode<int>* n) {
                preorder.emplace_back(n->val);
            });

    std::vector<int> inorder;
    in_order_visit(root.get(), [&inorder](const BSTNode<int>* n) {
                inorder.emplace_back(n->val);
            });
    auto root1 = rebuild_from_preorder(preorder);
    std::vector<int> preorder1;
    std::vector<int> inorder1;
    pre_order_visit(root.get(), [&preorder1](const BSTNode<int>* n) {
                preorder1.emplace_back(n->val);
            });
    in_order_visit(root.get(), [&inorder1](const BSTNode<int>* n) {
                inorder1.emplace_back(n->val);
            });

    CHECK(preorder.size() == preorder1.size());
    CHECK(inorder.size() == inorder1.size());
    for (int i = 0; i < preorder1.size(); ++i) {
        CHECK(preorder[i] == preorder1[i])
    }
    for (int i = 0; i < inorder1.size(); ++i) {
        CHECK(inorder[i] == inorder1[i])
    }
}

TEST(RebuildFromPreorder, Fig1)
{
    auto root = build_fig1();
    std::vector<int> preorder;
    pre_order_visit(root.get(), [&preorder](const BSTNode<int>* n) {
                preorder.emplace_back(n->val);
            });

    std::vector<int> inorder;
    in_order_visit(root.get(), [&inorder](const BSTNode<int>* n) {
                inorder.emplace_back(n->val);
            });
    auto root1 = rebuild_from_preorder(preorder);
    std::vector<int> preorder1;
    std::vector<int> inorder1;
    pre_order_visit(root.get(), [&preorder1](const BSTNode<int>* n) {
                preorder1.emplace_back(n->val);
            });
    in_order_visit(root.get(), [&inorder1](const BSTNode<int>* n) {
                inorder1.emplace_back(n->val);
            });

    CHECK(preorder.size() == preorder1.size());
    CHECK(inorder.size() == inorder1.size());
    for (int i = 0; i < preorder1.size(); ++i) {
        CHECK(preorder[i] == preorder1[i])
    }
    for (int i = 0; i < inorder1.size(); ++i) {
        CHECK(inorder[i] == inorder1[i])
    }
}

TEST(RebuildFromPreorder, Fig2)
{
    auto root = build_fig2();
    std::vector<int> preorder;
    pre_order_visit(root.get(), [&preorder](const BSTNode<int>* n) {
                preorder.emplace_back(n->val);
            });

    std::vector<int> inorder;
    in_order_visit(root.get(), [&inorder](const BSTNode<int>* n) {
                inorder.emplace_back(n->val);
            });
    auto root1 = rebuild_from_preorder(preorder);
    std::vector<int> preorder1;
    std::vector<int> inorder1;
    pre_order_visit(root.get(), [&preorder1](const BSTNode<int>* n) {
                preorder1.emplace_back(n->val);
            });
    in_order_visit(root.get(), [&inorder1](const BSTNode<int>* n) {
                inorder1.emplace_back(n->val);
            });

    CHECK(preorder.size() == preorder1.size());
    CHECK(inorder.size() == inorder1.size());
    for (int i = 0; i < preorder1.size(); ++i) {
        CHECK(preorder[i] == preorder1[i])
    }
    for (int i = 0; i < inorder1.size(); ++i) {
        CHECK(inorder[i] == inorder1[i])
    }
}
