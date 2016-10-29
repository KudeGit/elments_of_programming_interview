#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch9.hpp"
TEST_GROUP (RPNTransform)
{
};
TEST(RPNTransform, EmptyString)
{
    std::vector<std::string> strs;
    auto rpn_str = transform_to_rpn(strs);
    CHECK(rpn_str == "");
}

TEST(RPNTransform, SimpleEx)
{
    std::vector<std::string> strs{"(", "5", "+", "3", ")", "*", "12", "/", "3"};
    auto rpn_str = transform_to_rpn(strs);
    CHECK(rpn_str == "5,3,+,12,*,3,/");
}
TEST(RPNTransform, SimpleEx2)
{
    std::vector<std::string> strs{"(", "5", "+", "3", ")", "*", "12", "/", "3", "^", "2"};
    auto rpn_str = transform_to_rpn(strs);
    CHECK(rpn_str == "5,3,+,12,*,3,2,^,/");
}

TEST_GROUP(RPNEvalutation)
{

};


TEST(RPNEvalutation, RPN1)
{
    auto str{"3,4,*,1,2,+,+"};
    auto res = evalute_rpn(str);
    CHECK(res == 15);
}

TEST(RPNEvalutation, RPN2)
{
    auto str{"4,6,/,2,/"};
    auto res = evalute_rpn(str);
    CHECK(res == 0);
}
