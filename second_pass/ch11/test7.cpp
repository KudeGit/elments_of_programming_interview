#include <iostream>
#include <numeric>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(FairBonuses)
{
};

TEST(FairBonuses, Simple)
{
    std::vector<int> locs{300,400,500,200};
    std::vector<int> exp_bonuses{1,2,3,1};
    auto res= compute_fair_bonuses(locs);
    int i = 0;
    for (const auto& r: res) {
        CHECK(r == exp_bonuses[i++]);
    }
    CHECK(std::accumulate(res.begin(), res.end(), 0) == 7);
}
