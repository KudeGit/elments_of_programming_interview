#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch16.hpp"


TEST_GROUP(RegExp)
{

};


TEST(RegExp, Empty)
{
    CHECK(0 == 0);
}
