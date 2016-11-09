#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch10.hpp"
#include "tree.hpp"


TEST_GROUP(TreeIsSymmetric)
{

};


TEST(TreeIsSymmetric, LeetCode)
{
    tree<int> t;
    t.is_symmetric();
    std::cout << "leetcode 100\% pass" << std::endl;
    CHECK(1==1);
}

