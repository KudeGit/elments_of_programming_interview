#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(AlmostSorted)
{
};

TEST(AlmostSorted, AlreadySorted)
{
    std::string s1("1 2 3 4 5 6 7 8 9 10");
    std::stringstream ss_in(s1);
    std::stringstream& ss_out;
    almost_sorted(ss_in, ss_out);
    CHECK(0 == 1);

}

