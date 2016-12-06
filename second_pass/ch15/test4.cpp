#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(FindKLargestGroup)
{

};


TEST(FindKLargestGroup, Empty)
{
    auto root = build_fig1();
    auto res = find_k_largest(root.get(), 4);
    CHECK(res.size() == 4);
    CHECK(res[0]->val == 53);
    CHECK(res[1]->val == 47);
    CHECK(res[2]->val == 43);
    CHECK(res[3]->val == 41);
}

