#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "es4.hpp"


TEST_GROUP(UniqueTestGroup)
{

};


TEST(UniqueTestGroup, Empty)
{
    std::vector<int> A{};
    find_unique_elements(A);
    CHECK(A.size() == 0);
}

TEST(UniqueTestGroup, SimpleSorted)
{
    std::vector<int> A{0,0,1,1,2,2,3,3,4,4,5,5};
    find_unique_elements(A);
    CHECK(A.size() == 6);
    for (int i = 0; i < 6; ++i) {
        CHECK(A[i] == i);
    }
}

TEST(UniqueTestGroup, SimpleShuffled)
{
    std::vector<int> A{0,0,1,1,2,2,3,3,4,4,5,5};
    std::random_shuffle(A.begin(), A.end());
    find_unique_elements(A);
    CHECK(A.size() == 6);
    for (int i = 0; i < 6; ++i) {
        CHECK(A[i] == i);
    }
}


TEST_GROUP(MyUniqueTestGroup) {};
TEST(MyUniqueTestGroup, SimpleTest)
{
    std::vector<int> A{0,1,2,3,4,5};
    auto last = my_unique(A.begin(), A.end());
    CHECK(last == A.end());
    for (int i = 0; i < A.size(); ++i) {
        CHECK(A[i] == i);
    }
}
TEST(MyUniqueTestGroup, SimpleTest1)
{
    std::vector<int> A{0,0,1,1,2,2,3,3,4,4,5,5};
    auto last = my_unique(A.begin(), A.end());
    CHECK(last == A.begin() + 6);
    for (int i = 0; i < 6; ++i) {
        CHECK(A[i] == i);
    }
}

