#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch16.hpp"


TEST_GROUP(Hanoy)
{

};


TEST(Hanoy, Empty)
{
    hanoy(3, 'A', 'B', 'C');
    CHECK(0 == 0);
}

