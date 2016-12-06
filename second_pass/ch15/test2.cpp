#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"

#include "../../utils.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Simple1)
{
    auto root = std::move(build_fig2());
    auto res108 = find_recursive(root.get(), 108);
    CHECK(res108 != nullptr);
    CHECK(res108->val == 108);
    CHECK(res108 == root->left.get());
    auto res285 = find_recursive(root.get(), 285);
    CHECK(res285 != nullptr);
    CHECK(res285->val == 285);
    CHECK(res285 == root->right.get());
}

TEST(TreeGRoup, Simple2)
{
    auto root = std::move(build_fig2());
    auto res108 = find_iterative(root.get(), 108);
    CHECK(res108 != nullptr);
    CHECK(res108->val == 108);
    CHECK(res108 == root->left.get());
    auto res285 = find_iterative(root.get(), 285);
    CHECK(res285 != nullptr);
    CHECK(res285->val == 285);
    CHECK(res285 == root->right.get());
}


