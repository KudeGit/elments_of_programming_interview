#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch6.hpp"
#include "../../utils.hpp"
#include <vector>


TEST_GROUP(IncBigNumber)
{

};

bool operator== (const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    if(lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

TEST(IncBigNumber, CheckZero)
{
    std::vector<int> A{0};
    std::vector<int> B{1};
    increment(A);
    CHECK(A==B);
}



TEST(IncBigNumber, CheckSimple123)
{
    std::vector<int> A{1,2,3};
    std::vector<int> B{1,2,4};
    increment(A);
    CHECK(A==B);
}


TEST(IncBigNumber, Check9)
{
    std::vector<int> A{9};
    std::vector<int> B{1,0};
    increment(A);
    CHECK(A==B);
}

TEST(IncBigNumber, CheckMultipleInc)
{
    std::vector<int> A{9,0};
    increment(A);
    CHECK(A==(std::vector<int>{9,1}));
    increment(A);
    CHECK(A==(std::vector<int>{9,2}));
    increment(A);
    CHECK(A==(std::vector<int>{9,3}));
    increment(A);
    CHECK(A==(std::vector<int>{9,4}));
    increment(A);
    CHECK(A==(std::vector<int>{9,5}));
    increment(A);
    CHECK(A==(std::vector<int>{9,6}));
    increment(A);
    CHECK(A==(std::vector<int>{9,7}));
    increment(A);
    CHECK(A==(std::vector<int>{9,8}));
    increment(A);
    CHECK(A==(std::vector<int>{9,9}));
    increment(A);
    CHECK(A==(std::vector<int>{1,0,0}));
    increment(A);
    CHECK(A==(std::vector<int>{1,0,1}));
}



