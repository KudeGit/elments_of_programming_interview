#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch12.hpp"


TEST_GROUP(SearchIdentity)
{
};

TEST (SearchIdentity, EmptyVector)
{
    std::vector<int> A = {};
    auto res = search_identity(A);
    CHECK(res == -1);
}

TEST (SearchIdentity, Vector)
{
    std::vector<int> A = {-2,0,2,3,6,7,9};
    auto res = search_identity(A);
    CHECK(res == 2 || res == 3);
}
