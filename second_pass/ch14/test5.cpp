#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "es5.hpp"


TEST_GROUP(MaxConcurrentEvents)
{

};


TEST(MaxConcurrentEvents, Empty)
{
    std::vector<Event> events{
        {1,5}, {2,7}, {4,5}, {6,10}, {8,9}, {9,17}, {12,15}, {11,13}, {14,15}
    };
    auto res = max_concurrent_events(events);
    CHECK(res == 3);
}
