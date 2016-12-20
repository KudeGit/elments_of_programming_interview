#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <cassert>
#include "../../utils.hpp"

using namespace std;

struct Point {
    int x;
    int y;
    bool is_start;
};

ostream& operator<< (ostream& out, const Point& p)
{
    out << "("<< p.x << ", " << p.y << ", " << p.is_start <<")";
    return out;
}

vector<pair<int, int>> getSkyline(const vector<vector<int>>& B)
{
    if (B.empty()) {
        return {};
    }
    vector<Point> P;
    for (auto& b: B) {
        P.emplace_back(Point{b[0], b[2], true});
        P.emplace_back(Point{b[1], b[2], false});
    }
    auto cmp_points = [](const Point& lhs, const Point& rhs) {
        if (lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        }
        if (lhs.y != rhs.y) {
            if(lhs.is_start == true && rhs.is_start == true) {
                return lhs.y > rhs.y;
            } else if (lhs.is_start == false && rhs.is_start == false) {
                return lhs.y < rhs.y;
            }
        }
        return true;
    };
    sort(P.begin(), P.end(), cmp_points);
    map<int, long> heights;
    heights[0] = std::numeric_limits<int>::max();
    vector<pair<int, int>> skyline;

    skyline.emplace_back(make_pair(P[0].x, P[0].y));
    heights[P[0].y] = 1;
    for (int i = 1; i < P.size(); ++i) {
        auto curr_p = P[i];
        if (curr_p.is_start) {
            auto it = heights.find(curr_p.y);
            if (it == heights.end()) {
                heights[curr_p.y] = 1;
            } else {
                ++it->second;
            }
            auto max_h = heights.crbegin()->first;

            //debug(curr_p.x);
            //debug(max_h);
            //debug(skyline.back().second);

            if (max_h > skyline.back().second) {
                skyline.emplace_back(make_pair(curr_p.x, max_h));
            }
            //debug(skyline.back());
        } else {
            auto it = heights.find(P[i].y);
            if (it == heights.end()) {
                throw logic_error("End point with heigh not seen before!!!");
            }
            if (--(it->second) == 0) {
                heights.erase(it);
            }
            auto max_h = heights.crbegin()->first;

            //debug(curr_p.x);
            //debug(max_h);
            //debug(skyline.back().second);

            if (max_h < skyline.back().second) {
                skyline.emplace_back(make_pair(curr_p.x, max_h));
            }
            //debug(skyline.back());
        }
    }

    //debug(skyline);
    return skyline;
}


void check_result (const std::vector<pair<int, int>> res,
        const std::vector<pair<int, int>> expected)
{
    assert (res.size() == expected.size());
    for (int i = 0; i < res.size(); ++i) {
        assert(res[i].first == expected[i].first);
        assert(res[i].second == expected[i].second);
    }
}

void test (void)
{
    auto res1 = getSkyline({ {2, 9, 10},
            {3, 7, 15},
            {5, 12, 12},
            {15, 20, 10},
            {19, 24, 8} });
    std::vector<pair<int, int>> expected1 {
        {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}
    };
    check_result(res1, expected1);


    auto res2 = getSkyline({
             {1, 100, 100},
             {10, 20, 10},
            });
    std::vector<pair<int, int>> expected2{{1, 100}, {100, 0}};
    check_result(res2, expected2);


    auto res3 = getSkyline({
            {1, 10, 10}, {1, 5, 6}
            });
    std::vector<pair<int, int>> expected3{{1, 10}, {10, 0}};
    check_result(res3, expected3);

    auto res4 = getSkyline({
            {1, 10, 10}, {5, 10, 6}
            });
    std::vector<pair<int, int>> expected4{{1, 10}, {10, 0}};
    check_result(res4, expected4);
    return;
}

int main (void)
{
    test();

    return 0;
}
