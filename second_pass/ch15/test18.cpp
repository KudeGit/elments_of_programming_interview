#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch15.hpp"


TEST_GROUP(TreePredecessorGroup)
{

};


TEST(TreePredecessorGroup, Empty)
{
    auto root = std::unique_ptr<BSTNode<int>>(nullptr);
    auto pred1 = find_predecessor(root.get(), 8);
    auto pred2 = find_predecessor_rec(root.get(), 8);
    CHECK(pred1 == nullptr);
    CHECK(pred2 == nullptr);
}

TEST(TreePredecessorGroup, Simple1)
{
    std::vector<int> A{0,1,2,3,4,5,6};
    auto root = rebuild_from_sorted_vector(A);
    auto pred1 = find_predecessor(root.get(), A[0]);
    auto pred2 = find_predecessor_rec(root.get(), A[0]);
    CHECK(pred1 == nullptr);
    CHECK(pred2 == nullptr);
    for (int i = 1; i < A.size(); ++i) {
        auto pred1 = find_predecessor(root.get(), A[i]);
        auto pred2 = find_predecessor_rec(root.get(), A[i]);
        CHECK(pred1 == pred2);
        CHECK(pred1->val == A[i-1]);
    }
}


TEST_GROUP(TreeSuccessorGroup)
{

};


TEST(TreeSuccessorGroup, Empty)
{
    auto root = std::unique_ptr<BSTNode<int>>(nullptr);
    auto pred1 = find_successor(root.get(), 8);
    auto pred2 = find_successor_rec(root.get(), 8);
    CHECK(pred1 == nullptr);
    CHECK(pred2 == nullptr);
}

TEST(TreeSuccessorGroup, Simple1)
{
    std::vector<int> A{0,1,2,3,4,5,6};
    auto root = rebuild_from_sorted_vector(A);
    auto pred1 = find_successor(root.get(), A.back());
    auto pred2 = find_successor_rec(root.get(), A.back());
    CHECK(pred1 == nullptr);
    CHECK(pred2 == nullptr);
    for (int i = 0; i < A.size() - 1; ++i) {
        auto pred1 = find_successor(root.get(), A[i]);
        auto pred2 = find_successor_rec(root.get(), A[i]);
        CHECK(pred1 == pred2);
        CHECK(pred1->val == A[i+1]);
    }
}

TEST_GROUP(TreeNodeInRangeGroup)
{

};


TEST(TreeNodeInRangeGroup, Empty)
{
    auto root = std::unique_ptr<BSTNode<int>>(nullptr);
    auto res = find_nodes_in_range(root.get(), 8, 10);
    CHECK(res.size() == 0);
}

TEST(TreeNodeInRangeGroup, Simple1)
{
    std::vector<int> A{0,1,2,3,4,5,6};
    auto root = rebuild_from_sorted_vector(A);
    auto res = find_nodes_in_range(root.get(), -1, 7);
    CHECK(res.size() == A.size());
    for (int i = 0; i < A.size(); ++i) {
        CHECK(res[i]->val == A[i]);
    }
}

TEST(TreeNodeInRangeGroup, Simple2)
{
    std::vector<int> A{0,1,2,3,4,5,6};
    auto root = rebuild_from_sorted_vector(A);
    auto res = find_nodes_in_range(root.get(), 0, 6);
    CHECK(res.size() == A.size()-2);
    for (int i = 1, j = 0; i < A.size()-1 && j < res.size(); ++i, ++j) {
        CHECK(res[j]->val == A[i]);
    }
}
