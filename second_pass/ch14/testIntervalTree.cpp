
#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "interval_tree.hpp"


TEST_GROUP(IntervalTreeNode)
{

};


TEST(IntervalTreeNode, Empty)
{
    Event* e = new Event{0,1};
    std::shared_ptr<Event> ep(e);
    std::vector<IntervalTreeNode> itns;
    itns.emplace_back(IntervalTreeNode{std::make_shared<Event>(0,1), 0, nullptr, nullptr});
    itns.emplace_back(IntervalTreeNode{ep, 0, nullptr, nullptr});
}





TEST_GROUP(IntervalTree) {};
TEST(IntervalTree, Empty)
{
    IntervalTree it;
}
//example from: http://www.geeksforgeeks.org/interval-tree/
TEST(IntervalTree, insert)
{
    IntervalTree it;
    it.insert(std::make_shared<Event>(15,20));

    it.insert(std::make_shared<Event>(10,30));
    it.insert(std::make_shared<Event>(17,19));

    it.insert(std::make_shared<Event>(5,20));
    it.insert(std::make_shared<Event>(12,15));
    it.insert(std::make_shared<Event>(30,40));

    std::vector<const IntervalTreeNode*> in_order_visit;
    it.visit([&in_order_visit](const IntervalTreeNode* n){in_order_visit.emplace_back(n);});
    CHECK(in_order_visit.size() == 6);

    CHECK(in_order_visit[0]->e->first == 5);
    CHECK(in_order_visit[0]->e->second == 20);
    CHECK(in_order_visit[0]->max_end_time == 20);

    CHECK(in_order_visit[1]->e->first == 10);
    CHECK(in_order_visit[1]->e->second == 30);
    CHECK(in_order_visit[1]->max_end_time == 30);

    CHECK(in_order_visit[2]->e->first == 12);
    CHECK(in_order_visit[2]->e->second == 15);
    CHECK(in_order_visit[2]->max_end_time == 15);

    CHECK(in_order_visit[3]->e->first == 15);
    CHECK(in_order_visit[3]->e->second == 20);
    CHECK(in_order_visit[3]->max_end_time == 40);

    CHECK(in_order_visit[4]->e->first == 17);
    CHECK(in_order_visit[4]->e->second == 19);
    CHECK(in_order_visit[4]->max_end_time == 40);

    CHECK(in_order_visit[5]->e->first == 30);
    CHECK(in_order_visit[5]->e->second == 40);
    CHECK(in_order_visit[5]->max_end_time == 40);
}

//http://www.davismol.net/2016/02/07/data-structures-augmented-interval-tree-to-search-for-interval-overlapping/
TEST(IntervalTree, insert2)
{
    IntervalTree it;
    it.insert(std::make_shared<Event>(5,10));
    it.insert(std::make_shared<Event>(1,12));
    it.insert(std::make_shared<Event>(2,8));
    it.insert(std::make_shared<Event>(15,25));
    it.insert(std::make_shared<Event>(8,16));
    it.insert(std::make_shared<Event>(18,21));
    it.insert(std::make_shared<Event>(14,20));

    std::vector<const IntervalTreeNode*> in_order_visit;
    it.visit([&in_order_visit](const IntervalTreeNode* n){in_order_visit.emplace_back(n);});
    CHECK(in_order_visit.size() == 7);



    CHECK(in_order_visit[0]->e->first == 1);
    CHECK(in_order_visit[0]->e->second == 12);
    CHECK(in_order_visit[0]->max_end_time == 12);

    CHECK(in_order_visit[1]->e->first == 2);
    CHECK(in_order_visit[1]->e->second == 8);
    CHECK(in_order_visit[1]->max_end_time == 8);

    CHECK(in_order_visit[2]->e->first == 5);
    CHECK(in_order_visit[2]->e->second == 10);
    CHECK(in_order_visit[2]->max_end_time == 25);

    CHECK(in_order_visit[3]->e->first == 8);
    CHECK(in_order_visit[3]->e->second == 16);
    CHECK(in_order_visit[3]->max_end_time == 20);

    CHECK(in_order_visit[4]->e->first == 14);
    CHECK(in_order_visit[4]->e->second == 20);
    CHECK(in_order_visit[4]->max_end_time == 20);

    CHECK(in_order_visit[5]->e->first == 15);
    CHECK(in_order_visit[5]->e->second == 25);
    CHECK(in_order_visit[5]->max_end_time == 25);


    CHECK(in_order_visit[6]->e->first == 18);
    CHECK(in_order_visit[6]->e->second == 21);
    CHECK(in_order_visit[6]->max_end_time == 21);
}


TEST(IntervalTreeNode, query1)
{
    IntervalTree it;
    it.insert(std::make_shared<Event>(5,10));
    it.insert(std::make_shared<Event>(1,12));
    it.insert(std::make_shared<Event>(2,8));
    it.insert(std::make_shared<Event>(15,25));
    it.insert(std::make_shared<Event>(8,16));
    it.insert(std::make_shared<Event>(18,21));
    it.insert(std::make_shared<Event>(14,20));

    std::vector<Event> intersects;
    auto u = [&intersects](const Event e){intersects.emplace_back(e);};
    it.search(Event{8,10}, u);
    CHECK(intersects.size() == 4);

    CHECK(intersects[0].first == 5);
    CHECK(intersects[0].second == 10);

    CHECK(intersects[1].first == 1);
    CHECK(intersects[1].second == 12);

    CHECK(intersects[2].first == 2);
    CHECK(intersects[2].second == 8);

    CHECK(intersects[3].first == 8);
    CHECK(intersects[3].second == 16);

    intersects.clear();
    it.search(Event{20,22}, u);
    CHECK(intersects.size() == 3)


    CHECK(intersects[0].first == 15);
    CHECK(intersects[0].second == 25);

    CHECK(intersects[1].first == 14);
    CHECK(intersects[1].second == 20);

    CHECK(intersects[2].first == 18);
    CHECK(intersects[2].second == 21);

}

