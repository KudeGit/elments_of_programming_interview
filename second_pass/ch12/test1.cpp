#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch12.hpp"


TEST_GROUP(FindFirstOccurence)
{
};

TEST (FindFirstOccurence, EmptyVector)
{
    std::vector<int> A = {};
    auto res = find_first_occurence(A, 2);
    CHECK(res == -1);
}

TEST (FindFirstOccurence, SameElementsEven)
{
    std::vector<int> A(10,2);
    auto res = find_first_occurence(A, 2);
    CHECK(res == 0);
}

TEST (FindFirstOccurence, SameElementsOdd)
{
    std::vector<int> A(11,2);
    auto res = find_first_occurence(A, 2);
    CHECK(res == 0);
}

TEST (FindFirstOccurence, Example1)
{
    std::vector<int> A{0,1,2,2,2,3,4,5,6,7,8};
    auto res = find_first_occurence(A, 2);
    CHECK(res == 2);
    res = find_first_occurence(A, 0);
    CHECK(res == 0);
    res = find_first_occurence(A, 1);
    CHECK(res == 1);
    res = find_first_occurence(A, 3);
    CHECK(res == 5);
}

TEST (FindFirstOccurence, Example2)
{
    std::vector<int> A{0,1,2,2,2,3,4,5,6,7,8,8,8,8};
    auto res = find_first_occurence(A, 8);
    CHECK(res == 10);
}
