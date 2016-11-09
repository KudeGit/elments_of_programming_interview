#include <iostream>
#include <numeric>
#include <unordered_set>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(FindKClostestToMedian)
{
};

TEST(FindKClostestToMedian, Simple)
{
    std::vector<int> A{7,14,10,12,2,11,29,3,4};
    std::unordered_set<int> expected = {7,14,10,12,11};
    auto res = find_k_closest_to_median(A, 5);
    for (const auto& r: res) {
        CHECK(expected.find(r) != expected.end());
    }
}
