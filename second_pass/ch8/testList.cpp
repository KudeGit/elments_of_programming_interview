#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "ch8.hpp"
#include "list.hpp"


TEST_GROUP(LinkedListGroup)
{};


TEST(LinkedListGroup, Empty0)
{
    ListNode<int> ln;
    ListNode<int> ln1(10);
    CHECK(ln.data == 0);
    CHECK(ln1.data == 10);
}
TEST(LinkedListGroup, insertInFront)
{
    List<int> l;
    std::vector<int> A{1,2,3,4,5,6,7,8,9,0};
    for (const auto& a: A) {
        l.push_front(a);
    }
    auto ln = l.head;

    for (auto it = A.crbegin(); it != A.crend(); ++it) {
        CHECK(ln->data == *it);
        ln = ln->next;
    }
    CHECK(ln == nullptr);
}

