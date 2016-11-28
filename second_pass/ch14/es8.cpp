#include <iostream>
#include <vector>
#include <set>
#include "ch14.hpp"
#include "../../utils.hpp"


std::vector<int> minimum_covering (const std::vector<Event> events)
{
    auto sort_by_end_time = [](const Event& a, const Event& b) {
                                return a.second != b.second ? 
                                    a.second < b.second : a.first < b.first;
                            };
    auto sort_by_start_time = [] (const Event& a, const Event& b) {
                                return a.first != b.first ?
                                    a.first < b.first :
                                    a.second < b.second;
                            };
    std::set<Event, decltype(sort_by_end_time)> end_time_set{events.begin(),
                                                            events.end(),
                                                            sort_by_end_time};
    std::set<Event, decltype(sort_by_start_time)> start_time_set{events.begin(),
                                                            events.end(),
                                                            sort_by_start_time};

    std::vector<int> res;
    while (!end_time_set.empty() && !start_time_set.empty()) {
        res.emplace_back(end_time_set.begin()->second);
        auto it = start_time_set.begin();
        while (!start_time_set.empty() && it->first < res.back()) {
            end_time_set.erase(*it);
            start_time_set.erase(it++);
        }
    }
    return res;

}

std::vector<int> minimum_covering2 (const std::vector<Event> events)
{
    auto sort_by_end_time = [](const Event& lhs, const Event& rhs) {
                                return lhs.second != rhs.second ? 
                                    lhs.second < rhs.second : 
                                    lhs.first < rhs.first;
                             };
    std::set<Event,decltype(sort_by_end_time)> time_set(events.begin(),
            events.end(), sort_by_end_time);
    std::vector<int> res{};
    while (!time_set.empty()) {
        auto candidate = time_set.begin();
        res.emplace_back(candidate->second);
        while (!time_set.empty() && time_set.begin()->first <= res.back()) {
            time_set.erase(time_set.begin());
        }
    }
    return res;
}
