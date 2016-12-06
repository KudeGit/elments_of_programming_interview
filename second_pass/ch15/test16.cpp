#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "es16.hpp"


TEST_GROUP(TreeGRoup)
{
};


TEST(TreeGRoup, Empty)
{
    auto res = find_top_student({});
    CHECK(res == "no such student");
}
TEST(TreeGRoup, SngleStudent1Score)
{
    std::vector<std::pair<std::string, int>> A{
        {"A", 100}
    };
    auto res = find_top_student(A);
    CHECK(res == "no such student");
}

TEST(TreeGRoup, SngleStudent2Score)
{
    std::vector<std::pair<std::string, int>> A{
        {"A", 100},
        {"A", 100}
    };
    auto res = find_top_student(A);
    CHECK(res == "no such student");
}

TEST(TreeGRoup, SngleStudent3Score)
{
    std::vector<std::pair<std::string, int>> A{
        {"A", 100},
        {"A", 100},
        {"A", 100}
    };
    auto res = find_top_student(A);
    CHECK(res == "A");
}

TEST(TreeGRoup, TwoStudent3Score)
{
    std::vector<std::pair<std::string, int>> A{
        {"A", 100},
        {"A", 100},
        {"A", 100},
        {"B", 10},
        {"B", 10},
        {"B", 10}
    };
    auto res = find_top_student(A);
    CHECK(res == "A");
}
