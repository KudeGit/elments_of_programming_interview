#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch6.hpp"
#include "../../utils.hpp"
#include <vector>


TEST_GROUP(DutchFlag)
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

TEST(DutchFlag, CheckZero)
{
    std::vector<int> A(10, 0);
    std::vector<int> B(10, 0);
    dutch_flag(A, 3);
    CHECK(A==B);
}



TEST(DutchFlag, CheckSimple123)
{
    std::vector<int> A{1,2,3};
    std::vector<int> B{1,2,3};
    dutch_flag(A,2);
    CHECK(A==B);
}


TEST(DutchFlag, CheckMore123)
{
    std::vector<int> A{1,1,1,1,2,2,2,2,2,3,3,3,3,3,3};
    std::vector<int> B{1,1,1,1,2,2,2,2,2,3,3,3,3,3,3};
    dutch_flag(A,2);
    CHECK(A==B);
}

TEST(DutchFlag, CheckMoreComplex123)
{
    std::vector<int> A{3,3,1,2,2,1,3,2,1,3,3,1,1,2,3};
    std::vector<int> B{1,1,1,1,1,2,2,2,2,3,3,3,3,3,3};
    dutch_flag(A,3);
    CHECK(A==B);
}



