#include <iostream>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "ch1.hpp"



TEST_GROUP(SwapBit)
{
};

TEST(SwapBit, Check0)
{
    CHECK(reverse_bits(0) == 0);
}

TEST(SwapBit, CheckPowerOf2)
{
    for (int i = 0; i < 63; ++i) {
        uint64_t reversed = 0x1lu << (63 - i);
        uint64_t test = 0x1lu << i;
        CHECK(reverse_bits(test) == reversed);
    }
}

TEST(SwapBit, CheckPowerAllOnes)
{
    uint64_t test = ~0x0ul;
    CHECK(reverse_bits(test) == test);
}

