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
    tree<int> t;
    t.add_node(10);
    t.add_node(5);
    t.add_node(15);
    auto print_node = [](tree_node<int>* x){std::cout << *x << std::endl;};
    t.visit(print_node);

}

