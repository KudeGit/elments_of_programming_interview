#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch8.hpp"
#include "list.hpp"
#include "../../utils.hpp"


TEST_GROUP(LinkedListGroup)
{

};


TEST(LinkedListGroup, MergeEmptyList)
{
    List<int> l1;
    List<int> l2;
    auto l3 = merge_sorted_list(l1, l2);
    CHECK(l3.head == nullptr);
}

TEST(LinkedListGroup, L2iSEmptyList)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l1.push_front(i);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 10; ++i) {
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}

TEST(LinkedListGroup, L1iSEmptyList)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l2.push_front(i);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 10; ++i) {
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}

TEST(LinkedListGroup, L1SmallerL2)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l1.push_front(i);
        l2.push_front(i+10);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 20; ++i) {
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}

TEST(LinkedListGroup, L2SmallerL1)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l2.push_front(i);
        l1.push_front(i+10);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 20; ++i) {
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}

TEST(LinkedListGroup, L2EqualL1)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l2.push_front(i);
        l1.push_front(i);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 10; ++i) {
        CHECK(x->data == i);
        x = x->next;
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}
TEST(LinkedListGroup, L2InterleaveL1)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 19; i >= 0; --i) {
        if (i & 0x1) {
            l2.push_front(i);
        } else {
            l1.push_front(i);
        }
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 20; ++i) {
        CHECK(x->data == i);
        x = x->next;
    }
    CHECK(x == nullptr);
}
TEST(LinkedListGroup, AllEqual)
{
    List<int> l1;
    List<int> l2;
    for (auto i = 9; i >= 0; --i) {
        l1.push_front(0);
        l2.push_front(0);
    }
    auto l3 = merge_sorted_list(l1, l2);
    auto x = l3.head;
    for (auto i = 0; i < 20; ++i) {
        CHECK(x->data == 0);
        x = x->next;
    }
    CHECK(x == nullptr);
}

