
#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(IntervalCovering)
{

};
TEST(IntervalCovering, Simple1)
{
    std::vector<Event> events{};
    auto res = minimum_covering(events);
    CHECK(res.empty() == true);
}
TEST(IntervalCovering, SingleElements)
{
    std::vector<Event> events{{0,1}};
    auto res = minimum_covering(events);
    CHECK(res.size() == 1);
    CHECK(res[0] == 1);
}

TEST(IntervalCovering, FromBook)
{
    std::vector<Event> events{
        {1,5}, {2,7}, {4,5}, {6,10}, {8,9}, {9,17}, {12,15}, {11,13}, {14,15}
    };

    auto res = minimum_covering(events);
    CHECK(res.size() == 4);
    CHECK(res[0] == 5);
    CHECK(res[1] == 9);
    CHECK(res[2] == 13);
    CHECK(res[3] == 15);
}
