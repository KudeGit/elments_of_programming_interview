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
    tree<int> t;
    t.is_balanced();
    CHECK(0 == 0);
}

