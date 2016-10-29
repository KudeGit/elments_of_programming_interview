#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch8.hpp"
#include "list.hpp"
#include "../../utils.hpp"


TEST_GROUP(ReverseList)
{

};
TEST(ReverseList, EmptyList)
{
    List<int> l;
    reverse(l);
    CHECK(l.head == nullptr);
}
TEST(ReverseList, SingleElement)
{
    List<int> l;
    l.push_front(1);
    reverse(l);
    CHECK(l.head->data == 1);
}

TEST(ReverseList, TwoElements)
{
    List<int> l;
    l.push_front(2);
    l.push_front(1);
    reverse(l);
    auto x = l.head;
    CHECK(x->data == 2);
    x = x->next;
    CHECK(x->data == 1);
}


TEST(ReverseList, EvenElements)
{
    std::vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    List<int> l;
    for (const auto& a: A) {
        l.push_front(a);
    }
    reverse(l);
    auto x = l.head;
    for (const auto& a: A) {
        CHECK(x->data == a);
        x = x->next;
    }
    CHECK(x == nullptr);
}

TEST(ReverseList, OddElements)
{
    std::vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List<int> l;
    for (const auto& a: A) {
        l.push_front(a);
    }
    reverse(l);
    auto x = l.head;
    for (const auto& a: A) {
        CHECK(x->data == a);
        x = x->next;
    }
    CHECK(x == nullptr);
}
