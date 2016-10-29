#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch7.hpp"
#include "../../utils.hpp"


TEST_GROUP(StringToIntGroup)
{

};


TEST(StringToIntGroup, StringToInt0)
{
    CHECK(stringToInt("0") == 0);
    CHECK(stringToInt("-0") == 0);
}


TEST(StringToIntGroup, StringToInt1)
{
    CHECK(stringToInt("1") == 1);
    CHECK(stringToInt("-1") == -1);
}

TEST(StringToIntGroup, StringToInt1000)
{
    constexpr int  N = 100000;
    for (int i = -N; i <N; ++i) {
        CHECK(stringToInt(std::to_string(i)) == i);
    }
}


TEST_GROUP(IntToStringGroup)
{

};


TEST(IntToStringGroup, IntToString0)
{
    CHECK(intToString(0) == "0");
    CHECK(intToString(-0) == "0");
}


TEST(IntToStringGroup, IntToString1)
{
    CHECK(intToString(1) == "1");
    CHECK(intToString(-1) == "-1");
}

TEST(IntToStringGroup, IntToString1000)
{
    constexpr int  N = 100000;
    for (int i = -N; i <N; ++i) {
        CHECK(intToString(i) == std::to_string(i));
    }
}


