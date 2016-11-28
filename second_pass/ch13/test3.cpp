#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(IsConstructible)
{
};


TEST(IsConstructible, Empty)
{
    std::stringstream iss_magazine("Ciao come va?");
    std::stringstream iss_letter("Mi chiamo pippo.");
    auto res = is_constructible(iss_letter, iss_magazine);
    CHECK(res == false);

}

