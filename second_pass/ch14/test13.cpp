
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(MinUnachievableChange)
{

};


TEST(MinUnachievableChange, Simple1)
{
    std::vector<int> C{1,2,3};
    CHECK(smallest_nonconstructible_change(C) == 7);
}

TEST(MinUnachievableChange, Simple2)
{
    std::vector<int> C{1,2,4};
    CHECK(smallest_nonconstructible_change(C) == 8);
}

TEST(MinUnachievableChange, Simple3)
{
    std::vector<int> C{1,2,5};
    CHECK(smallest_nonconstructible_change(C) == 4);
}
