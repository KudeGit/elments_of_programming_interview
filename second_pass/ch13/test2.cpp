
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(IsPalindromicPerm)
{

};


TEST(IsPalindromicPerm, Empty)
{
    auto res = is_palindrome_permutation("");
    CHECK(res == true);
}


TEST(IsPalindromicPerm, SimplePalidrome)
{
    auto res = is_palindrome_permutation("aaaa");
    CHECK(res == true);
}

TEST(IsPalindromicPerm, SimplePalidrome1)
{
    auto res = is_palindrome_permutation("aapaa");
    CHECK(res == true);
}

TEST(IsPalindromicPerm, SimplePalidrome3)
{
    auto res = is_palindrome_permutation("edified");
    CHECK(res == true);
}

TEST(IsPalindromicPerm, SimpleNotPalidrome) 
{
    auto res = is_palindrome_permutation("abcd");
    CHECK(res == false);
}

TEST(IsPalindromicPerm, SimpleNotPalidrome2) 
{
    auto res = is_palindrome_permutation("abcdabef");
    CHECK(res == false);
}
