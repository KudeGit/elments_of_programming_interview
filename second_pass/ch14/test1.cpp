#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(IntersectionTest)
{

};


TEST(IntersectionTest, Empty)
{
    auto unique_el = unique_elements_in_sorted_array({});
    CHECK( unique_el.size() ==  0);
}



TEST(IntersectionTest, AllDistinct)
{
    auto unique_el = unique_elements_in_sorted_array({0,1,2,3,4,5,6,7,8,9,10});
    CHECK( unique_el.size() ==  11);
    for (int i = 0; i < 11; ++i) {
        CHECK(unique_el[i] == i);
    }
}

TEST(IntersectionTest, AllEqual)
{
    auto unique_el = unique_elements_in_sorted_array({0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    CHECK( unique_el.size() ==  1);
    CHECK(unique_el[0] == 0);
}

TEST(IntersectionTest, Pairs)
{
    auto unique_el = unique_elements_in_sorted_array({0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9});
    CHECK( unique_el.size() ==  10);
    for (int i = 0; i < 10; ++i) {
        CHECK(unique_el[i] == i);
    }
}


