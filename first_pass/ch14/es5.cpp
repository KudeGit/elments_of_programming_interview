#include <iostream>
#include <vector>
#include "../utils.hpp"

struct Event {
    int start;
    int finish;
};

struct Point {
    int time;
    bool is_start;
};

bool operator< (const Point& a, const Point& b)
{
    return a.time != b.time
        ? a.time < b.time 
        : a.is_start > b.is_start;
}


int max_parallel_events (const std::vector<Event> events)
{
    std::vector<Point> points;
    for (const auto& e: events) {
        points.emplace_back(Point{e.start, true});
        points.emplace_back(Point{e.finish, false});
    }
    std::sort(points.begin(), points.end());
    int current_parallel = 0;
    int max_parallel = 0;
    for (const auto& p: points) {
        if(p.is_start) {
            ++current_parallel;
            max_parallel = std::max(max_parallel, current_parallel);
        } else {
            --current_parallel;
        }
    }
    return max_parallel;
}

int main (void)
{
    std::vector<Event> events = {
        Event{1,5},
        Event{2,7},
        Event{4,5},
        Event{6,10},
        Event{8,9},
        Event{9,17},
        Event{11,13},
        Event{14,15},
        Event{12,15},
    };
    auto n = max_parallel_events(events);
    std::cout << n << std::endl;
    return 0;

}
