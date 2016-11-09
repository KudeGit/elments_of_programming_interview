#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch11.hpp"


TEST_GROUP(StockFile)
{
};

TEST (StockFile, StockConstructor)
{
    std::string line("12345,AAPL,30,456.12");
    stock_entry s(line, nullptr);
    CHECK(s.time_of_day == 12345);
    CHECK(s.company_name == "AAPL");
    CHECK(s.n_shares == 30);
    CHECK(s.price == 456.12);
}

TEST(StockFile, SingleFile)
{
    std::vector<std::string> inputs{"test_apple"};
    sort_stocks_files(inputs, "test_apple_out");
    CHECK(0 == 1);
}

