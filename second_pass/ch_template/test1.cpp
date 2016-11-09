#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch_x.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Empty)
{
    CHECK(0 == 1);
}

