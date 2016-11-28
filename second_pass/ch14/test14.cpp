
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(CompletionSearch)
{
};


TEST(CompletionSearch, Simple1)
{
    std::vector<int> A{90, 30, 100, 40};
    auto res = search_completeness(210, A);
    CHECK(res == 60);
}
