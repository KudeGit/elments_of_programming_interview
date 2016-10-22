#include <iostream>
#include <list>
#include <sstream>
#include <limits>
#include "utils.hpp"

using namespace std;

struct Bucket {
    size_t start;
    size_t end;
    size_t value;
    Bucket (size_t s, size_t e, size_t v): 
        start(s), end(e), value(v) {}
    Bucket (Bucket&& other): 
        start(other.start), end(other.end), value(other.value) {}
};

ostream& operator<< (ostream& out, const Bucket& b) 
{
    out << "{" << b.start << ", "
               << b.end << ", "
               << b.value << "}";
    return out;
}



int main (void) 
{
    size_t num_ops = 0;
    size_t start = 0 , end = std::numeric_limits<size_t>::max(), value = 0;
    cin >> end >> num_ops;
    list<Bucket> b_list;
    size_t max_value = 0;
    b_list.emplace_back(start, end, value);
    debug(end);
    debug(num_ops);
    for (size_t i = 0; i < num_ops; ++i) {
        debug("##########################");
        cin >> start >> end >> value;
        debug(start);
        debug(end);
        debug(value);
        for (auto it = b_list.begin(); it != b_list.end(); ++it) {
            debug("----------------------------------------");
            debug((*it));

            if (it->start >= start && it->end <= end) {
                debug("A");
                it->value += value;
            }
            else if  (it->start < start && it->end > end){
                debug("B");
                size_t old_end = it->end;
                size_t old_value = it->value;
                it->end = start - 1;
                auto it_1 = next(it);
                b_list.emplace(it_1, start, end, value + old_value);
                ++it;
                it_1 = next(it);
                b_list.emplace(it_1, end+1, old_end, old_value);
                ++it;
            } else {
                if (start > it->start) {
                    debug("C");
                    size_t old_end = it->end; 
                    size_t old_value = it->start;
                    it->end = start - 1;
                    auto it_1 = next(it);
                    b_list.emplace(it_1, start, old_end, value + old_value);
                    ++it;
                }
                if(end < it->end) {
                    debug("D");
                    size_t old_end = it->end;
                    size_t old_value = it->value;
                    it->end = end;
                    it->value += value;
                    auto it_1 = next(it);
                    b_list.emplace(it_1, end+1, old_end, old_value);
                    ++it;
                } else {
                    debug("E");
                }
            }
            debug(b_list);
        }
    }
    for (const auto& b: b_list) {
        max_value = max(b.value, max_value);
    }

    cout << max_value << std::endl;
    return 0;
}
