#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch7.hpp"
#include <string>
#include <unordered_map>


TEST_GROUP(ReplaceAndRemoveGroup)
{

};

std::unordered_map<char, std::string> rules = {
    {'a', "dd"},
    {'c', "b"},
    {'b', ""},
};

TEST(ReplaceAndRemoveGroup, EmptyString)
{
    std::string s("");
    replace_and_remove(s, rules);
    CHECK(s == s);
}

TEST(ReplaceAndRemoveGroup, NotToEncodeString)
{
    std::string s("ffgffhfhh");
    replace_and_remove(s, rules);
    CHECK(s == s);
}

TEST(ReplaceAndRemoveGroup, ASimpleString)
{
    std::string s1("a");
    std::string s2("aa");
    std::string s3("aaa");
    replace_and_remove(s1, rules);
    CHECK(s1 == "dd");
    replace_and_remove(s2, rules);
    CHECK(s2 == "dddd");
    replace_and_remove(s3, rules);
    CHECK(s3 == "dddddd");
}

TEST(ReplaceAndRemoveGroup, BSimpleString)
{
    std::string s1("b");
    std::string s2("b");
    std::string s3("b");
    replace_and_remove(s1, rules);
    replace_and_remove(s2, rules);
    replace_and_remove(s3, rules);
    CHECK(s1 == "");
    CHECK(s2 == "");
    CHECK(s3 == "");
}

TEST(ReplaceAndRemoveGroup, CSimpleString)
{
    std::string s1("c");
    std::string s2("cc");
    std::string s3("ccc");
    replace_and_remove(s1, rules);
    replace_and_remove(s2, rules);
    replace_and_remove(s3, rules);
    CHECK(s1 == "b");
    CHECK(s2 == "bb");
    CHECK(s3 == "bbb");
}

TEST(ReplaceAndRemoveGroup, MoreComplexString)
{
    std::string s1("cba");
    replace_and_remove(s1, rules);
    CHECK(s1 == "bdd");

    std::string s2("cbfa");
    replace_and_remove(s2, rules);
    CHECK(s2 == "bfdd");

    std::string s3("cbfab");
    replace_and_remove(s3, rules);
    CHECK(s3 == "bfdd");
}


