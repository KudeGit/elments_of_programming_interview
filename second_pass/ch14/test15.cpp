#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(CompletionSearch)
{
};


TEST(CompletionSearch, Simple1)
{
    std::vector<std::string> A{"A", "B", "C", "AA"};
    const std::string ifilename("itest.txt");
    const std::string ofilename("itest.txt");
    std::ofstream input_test_file(ifilename);
    if (!input_test_file.good()) {
        CHECK(0 == 1);
    }
    for (const auto& a: A) {
        input_test_file << a << std::endl;
    }
    input_test_file.close();
    std::sort(A.begin(), A.end());
    indirect_sort(ifilename, ofilename);
    std::vector<std::string> res;
    std::ifstream output_test_file(ofilename);
    if (!output_test_file.good()) {
        CHECK(0 == 1);
    }
    std::string line;
    while (getline(output_test_file,line)) {
        res.emplace_back(line);
    }
    CHECK(res.size() == A.size());
    for (int i = 0; i < res.size(); ++i) {
        CHECK(res[i] == A[i]);
    }

}
