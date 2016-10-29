#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch9.hpp"


TEST_GROUP(MaxStackGroup)
{

};


TEST(MaxStackGroup, StackEmpty)
{
    max_stack<int> s;
    CHECK(s.empty() == 1);
}

TEST(MaxStackGroup, StackPushingIncreasingEl)
{
    max_stack<int> s;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
        CHECK(s.top() == s.max());
    }
    try{
        while (!s.empty()) {
            CHECK(s.top() == s.max());
            s.pop();
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


TEST(MaxStackGroup, StackPushingDecreasingEl)
{
    max_stack<int> s;
    for (int i = 0; i < 10; ++i) {
        s.push(9 - i);
        CHECK(s.top() == 9-i);
        CHECK(s.max() == 9);
    }
    try{
        while (!s.empty()) {
            CHECK(9 == s.max());
            s.pop();
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
