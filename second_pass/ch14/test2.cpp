#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(MergeInPlace)
{

};


TEST(MergeInPlace, Empty)
{
    std::vector<int> A{};
    std::vector<int> B{};
    merge_in_place(A,0,B);
    CHECK(A.size() ==  0);
}

TEST(MergeInPlace, SimpleSorted)
{
    std::vector<int> A{0,1,2,3,0,0,0,0};
    std::vector<int> B{0,1,2,3};
    merge_in_place(A,4,B);
    for (int i = 0; i < 4; i+=2){
        CHECK(A[2*i] == i);
        CHECK(A[2*i+1] == i);
    }
}

TEST(MergeInPlace, SimpleSorted1)
{
    std::vector<int> A{-4,-3,-2,-1,0,0,0,0};
    std::vector<int> B{0,1,2,3};
    merge_in_place(A,4,B);
    for (int i = -4; i < 4; ++i){
        CHECK(A[i+4] == i);
    }
}

TEST(MergeInPlace, SimpleSorted2)
{
    std::vector<int> A{0,1,2,3,0,0,0,0};
    std::vector<int> B{-4,-3,-2,-1};
    merge_in_place(A,4,B);
    for (int i = -4; i < 4; ++i){
        CHECK(A[i+4] == i);
    }
}





