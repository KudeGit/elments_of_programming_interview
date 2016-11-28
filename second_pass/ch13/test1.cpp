#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(TreeGRoup)
{

};


TEST(TreeGRoup, Empty)
{
    auto res = partition_into_anagrams("dict.txt");
    CHECK(res.empty() == 0)

}

