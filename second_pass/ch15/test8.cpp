
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "es8.hpp"


TEST_GROUP(PageRank)
{

};


TEST(PageRank, Empty)
{
    std::vector<std::string> urls = {};
    PageRank pr;
    for (const auto& url: urls) {
        pr.add(url);
    }
    CHECK(pr.common(10).empty() == true);
}

TEST(PageRank, SingleEntry)
{
    std::vector<std::string> urls = {"A"};
    PageRank pr;
    for (const auto& url: urls) {
        pr.add(url);
    }
    auto res = pr.common(10);
    CHECK(res.size() == 1);
    CHECK(res[0].count == 1);
    CHECK(res[0].url == "A");
}

TEST(PageRank, SingleEntryRepeated)
{
    std::vector<std::string> urls(100, "A");
    PageRank pr;
    for (const auto& url: urls) {
        pr.add(url);
    }
    auto res = pr.common(10);
    CHECK(res.size() == 1);
    CHECK(res[0].count == 100);
    CHECK(res[0].url == "A");
}

TEST(PageRank, SingleTwoEntryRepeated)
{
    std::vector<std::string> urls{
        "A",
        "A",
        "A",
        "A",
        "A",
        "A",
        "A",
        "B",
        "B",
        "B",
        "B",
        "B"};
    PageRank pr;
    for (const auto& url: urls) {
        pr.add(url);
    }
    auto res = pr.common(10);
    CHECK(res.size() == 2);
    CHECK(res[0].count == 7);
    CHECK(res[0].url == "A");
    CHECK(res[1].count == 5);
    CHECK(res[1].url == "B");
}




