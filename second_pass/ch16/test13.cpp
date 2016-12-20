#include <iostream>
#include <vector>
#include <random>
#include "../../utils.hpp"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch16.hpp"


TEST_GROUP(InvestionCount)
{

};


TEST(InvestionCount, Empty)
{
    std::vector<int> A{};
    CHECK(countInversionSimple(A) == 0)
}

TEST(InvestionCount, Geeks1)
{
    std::vector<int>A{1, 20, 6, 4, 5};
    CHECK(countInversionSimple(A) == 5);
}

TEST(InvestionCount, Geeks1Merge)
{
    std::vector<int>A{1, 20, 6, 4, 5};
    CHECK(countInversion(A) == 5);
}

TEST(InvestionCount, RandomArray)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const int N = 1000;
    std::uniform_int_distribution<> dis(0, N);

    for (int i = 0; i < 100; ++i) {
        std::vector<int> A;
        for (int i = 0; i < N; ++i) {
            A.emplace_back(dis(gen));
        }
        auto r2 = countInversionSimple(A);
        auto r1 = countInversion(A);
        CHECK(r1 == r2);
    }
}
