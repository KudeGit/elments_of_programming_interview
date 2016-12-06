#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(MinDist3SortedArray)
{

};


TEST(MinDist3SortedArray, GeeksForGeeks1)
{
    std::vector<std::vector<int>> A{{1, 4, 10},{2, 15, 20}, {10, 12}};
    auto res = min_distance_3_sorted_array(A);
    CHECK(res == 5);

}

TEST(MinDist3SortedArray, GeeksForGeeks2)
{
    std::vector<std::vector<int>> A{{20, 24, 100},
        {2, 19, 22, 79, 800},
        {10, 12, 23, 24, 119}};
    auto res = min_distance_3_sorted_array(A);
    CHECK(res == 2);

}

