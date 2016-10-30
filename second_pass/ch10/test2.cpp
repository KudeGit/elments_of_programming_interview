#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch10.hpp"
#include "tree.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Empty)
{
    //tested on leetcode:
    //https://leetcode.com/problems/balanced-binary-tree/
    auto tA = std::make_unique<tree_node<char>>('A');
    auto tB = std::make_unique<tree_node<char>>('B');
    auto tC = std::make_unique<tree_node<char>>('C');
    auto tD = std::make_unique<tree_node<char>>('D');
    auto tE = std::make_unique<tree_node<char>>('E');
    auto tF = std::make_unique<tree_node<char>>('F');
    auto tG = std::make_unique<tree_node<char>>('G');
    auto tH = std::make_unique<tree_node<char>>('H');
    auto tJ = std::make_unique<tree_node<char>>('J');
    auto tK = std::make_unique<tree_node<char>>('K');
    auto tI = std::make_unique<tree_node<char>>('I');
    auto tL = std::make_unique<tree_node<char>>('L');
    auto tM = std::make_unique<tree_node<char>>('M');
    auto tN = std::make_unique<tree_node<char>>('N');
    auto tO = std::make_unique<tree_node<char>>('O');
    auto tP = std::make_unique<tree_node<char>>('P');
    tA->left = std::move(tB); tA->right = std::move(tI);
    tA->left->left = std::move(tC); tA->left->right = std::move(tF);
    tA->left->left->left = std::move(tD); tA->left->left->right = std::move(tE);
    tA->left->right->right = std::move(tG);
    tA->left->right->right->left = std::move(tH);
    tA->right->left = std::move(tJ); tA->right->right = std::move(tO);
    tA->right->left->right = std::move(tK);
    tA->right->left->right->left = std::move(tL); tA->right->left->right->right = std::move(tN);
    tA->right->left->right->left->right = std::move(tM);
    tA->right->right->right = std::move(tP);

    tree<char> t;
    t.root = std::move(tA);
    //t.visit([](tree_node<char>* x){std::cout << *x << std::endl;});
    auto x = t.is_k_balanced(3);
    CHECK(x != nullptr);
    CHECK(x->data == 'J');
}

