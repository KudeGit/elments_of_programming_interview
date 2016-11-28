#include <iostream>
#include <vector>
#include <utility>
#include "es5.hpp"

int max_concurrent_events (const std::vector<Event>& events)
{
    struct TimePoint {
        enum class Type{START, FINISH};
        std::size_t time;
        Type type;

    };

    std::vector<TimePoint> time_points;
    for (const auto& event: events) {
        time_points.emplace_back(TimePoint{event.first, TimePoint::Type::START});
        time_points.emplace_back(TimePoint{event.second, TimePoint::Type::FINISH});
    }
    std::sort(time_points.begin(), time_points.end(),
                [](const TimePoint& lhs, const TimePoint& rhs) {
                    return lhs.time < rhs.time;
                    });
    auto n_concurrent_events = 0;
    auto max_n_concurrent_events = n_concurrent_events;
    for (const auto& tp: time_points) {
        n_concurrent_events += tp.type == TimePoint::Type::START ? 1 : -1;
        max_n_concurrent_events = std::max(max_n_concurrent_events, n_concurrent_events);
    }
    return max_n_concurrent_events;
}
