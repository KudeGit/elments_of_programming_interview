#include <iostream>
#include <vector>
#include "../utils.hpp"


struct Interrval {
    int start;
    int end;
};

std::ostream& operator<< (std::ostream& out,
        const Interrval& i)
{
    out << "(" << i.start << "," << i.end << ")";
    return out;
}


std::vector<Interrval> find_union (
        std::vector<Interrval> intervals)
{
    std::sort(intervals.begin(), intervals.end(), 
            [](const Interrval& a, const Interrval& b) {
            return a.start < b.start;
            });
    std::vector<Interrval> res;
    for (int i = 0; i < intervals.size(); ++i) {
        int current_start = intervals[i].start;
        int current_end = intervals[i].end;
        while (i < intervals.size() - 1 &&
                current_end >= intervals[i+1].start) {
            current_end = std::max(intervals[i + 1].end, current_end);
            ++i;
        }
        res.emplace_back(Interrval{current_start, current_end});
    }
    return res;
}

int main (void)
{
    std::vector<Interrval> intervals = {
        Interrval{0,3},
        Interrval{1,1},
        Interrval{3,4},
        Interrval{2,4},
        Interrval{5,7},
        Interrval{7,8},
        Interrval{8,11},
        Interrval{12,14},
        Interrval{12,15},
        Interrval{13,13},
        Interrval{16,17},
    };

    auto res = find_union(intervals);
    std::cout << res << std::endl;

    return 0;
}
