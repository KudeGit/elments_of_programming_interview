
#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch12.hpp"


TEST_GROUP(FindFirstLargest)
{
};

TEST (FindFirstLargest, EmptyArray)
{
    std::vector<int> A = {};
    auto res = find_first_largest(A, 2);
    CHECK(res == -1);
}

TEST (FindFirstLargest, SameElementsEven)
{
    std::vector<int> A(10,2);
    auto res = find_first_largest(A, 2);
    CHECK(res == -1);
}

TEST (FindFirstLargest, SameElementsOdd)
{
    std::vector<int> A(10,2);
    auto res = find_first_largest(A, 2);
    CHECK(res == -1);
}

TEST (FindFirstLargest, SameElementsEven1)
{
    std::vector<int> A(10,2);
    auto res = find_first_largest(A, 1);
    CHECK(res == 0);
}


TEST (FindFirstLargest, SameElementsEven2)
{
    std::vector<int> A(10,2);
    auto res = find_first_largest(A, 0);
    CHECK(res == 0);
}

TEST (FindFirstLargest, Example1)
{
    std::vector<int> A{-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    CHECK(find_first_largest(A, 500) == -1);
    CHECK(find_first_largest(A, 101) == 3);
}


