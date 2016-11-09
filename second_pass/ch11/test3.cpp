#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(AlmostSorted)
{
};

TEST(AlmostSorted, AlreadySorted)
{
    std::string s1("0 1 2 3 4 5 6 7 8 9 10");
    std::stringstream ss_in(s1);
    std::stringstream ss_out;
    almost_sorted(ss_in, ss_out, 2);
    auto j = 0;
    auto i = 0;
    while(ss_out >> i) {
        CHECK(i == j++);
    }
}
TEST(AlmostSorted, MaxDisplacement)
{
    std::string s1("10 1 2 3 4 5 6 7 8 9 0");
    std::stringstream ss_in(s1);
    std::stringstream ss_out;
    almost_sorted(ss_in, ss_out, 10);
    auto j = 0;
    auto i = 0;
    while(ss_out >> i) {
        CHECK(i == j++);
    }
}

