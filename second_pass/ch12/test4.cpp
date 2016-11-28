#include <iostream>
#include <algorithm>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch12.hpp"





TEST_GROUP(RotatedVector)
{
};

TEST (RotatedVector, EmptyVector)
{
    std::vector<int> A = {};
    auto res = find_smallest(A);
    CHECK(res == -1);
}

TEST (RotatedVector, Vector1)
{
    std::vector<int> A = {4,5,6,7,8,1,2,3};
    auto res = find_smallest(A);
    std::cout << A[res] << std::endl;
    CHECK(res == 5);
}

TEST (RotatedVector, VectorTestAllShifts)
{
    std::vector<int> A = {1,2,3,4,5,6,7,9};
    for (int i = 0; i < A.size(); ++i) {
        std::rotate(A.begin(), A.begin()+i, A.end());
        auto res = find_smallest(A);
        CHECK(A[res] == 1);
    }
}
