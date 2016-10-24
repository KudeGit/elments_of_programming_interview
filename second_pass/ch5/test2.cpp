#include <iostream>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "ch1.hpp"



TEST_GROUP(SwapBit)
{
};

TEST(SwapBit, Check0)
{
    CHECK(swap_bit(0,0,0) == 0);
}

TEST(SwapBit, SameValueBit)
{
    CHECK(swap_bit(15, 0, 0) == 15);
    CHECK(swap_bit(16, 4, 4) == 16);
    CHECK(swap_bit(16, 1, 1) == 16);
}



TEST(SwapBit, differentBit)
{
    CHECK(swap_bit(15, 0, 4) == 30);
    CHECK(swap_bit(16, 4, 0) == 1);
    CHECK(swap_bit(16, 4, 1) == 2);
    CHECK(swap_bit(16, 4, 5) == 32);
}

