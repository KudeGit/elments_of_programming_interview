#include <iostream>
#include <unordered_set>
#include <vector>
#include "../utils.hpp"

struct Jug {
    int min;
    int max;
};
std::ostream& operator<< (std::ostream& out, 
        const Jug& j) {
    out << "(" << j.min << ", " << j.max << ")";
    return out;
}



struct HashPair {
    size_t operator() (const std::pair<int, int>& a) const {
        return std::hash<int>()(a.first ^ a.second);
    }
};


struct PairEqual {
    bool operator() (const std::pair<int, int>& a, 
            const std::pair<int, int>& b) const {
        return a.first == b.first && a.second == b.second;
    }
};

std::vector<Jug> is_feasible_helper (int min, int max,
        const std::vector<Jug>& jugs,
        std::vector<Jug> current,
        std::unordered_set<std::pair<int,int>, HashPair, PairEqual>& cache)
{
    if (min > max || cache.find({min, max}) != cache.end() ) {
        return {};
    }
    if (min < 0 && max < 0) {
        return {};
    }
    for (const auto& j: jugs) {
        if (min <= j.min && j.max <= max) {
            current.emplace_back(j);
            return current;
        } else {
            current.emplace_back(j);
            auto res = is_feasible_helper(min - j.min,
                    max - j.max, jugs, current, cache);
            if (!res.empty()) {
                return res;
            }
            current.pop_back();
        }
    }
    cache.insert(std::pair<int,int>(min, max));
    return {};

}

std::vector<Jug> is_feasible (int min, int max,
        const std::vector<Jug>& jugs) 
{
    std::vector<Jug> current;
    std::unordered_set<std::pair<int,int>, HashPair, PairEqual> cache;
    return is_feasible_helper(min, max, jugs, current, cache);
}



int main (void)
{
    const std::vector<Jug> jugs = {
        Jug{230, 240},
        Jug{290, 310},
        Jug{500, 515}};
    auto res = is_feasible(2100, 2300, jugs);
    std::cout << "res: " << res << std::endl;
    return 0;
}
