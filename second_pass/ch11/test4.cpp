#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(MedianFinder)
{
};

TEST(MedianFinder, Simple)
{
    MedianFinder mf;
    mf.addNum(2);
    CHECK(mf.findMedian() == 2.0);
    mf.addNum(3);
    CHECK(mf.findMedian() == 2.5);
}

//additional tests done in leetcode: 
//https://leetcode.com/problems/find-median-from-data-stream/
