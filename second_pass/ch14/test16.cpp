#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch14.hpp"


TEST_GROUP(ApplyPermutation)
{
};


TEST(ApplyPermutation, Simple1)
{
    std::vector<char> A{'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<int> P{3, 5, 2, 1, 0, 4};
    std::vector<int> PP(P);
    apply_permutation(A,P);
    int i= 0;
    for (const auto& p: P) {
        CHECK(p == PP[i++]);
    }
    CHECK(A[0] == 'E');
    CHECK(A[1] == 'D');
    CHECK(A[2] == 'C');
    CHECK(A[3] == 'A');
    CHECK(A[4] == 'F');
    CHECK(A[5] == 'B');

}

TEST_GROUP(SortStatues){};
TEST(SortStatues, Simple1)
{
    std::vector<int> A{0,1,2,3};
    
    sort_min_distance(A);
    CHECK(A.size() == 4);
    for(int i = 0; i < A.size(); ++i) {
        CHECK(A[i] == i);
    }
}
