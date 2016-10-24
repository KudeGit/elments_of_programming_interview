#include <iostream>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include <stdexcept>
#include "ch1.hpp"
#include "../../utils.hpp"

int countOnes (uint64_t a)
{
    int n = 0;
    while (a) {
        a &= a-1;
        ++n;
    }
    return n;
}

uint64_t find_closest_same_weight_stupid (uint64_t a)
{
    uint64_t ah = a;
    uint64_t al = a;
    auto n_ones = countOnes(a);
    while (1) {
        if (countOnes(--al) == n_ones) {
            return al;
        }
        if (countOnes(++ah) == n_ones) {
            return ah;
        }
        if (al == a || ah == a) {
            throw std::invalid_argument("all bits are 1 or 0");
        }
    }
}

TEST_GROUP(countOnesGroup) {};
TEST(countOnesGroup, Zero) {
    CHECK(countOnes(0) == 0);
}
TEST(countOnesGroup, powerOf2) {
    for (int i = 0; i < 64; ++i) {
        uint64_t test = (0x01ul << 1);
        CHECK(countOnes(test) == 1);
    }
}

TEST(countOnesGroup, powerOf2Minus1) {
    for (int i = 0; i < 64; ++i) {
        uint64_t test = (0x01ul << i) - 1;
        CHECK(countOnes(test) == i);
    }
}

TEST_GROUP(FindSameWeight)
{
};

TEST(FindSameWeight, Check1)
{
    CHECK(find_closest_same_weight(1) == 2);
}

TEST(FindSameWeight, Check2)
{
    CHECK(find_closest_same_weight(2) == 1);
}

TEST(FindSameWeight, Check256)
{
    for (int i = 1; i < 256; ++i) {
        CHECK(find_closest_same_weight_stupid(i) == find_closest_same_weight(i));
    }
}
