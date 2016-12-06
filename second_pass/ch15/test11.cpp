#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Empty)
{
    ListNode<int>* head = nullptr;
    auto root = rebuild_from_sorted_list(head);
    CHECK(root == nullptr);
}
